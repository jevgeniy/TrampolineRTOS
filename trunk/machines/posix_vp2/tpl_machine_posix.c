/*
 * Trampoline OS
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline posix machine dependent stuffs
 *
 */

#include "tpl_machine.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_internal_types.h"
/*#include "tpl_viper_interface.h"*/
#include "tpl_os_it_kernel.h"
#include "tpl_os.h"
#include "tpl_machine_interface.h"
#include "tpl_os_application_def.h" /* define NO_ISR if needed. */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h" /* for tpl_running_obj */
#include "tpl_as_definitions.h"
#include "tpl_os_task_kernel.h"
#endif /* WITH_AUTOSAR */

#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

extern volatile u32 tpl_locking_depth;

extern tpl_it_vector_entry tpl_it_vector[];
ipc_t viper;
global_ipc_t global_shared_memory;

VAR(tpl_stack_word, OS_VAR) idle_stack_zone[32768/sizeof(tpl_stack_word)] = {0} ;
VAR(struct TPL_STACK, OS_VAR) idle_task_stack = { idle_stack_zone, 32768} ;
VAR(struct TPL_CONTEXT, OS_VAR) idle_task_context;

extern VAR(tpl_bool, OS_VAR) tpl_user_task_lock;
extern VAR(u32, OS_VAR) tpl_cpt_os_task_lock;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
VAR(static struct timeval, OS_VAR) startup_time;
#endif

/*
 * The signal set corresponding to the enabled interrupts
 */
VAR(sigset_t, OS_VAR) signal_set_all;
VAR(sigset_t, OS_VAR) signal_set_cat1and2;
VAR(sigset_t, OS_VAR) signal_set_cat2;

/*
 * quit is used to shut down trampoline when
 * SIGINT or SIGHUP is raised
 */
void quit(int n)
{
    ShutdownOS(E_OK);  
}

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

FUNC(void, OS_CODE) tpl_watchdog_callback(void)
{
}

static struct timeval startup_time;

tpl_time tpl_get_local_current_date ()
{
    struct timeval time;
    tpl_time result;
  
    gettimeofday (&time, NULL);
    result = ((time.tv_sec - startup_time.tv_sec) % 2000) * (1000 * 1000) + 
        (time.tv_usec - startup_time.tv_usec);
  
    return result;
}

void tpl_set_watchdog (tpl_time delay)
{
    struct itimerval timer;
  
    /* configure and start the timer */
    timer.it_value.tv_sec = delay / (1000 * 1000);
    timer.it_value.tv_usec = delay % (1000 * 1000);
    timer.it_interval.tv_sec = delay / (1000 * 1000);
    timer.it_interval.tv_usec = delay % (1000 * 1000);
    setitimer (ITIMER_REAL, &timer, NULL);
}

void tpl_cancel_watchdog(void)
{
    struct itimerval timer;
  
    /* disable the timer */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer (ITIMER_REAL, &timer, NULL);
}
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

#ifdef WITH_AUTOSAR_STACK_MONITORING
FUNC(tpl_bool, OS_CODE) tpl_check_stack_pointer(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    return 1;
}

tpl_bool tpl_check_stack_footprint(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    return 1;
}
#endif /* WITH_AUTOSAR_STACK_MONITORING */

/** fonction that calls the system function tpl_counter_tick() 
 * for each counter declared in the application.
 * tpl_call_counter_tick() is application dependant and is 
 * generated by the OIL compiler (goil).
 */
/*void tpl_call_counter_tick();*/

/**
 * Enable all interrupts
 */
void tpl_enable_interrupts(void)
{
    if ( -1 == sigprocmask(SIG_UNBLOCK, &signal_set_all, NULL) )
    {
        perror("tpl_enable_interrupt failed");
        exit(-1);
    }
}

/**
 * Disable all interrupts
 */
void tpl_disable_interrupts(void)
{
    if ( -1 == sigprocmask(SIG_BLOCK, &signal_set_all, NULL) )
    {
        perror("tpl_disable_interrupts failed");
        exit(-1);
    }
}

/*
 * The signal handler used when interrupts are enabled
 */
void tpl_signal_handler(int sig)
{
    u32 requested_it, channel_id;
	
    /* */
    tpl_locking_depth++;
    tpl_cpt_os_task_lock++;

    /* Get the interrupt id from shared memory through vp_ipc API */
    requested_it = vp_ipc_get_interruption_id(&viper);
    
    channel_id = 31; /* TODO : change magic number */
    while(requested_it != 0)
    {
        if(requested_it & 0x80000000)
        {
            /* If the interrupt id is valid, call the registred function */
            if( (TPL_IT_VECTOR_INDEX_OFFSET <= channel_id) &&
                (channel_id < (TPL_IT_VECTOR_INDEX_OFFSET + TPL_IT_VECTOR_SIZE)))
            {
                channel_id = channel_id - TPL_IT_VECTOR_INDEX_OFFSET;
                tpl_it_vector[channel_id].func(tpl_it_vector[channel_id].args);
            }
            else
            {
                /* Unknown interrupt request: invoke the balrog */
                printf("No ISR is registered for signal %d\n", sig);
                printf("Cowardly exiting!\n");
                tpl_shutdown();
            }
        }
        channel_id --;
        requested_it <<= 1;
    }
    tpl_locking_depth--;
    tpl_cpt_os_task_lock--;
}

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1) pause();
}

