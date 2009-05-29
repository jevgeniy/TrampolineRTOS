/*
 * Trampoline OS
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline posix signals and libpcl process machine dependent stuffs
 *
 */

#include "tpl_machine.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_internal_types.h"
#include "tpl_viper_interface.h"
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
#endif /* WITH_AUTOSAR */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <pcl.h>
#include <assert.h>
#include <sched.h>
#include <pcl.h>

coroutine_t idle_task_context = 0;


extern volatile u32 tpl_locking_depth;

#ifdef WITH_AUTOSAR
VAR(tpl_bool, OS_VAR) tpl_user_task_lock = FALSE;
VAR(u32, OS_VAR) tpl_cpt_user_task_lock = 0;
STATIC VAR(u32, OS_VAR) tpl_cpt_os_task_lock = 0;
#endif

#ifdef WITH_AUTOSAR
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(tpl_bool, OS_CODE) tpl_get_interrupt_lock_status(void)
{
    VAR(tpl_bool, AUTOMATIC) result;

    if( (TRUE == tpl_user_task_lock) || (tpl_cpt_user_task_lock > 0) )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif

/*******************************************************************************
** Function name: tpl_reset_interrupt_lock_status
** Description: this function reset the status of interrupt lock by user
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_reset_interrupt_lock_status(void)
{
  tpl_user_task_lock = FALSE;

  tpl_cpt_user_task_lock = 0;

  tpl_locking_depth = tpl_cpt_os_task_lock;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif

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
                                   
/*
 * table which stores the signals used for interrupt
 * handlers.
 */
#ifndef NO_ISR
	extern int signal_for_isr_id[ISR_COUNT];
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    const int signal_for_watchdog = SIGALRM;
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
	const int signal_for_counters = SIGUSR2;
#endif

/*
 * The signal set corresponding to the enabled interrupts
 */
sigset_t    signal_set;

/** fonction that calls the system function tpl_counter_tick() 
 * for each counter declared in the application.
 * tpl_call_counter_tick() is application dependant and is 
 * generated by the OIL compiler (goil).
 */
void tpl_call_counter_tick();

static sigset_t tpl_saved_state;

/**
 * Enable interrupts
 */
void tpl_enable_interrupts(void)
{
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1)
    {
        perror("tpl_enable_interrupts failed");
        exit(-1);
    }
}

/**
 * Disable interrupts
 */
void tpl_disable_interrupts(void)
{
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("tpl_enable_interrupts failed");
        exit(-1);
    }
}

/*
 * The signal handler used when interrupts are enabled
 */
void tpl_signal_handler(int sig)
{
		
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  struct itimerval timer;
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  
#ifndef NO_ISR
  unsigned int id;
#endif /* NO_ISR */
	
	/* Disable interrupts in PostTaskook and "PreTaskISR" :
	 * tpl_locking_depth is incremented because otherwise, when ResumeAllInterrupts
	 * is called in Post(Pre)-Task, interrupts are enabled whereas it shouldn't.
	 */
	tpl_locking_depth++; 
	
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
	if (signal_for_counters == sig) tpl_call_counter_tick();
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (sig == signal_for_watchdog)
    {
        /* disable the interval timer (one shot) */
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 1;
        timer.it_interval.tv_usec = 0;
        setitimer (ITIMER_REAL, &timer, NULL);
      
        tpl_watchdog_expiration();
    }    
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifndef NO_ISR
    for (id = 0; id < ISR_COUNT; id++)
    {
        if (signal_for_isr_id[id] == sig)
        {
			/*printf("tpl_signal_handler - ISR2 - tpl_locking_depth = %d\n",tpl_locking_depth);*/
			tpl_central_interrupt_handler(id + TASK_COUNT);
        }
    }
#endif /* NO_ISR */

	/* Release interrupts returning in the previous context*/
	tpl_locking_depth--;
}

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1);
/*      sched_yield();*/
}

static tpl_proc_static my_tpl_sleep = {
  NULL,
  {NULL, 0},
  tpl_sleep,
  NULL,
  -1,
#ifdef WITH_OSAPPLICATION
  -1,
#endif
  0,
  0,
  0,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
NULL    /* no timing protection for the idle task :D */
#endif
};

extern void viper_kill(void);

void tpl_shutdown(void)
{
	/* remove ITs */
	if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("tpl_shutdown failed");
        exit(-1);
    }
    
    viper_kill();
    /* sleep forever */
    exit(0);
}

volatile int x = 0;
int cnt = 0;
/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
    /*
     * block the handling of signals
     */
    /*  fprintf(stderr, "%d-lock\n", cnt++);*/
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("tpl_get_lock failed");
        exit(-1);
    }
/*    x++; */
    tpl_locking_depth++;

#ifdef WITH_AUTOSAR
    tpl_cpt_os_task_lock++;
#endif
    