void tpl_shutdown(void)
{
	/* remove ITs */
	if (sigprocmask(SIG_BLOCK,&signal_set_all,NULL) == -1)
    {
        perror("tpl_shutdown failed");
        exit(-1);
    }
    exit(0);
}

/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
    /*
     * block the handling of signals
     */
    if(0 == tpl_locking_depth) {
        if (sigprocmask(SIG_BLOCK,&signal_set_all,NULL) == -1)
        {
            perror("tpl_get_lock failed");
            exit(-1);
        }
    }
    tpl_locking_depth++;

#ifdef WITH_AUTOSAR
    tpl_cpt_os_task_lock++;
#endif
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
void tpl_release_task_lock(void)
{
	assert( tpl_locking_depth > 0 );
	tpl_locking_depth--;
	
#ifdef WITH_AUTOSAR
    tpl_cpt_os_task_lock--;
#endif

    if ( (tpl_locking_depth == 0) && (FALSE == tpl_user_task_lock) )
    {
        if (sigprocmask(SIG_UNBLOCK,&signal_set_all,NULL) == -1) {
            perror("tpl_release_lock failed");
            exit(-1);
        }
    }
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_switch_context(
    CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) old_context,
    CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) new_context)
{
    if( NULL == old_context)
    {
        _longjmp((*new_context)->current, 1);
    }
    else if ( 0 == _setjmp((*old_context)->current) ) 
    {
        _longjmp((*new_context)->current, 1);
    }
    return;
}


FUNC(void, OS_CODE) tpl_switch_context_from_it(
    CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) old_context,
    CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) new_context)
{
    if( NULL == old_context )
    {
        _longjmp((*new_context)->current, 1);
    }
    else if ( 0 == _setjmp((*old_context)->current) ) 
    {
        _longjmp((*new_context)->current, 1);
    }
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_init_context(
        CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
    memcpy( tpl_stat_proc_table[proc_id]->context->current,
            tpl_stat_proc_table[proc_id]->context->initial,
            sizeof(jmp_buf));
}

void tpl_osek_func_stub( tpl_proc_id task_id )
{
    tpl_proc_function func = tpl_stat_proc_table[task_id]->entry;
    tpl_proc_type     type = tpl_stat_proc_table[task_id]->type;
  
    /* Avoid signal blocking due to a previous call to tpl_init_context in a OS_ISR2 context. */
	tpl_release_task_lock();
    
    (*func)();
    
    if (type == IS_ROUTINE) {
	#ifdef WITH_AUTOSAR	
	    if (TerminateISR() == E_OS_DISABLEDINT)
		{
			tpl_reset_interrupt_lock_status();
			tpl_enable_all_interrupts_service();	
		}
	#endif /* WITH_AUTOSAR*/
        TerminateISR();
    }
    else {

	#ifdef WITH_AUTOSAR
        if(FALSE!=tpl_get_interrupt_lock_status())  
		{                                           
			/*enable interrupts :*/
			tpl_reset_interrupt_lock_status();
			tpl_enable_all_interrupts_service();
		}
		/*error hook*/
		
		PROCESS_ERROR(E_OS_MISSINGEND);

		/*terminate the task :*/
		tpl_terminate_task_service();
    #endif /* WITH_AUTOSAR */
        fprintf(stderr, "[OSEK/VDX Spec. 2.2.3 Sec. 4.7] Ending the task without a call to TerminateTask or ChainTask is strictly forbidden and causes undefined behaviour.\n");
        exit(1);
    }
}

/**
 * global variables used to store the "old" context
 * during the trampoline phase used to create a new context
 */
VAR(sigset_t,OS_VAR)        saved_mask;
VAR(sig_atomic_t,OS_VAR)    handler_has_been_triggered;
VAR(tpl_proc_id,OS_VAR)     new_proc_id;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_create_context_boot(void)
{
    tpl_proc_id context_owner_proc_id;
    
    /*
     * 10 : restore the mask modified by _longjmp so that
     * all tasks are executed with the same mask
     * Commented out since _longjmp/_setjmp replace longjmp/setjmp
     */
     sigprocmask(SIG_SETMASK, &saved_mask, NULL);

    /* 11 : store the id of the owner of this context */
    context_owner_proc_id = new_proc_id;

    /* 12 & 13 : context is ready, jump back to the tpl_create_context */
    if( 0 == _setjmp(tpl_stat_proc_table[context_owner_proc_id]->context->initial) ) 
    {
        _longjmp(tpl_stat_proc_table[IDLE_TASK_ID]->context->current, 1);
    }

    /* We are back for the first dispatch. Let's go */
    tpl_osek_func_stub(tpl_kern.running_id);

    /* We should not be there. Let's crash*/
    abort();
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_create_context_trampoline(int sigid)
{
    /* 5 : new context created. We go back to tpl_init_context */
    if( 0==_setjmp(tpl_stat_proc_table[new_proc_id]->context->initial) ) 
    {
        handler_has_been_triggered = TRUE;
        return;
    }

    /* 
     * 9 : we are back after a jump, but no more in signal handling mode
     * We are ready to boot the new context with a clean stack 
     */
    tpl_create_context_boot();
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_create_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
    struct sigaction new_action;
    struct sigaction old_action;
    stack_t new_stack;
    stack_t old_stack;
    sigset_t new_mask;
    sigset_t old_mask;

    /* 1 : save the current mask, and mask our worker signal : SIGUSR1 */
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &new_mask, &old_mask); 

    /*
     * 2 : install the new action for our worker signal.
     * Triggered function : tpl_init_context_trampoline.
     * It will be executed on its own stack (that is the trick).
     * When it will be executed, all signals will be blocked.
     */
    memset((void*)&new_action, 0, sizeof(new_action));
    new_action.sa_handler = tpl_create_context_trampoline;
    new_action.sa_flags = SA_ONSTACK;
    sigemptyset(&new_action.sa_mask);
    sigaction(SIGUSR1, &new_action, &old_action);

    /* 3 : prepare the new stack */
    new_stack.ss_sp = (tpl_stat_proc_table[proc_id]->stack)->stack_zone;
    new_stack.ss_size = (tpl_stat_proc_table[proc_id]->stack)->stack_size;
    new_stack.ss_flags = 0;
    sigaltstack(&new_stack, &old_stack);

    /* 4-a : store data for new context in globals */
    new_proc_id = proc_id;
    saved_mask = old_mask; 
    handler_has_been_triggered = FALSE;
    /* 4-b : send the worker signal */
    kill(getpid(), SIGUSR1);
    /* 4-c : prepare to unblock the worker signal */
    sigfillset(&new_mask);
    sigdelset(&new_mask, SIGUSR1);
    /* 
     * 4-d : unblock the worker signal and wait for it.
     * Once it is arrived, the previous mask is restored.
     */
    while(FALSE == handler_has_been_triggered)
        sigsuspend(&new_mask);

    /*
     * 6 : we are back from tpl_init_context_trampoline.
     * We can restore the previous signal handling configuration
     */
    sigaltstack(NULL, &new_stack);
    new_stack.ss_flags = SS_DISABLE;
    sigaltstack(&new_stack, NULL);
    if( ! (old_stack.ss_flags & SS_DISABLE) ) 
        sigaltstack(&old_stack, NULL);
    sigaction(SIGUSR1, &old_action, NULL);
    sigprocmask(SIG_SETMASK, &old_mask, NULL);

    /*
     * 7 & 8 : we jump back to the created context.
     * This time, we are no more in signal handling mode
     */
    if ( 0 == _setjmp(tpl_stat_proc_table[IDLE_TASK_ID]->context->current) )
        _longjmp(tpl_stat_proc_table[new_proc_id]->context->initial,1);

    /* 
     * 14 : we go back to the caller 
     */
    return;
}


/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
    tpl_proc_id proc_id;
    struct sigaction sa;


    /* 
     * create the context of each tpl_proc 
     */
    for(proc_id = 0; proc_id < TASK_COUNT+ISR_COUNT+1; proc_id++)
    {
        tpl_create_context(proc_id);
    }
    
    /*
     * install a specific handler for SIGINT and SIGHUP
     */
    signal(SIGINT, quit);
    signal(SIGHUP, quit);

    
    /*
     * Creates the sigset used for interrupts and the handler.
     * - SIGALRM (non maskable timer for timing protection)
     * - SIGUSR1 (maskable signal for interrupts handled by the system
     *   and category 1 ISR)
     * - SIGUSR2 (maskable signal for interrupts handled by 
     *   category 2 ISR)  
     */
    sigemptyset(&signal_set_all);
    sigemptyset(&signal_set_cat1and2);
    sigemptyset(&signal_set_cat2);
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    sigaddset(&signal_set_all,SIGALRM);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    sigaddset(&signal_set_all,SIGUSR1);
    sigaddset(&signal_set_cat1and2,SIGUSR1);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
#ifndef NO_ISR
    sigaddset(&signal_set_all,SIGUSR2);
    sigaddset(&signal_set_cat1and2,SIGUSR2);
    sigaddset(&signal_set_cat2,SIGUSR2);
#endif
    sa.sa_handler = tpl_signal_handler;
    sa.sa_mask = signal_set_all;
    sa.sa_flags = SA_RESTART;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    sigaction(SIGALRM,&sa,NULL);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    sigaction(SIGUSR1,&sa,NULL);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
#ifndef NO_ISR
    sigaction(SIGUSR2,&sa,NULL);
#endif
    
    vp_ipc_get_shared_memory(&viper);
    vp_ipc_get_global_shared_memory(&global_shared_memory);
    
    vp_ipc_ready(&viper);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    gettimeofday (&startup_time, NULL);  
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
}