/*    if (x > 1) printf("** lock ** X=%d\n",x);
    assert( 0 <= x && x <= 1); */
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

    if (tpl_locking_depth == 0)
    {
        if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
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
    assert( **new_context != co_current() );
    if( *new_context == &idle_task_context )
    {
        /* idle_task activation */
        co_call( idle_task_context );
    }
    else co_call( **new_context );
}


FUNC(void, OS_CODE) tpl_switch_context_from_it(
    CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) old_context,
    CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) new_context)
{
    assert( **new_context != co_current() );
    if( *new_context == &idle_task_context )
    {
        /* idle_task activation */
        co_call( idle_task_context );
    }
    else co_call( **new_context );
}

#define CO_MIN_SIZE (4*8*(4 * 1024))


void tpl_osek_func_stub( void* data )
{
    tpl_proc_function func = ((tpl_proc_static*)data)->entry;
    tpl_proc_type     type = ((tpl_proc_static*)data)->type;
  
    /* Avoid signal blocking due to a previous call to tpl_init_context in a OS_ISR2 context. */
	tpl_release_task_lock();
    
    /* printf("** unlock (tpl_osek_func_stub) ** X=%d\n",x) ; */
  
    (*func)();
    
    if (type == IS_ROUTINE) {
        TerminateISR();
    }
    else {
        fprintf(stderr, "[OSEK/VDX Spec. 2.2.3 Sec. 4.7] Ending the task without a call to TerminateTask or ChainTask is strictly forbidden and causes undefined behaviour.\n");
        exit(1);
    }
}


static coroutine_t previous_old_co = NULL;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
    coroutine_t old_co;
    coroutine_t *co = tpl_stat_proc_table[proc_id]->context;
    const tpl_stack *stack = &(tpl_stat_proc_table[proc_id]->stack);

    /* This is the entry func passed as data */
    void* data = (void*)tpl_stat_proc_table[proc_id]; 
    int stacksize = stack->stack_size;
    void* stackaddr = stack->stack_zone;  
  
    old_co = *co;
  
    assert( stacksize > 0 );
    assert( stackaddr != NULL );
    assert( data != NULL );
  

    if( stacksize < CO_MIN_SIZE )
    {
        /* co_create will fail if stacksize is < 4096 */
        stacksize = stacksize < CO_MIN_SIZE ? CO_MIN_SIZE : stacksize ;
    }
  
    stackaddr = NULL; /* co_create automatically allocate stack data using malloc. */  
    
    *co = co_create(tpl_osek_func_stub, data, stackaddr, stacksize);
  
    assert( *co != NULL );
    assert( *co != old_co );
  
    /* If old_co != NULL, we should garbage it soon. */
    if( old_co != NULL )
    {
      if( previous_old_co != NULL ) {
        co_delete( previous_old_co );
      }
        previous_old_co = old_co;
    }
}

void quit(int n)
{
    ShutdownOS(E_OK);  
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
#ifndef NO_ISR
    int id;
#endif
    
    struct sigaction sa;

    /*printf("start viper.\n");*/
    tpl_viper_init();
  
    signal(SIGINT, quit);
    signal(SIGHUP, quit);

    sigemptyset(&signal_set);
    sigemptyset(&tpl_saved_state);
    
    /*
     * init a signal mask to block all signals (aka interrupts)
     */
#ifndef NO_ISR
    for (id = 0; id < ISR_COUNT; id++) {
        sigaddset(&signal_set,signal_for_isr_id[id]);
    }
#endif
#ifndef NO_ALARM
    sigaddset(&signal_set,signal_for_counters);
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    sigaddset(&signal_set,signal_for_watchdog);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    sigaddset(&signal_set,signal_for_counters);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */


    /*
     * init the sa structure to install the handler
     */
    sa.sa_handler = tpl_signal_handler;
    sa.sa_mask = signal_set;
    sa.sa_flags = SA_RESTART;
    /*
     * Install the signal handler used to emulate interruptions
     */
#ifndef NO_ISR
    for (id = 0; id < ISR_COUNT; id++) {
        sigaction(signal_for_isr_id[id],&sa,NULL);
    }
#endif
#ifndef NO_ALARM
    sigaction(signal_for_counters,&sa,NULL);
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    sigaction(signal_for_watchdog,&sa,NULL);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    sigaction(signal_for_counters,&sa,NULL);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
    
    idle_task_context = co_create( tpl_osek_func_stub, (void*)&my_tpl_sleep, NULL, CO_MIN_SIZE );
    assert( idle_task_context != NULL );
    
    /*
     * block the handling of signals
     */
    /*if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
    */
#ifndef NO_ALARM
    tpl_viper_start_auto_timer(signal_for_counters,10000);  /* 10 ms */
#endif
#ifdef WITH_AUTOSAR
#ifndef NO_SCHEDTABLE
    #ifdef NO_ALARM
    tpl_viper_start_auto_timer(signal_for_counters,10000);  /* 10 ms */
    #endif
#endif
#endif

    /*
     * unblock the handling of signals
     */
    /*if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
	*/
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    gettimeofday (&startup_time, NULL);  
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
}


