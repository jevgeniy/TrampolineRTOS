/**
 * @file tpl_os_kernel.c
 *
 * @section descr File description
 *
 * Trampoline kernel structures and functions. These functions are used
 * internally by trampoline and should not be used directly.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_hooks.h"
#include "tpl_os_error.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_dow.h"
#include "tpl_trace.h"

#ifdef WITH_AUTOSAR_STACK_MONITORING
#include "tpl_as_stack_monitor.h"
#endif
#ifdef WITH_AUTOSAR
#include "tpl_as_st_kernel.h"
#if AUTOSAR_SC == 3 || AUTOSAR_SC == 4
#include "tpl_as_app_kernel.h"
#endif
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_protec_hook.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

STATIC /*@null@*/ FUNC(VAR(tpl_proc_id, AUTOMATIC), OS_CODE) tpl_get_proc(void);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @def INVALID_TASK
 *
 * This value is used to specify an invalid #TaskType
 * It is initialise by INVALID_TASK_ID to initialise other structure
 * without INVALID_TASK, which is a constant.
 */
CONST(tpl_proc_id, AUTOMATIC) INVALID_TASK = INVALID_TASK_ID;

/*
 * @internal
 *
 * The Application Mode that was used to start the OS.
 *
 * @see #tpl_start_os_service
 * @see #tpl_shutdown_os_service
 */
STATIC VAR(tpl_application_mode, OS_VAR) application_mode;

/*
 * idle_task is the task descriptor of the kernel task
 * used when no other task is ready. The OS starts
 * by setting this task as the running task (ie the
 * init code currently being run.
 * It then calls tpl_schedule to start the
 * multitasking and falls back in an infinite loop.
 */

/**
 * @internal
 *
 * static part of the idle task descriptor
 *
 * @see #idle_task
 */
CONST(tpl_proc_static, OS_CONST) idle_task_static = {
    /* context              */  IDLE_CONTEXT,
    /* stack                */  IDLE_STACK,
    /* entry point          */  IDLE_ENTRY,
    /* internal resource    */  NULL,
    /* id is IDLE_TASK_ID   */  IDLE_TASK_ID,
#ifdef WITH_OSAPPLICATION
    /* OS application id    */  INVALID_OSAPPLICATION,
#endif
    /* base priority is 0   */  0,
    /* max activate count   */  1,
    /* type is BASIC        */  TASK_BASIC
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* no timing protection
       for the idle task :D */  ,NULL
#endif
};

/**
 * @internal
 *
 * idle task descriptor
 */
VAR(tpl_proc, OS_VAR) idle_task = {
    /* resources            */  NULL,
#ifdef WITH_OSAPPLICATION
    /* trusted count  */        0,
#endif /* WITH_OSAPPLICATION */
    /* activation count     */  0,
    /* priority             */  0,
    /* state                */  RUNNING
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation_allowed   */  ,TRUE
#endif
};

/**
 * @internal
 *
 * tpl_kern gather informations on the current executing object and
 * the previous one
 */
VAR(tpl_kern_state, OS_VAR) tpl_kern =
{
  NULL,
  &idle_task_static,
  NULL,
  &idle_task,
  IDLE_TASK_ID,
  NO_NEED_SWITCH
};

/**
 * @internal
 *
 * tpl_running_id is the currently running process id.
 *
 * At system startup it is set to IDLE_TASK_ID since the main is a part
 * of the idle task.
 */
/* VAR(int, OS_VAR) tpl_running_id = IDLE_TASK_ID; */

/**
 * @internal
 *
 * tpl_need_switch is used to indicate a context switch should occur
 * It is set un the services and tested before calling the context switch
 * and reset to FALSE after that
 */
/* VAR(u8, OS_VAR) tpl_need_switch = NO_NEED_SWITCH; */


/*  MISRA RULE 27 VIOLATION: These 2 variables are used only in this file
    but declared in the configuration file, this is why they do not need
    to be declared as external in a header file
*/

/**
 * @internal
 *
 * tpl_ready_list is a table that is automatically generated by goil from
 * the application description. Indexes of this table are the priority levels
 * Each of its elements is a pointer to the fifo used to store task/isr2
 * activation instances and the size of this fifo.
 */
extern VAR(tpl_priority_level, OS_VAR) tpl_ready_list[];

/**
 * @internal
 *
 * tpl_fifo_rw is a table that is automatically generated by goil from
 * the application description. Indexes of this table are the priority levels
 * each of its elements are a read and write index in the fifo.
 */
extern VAR(tpl_fifo_state, OS_VAR) tpl_fifo_rw[];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_8BIT
#include "tpl_memmap.h"

/**
 * MISRA RULE 27 VIOLATION: This object is declared in this file but is
 * used as external only in the file tpl_os.c
 */

/**
 * @internal
 *
 * tpl_h_prio is the index of the highest priority non empty fifo
 * in the ready list. It is used to speed up scheduling
 */
VAR(s8, OS_VAR) tpl_h_prio = -1;

#define OS_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * INTERNAL_RES_SCHEDULER is an internal resource with the higher task priority
 * in the application. A task is non preemptable when INTERNAL_RES_SCHEDULER
 * is set as internal resource.
 */
VAR(tpl_internal_resource, OS_VAR) INTERNAL_RES_SCHEDULER = {
    RES_SCHEDULER_PRIORITY, /**< the ceiling priority is defined as the
                                 maximum priority of the tasks of the
                                 application                                */
    0,
    FALSE
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_POWEROF2QUEUE

#ifdef WITH_DOW
/* MISRA RULE 13 VIOLATION: this function is only used for debug purpose,
   so production release is not impacted by MISRA rules violated
   in this function
*/
FUNC(void, OS_CODE) printrl(
  P2VAR(char, OS_APPL_DATA, AUTOMATIC) msg)
{
  int i,j;
  tpl_exec_common **level;
  u8 mask;

  printf("%s - Highest: %d\n",msg,tpl_h_prio);
  for (i = 0; i < PRIO_LEVEL_COUNT; i++)
  {
    printf("P%2d: ",i);
    level = tpl_ready_list[i].fifo;
    mask = tpl_ready_list[i].mask;
    for (j = 0; j < tpl_fifo_rw[i].size; j++)
    {
      int idx = mask & (tpl_fifo_rw[i].read + j);
      printf(" %d",level[idx]);
    }
    printf("\n");
  }
}
#endif

/**
 * @internal
 *
 * tpl_get_proc extracts the highest priority ready process
 * from the executable objects list and returns it.
 * tpl_get_proc returns NULL if no ready executable object
 * is available
 *
 * This version of the function works for a power of 2 priority queue size
 *
 * @return highest priority executable object descriptor
 */
STATIC /*@null@*/
FUNC(VAR(tpl_proc_id, AUTOMATIC), OS_CODE) tpl_get_proc(void)
{
  VAR(tpl_proc_id, AUTOMATIC)                 elected;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA) highest;
  VAR(u8, AUTOMATIC)                          read_idx;

  DOW_ASSERT((tpl_h_prio >= 0) && (tpl_h_prio < PRIO_LEVEL_COUNT))
  DOW_ASSERT(tpl_fifo_rw[tpl_h_prio].size > 0)

  DOW_DO(printrl("tpl_get_exec_object - avant");)

  /*  Get the highest priority non empty fifo                         */
  highest = tpl_ready_list[tpl_h_prio].fifo;

  /*  Get the read index                                              */
  read_idx = tpl_fifo_rw[tpl_h_prio].read;

  /*  The fifo is not empty, get the descriptor                       */
  elected = highest[read_idx];

  /*  Adjust the read index and the size                              */
  read_idx = (read_idx + 1) & tpl_ready_list[tpl_h_prio].mask;
  tpl_fifo_rw[tpl_h_prio].read = read_idx;
  tpl_fifo_rw[tpl_h_prio].size--;

  /*  Adjust the highest priority non empty fifo index                */
  while ((tpl_h_prio >= 0) && (tpl_fifo_rw[tpl_h_prio].size == 0))
  {
    tpl_h_prio--;
  }

  DOW_DO(printrl("tpl_get_exec_object - apres");)

  return elected;
}

/**
 * @internal
 *
 * tpl_put_preempted_proc put a preempted process
 * in the ready executable object list
 *
 * This version of the function works for a power of 2 priority queue size
 *
 * @param proc_id   id of the process
 */
FUNC(void, OS_CODE) tpl_put_preempted_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  Get the current priority of the executable object             */
  VAR(tpl_priority, AUTOMATIC)                prio;
  P2VAR(tpl_proc_id, OS_APPL_DATA, AUTOMATIC) fifo;
  VAR(u8, AUTOMATIC)                          write_idx;
  DOW_DO(printrl("tpl_put_preempted_exec_object - avant");)

  /*  the priority used as level in the ready list
      for a preempted object is the current priority                */
  prio = tpl_dyn_proc_table[proc_id]->priority;

  DOW_ASSERT((prio >= 0) && (prio < PRIO_LEVEL_COUNT))
  DOW_ASSERT(tpl_fifo_rw[prio].size < tpl_ready_list[prio].size)

  /*  a preempted executable object is put at the head of the fifo  */
  write_idx = (tpl_fifo_rw[prio].read - 1) & tpl_ready_list[prio].mask ;

  tpl_fifo_rw[prio].read = write_idx;

  /*  Get the corresponding fifo                                    */
  fifo = tpl_ready_list[prio].fifo;

  /*  put the executable object in it */
  fifo[write_idx] = proc_id ;

  /* adjust the size                                                */
  tpl_fifo_rw[prio].size++;

  /* adjust the highest priority non empty fifo                     */
  if (prio > tpl_h_prio) {
    tpl_h_prio = prio;
  }

  DOW_DO(printrl("tpl_put_preempted_exec_object - apres");)
}

/**
 * @internal
 *
 * tpl_put_new_proc put a newly activated process
 * in the ready executable object list
 *
 * This version of the function works for a power of 2 priority queue size
 *
 * @param proc_id   id of the process
 */
FUNC(void, OS_CODE) tpl_put_new_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  Get the current priority of the executable object                   */
  VAR(tpl_priority, AUTOMATIC)                prio;
  P2VAR(tpl_proc_id, OS_APPL_DATA, AUTOMATIC) fifo;
  VAR(u8, AUTOMATIC)                          write_idx;

  DOW_DO(printrl("tpl_put_new_exec_object - avant");)

  /*  the priority used as level in the ready list
      for a newly activated object is the base priority                   */
  prio = tpl_stat_proc_table[proc_id]->base_priority;

  DOW_ASSERT((prio >= 0) && (prio < PRIO_LEVEL_COUNT))
  DOW_ASSERT(tpl_fifo_rw[prio].size < tpl_ready_list[prio].size)

  /*  a newly activated executable object
      is put at the end of the fifo                                       */
  write_idx = (tpl_fifo_rw[prio].read + tpl_fifo_rw[prio].size) &
  tpl_ready_list[prio].mask;

  /*  Get the corresponding fifo                                          */
  fifo = tpl_ready_list[prio].fifo;

  /*  put the executable object in it */
  fifo[write_idx] = proc_id ;

  /* adjust the size                                                      */
  tpl_fifo_rw[prio].size++;


  /* adjust the highest priority non empty fifo                           */
  if (prio > tpl_h_prio) {
    tpl_h_prio = prio;
  }

  DOW_DO(printrl("tpl_put_new_exec_object - apres");)
}

#else /* WITH_POWEROF2QUEUE */

#ifdef WITH_DOW
#include <stdio.h>
/* MISRA RULE 13 VIOLATION: this function is only used for debug purpose,
   so production release is not impacted by MISRA rules violated
   in this function
*/
FUNC(void, OS_CODE) printrl(
  P2VAR(char, AUTOMATIC, OS_APPL_DATA) msg)
{
  int i,j;
  tpl_proc_id *level;
  int size;

  printf("%s - Highest: %d\n",msg,tpl_h_prio);
  for (i = 0; i < PRIO_LEVEL_COUNT; i++)
  {
    printf("P%2d: ",i);
    level = tpl_ready_list[i].fifo;
    size = tpl_fifo_rw[i].size;
    for (j = 0; j < tpl_fifo_rw[i].size; j++)
    {
      int idx = tpl_fifo_rw[i].read + j;
      if (idx >= tpl_ready_list[i].size)
      {
        idx -= tpl_ready_list[i].size;
      }
      printf(" %d [%d]",level[idx],size);
    }
    printf("\n");
  }
}
#endif

/**
 * @internal
 *
 * tpl_get_proc extracts the highest priority ready executable
 * object from the executable objects list and returns it.
 * tpl_get_proc returns NULL if no ready executable object
 * is available
 *
 * This version of the function works for a priority queue of any size
 *
 * @return  highest priority process descriptor
 */
STATIC /*@null@*/
FUNC(VAR(tpl_proc_id, AUTOMATIC), OS_CODE) tpl_get_proc(void)
{
  VAR(tpl_proc_id, AUTOMATIC)                 elected;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA) highest;
  VAR(u8, AUTOMATIC)                          read_idx;

  DOW_ASSERT((tpl_h_prio >= 0) && (tpl_h_prio < PRIO_LEVEL_COUNT))
  DOW_ASSERT(tpl_fifo_rw[tpl_h_prio].size > 0)

  DOW_DO(printrl("tpl_get_exec_object - avant");)

  /*  Get the highest priority non empty fifo                         */
  highest = tpl_ready_list[tpl_h_prio].fifo;

  /*  Get the read index                                              */
  read_idx = tpl_fifo_rw[tpl_h_prio].read;

  /*  The fifo is not empty, get the descriptor                       */
  elected = highest[read_idx];

  /*  Adjust the read index and the size                              */
  read_idx++;
  if (read_idx >= tpl_ready_list[tpl_h_prio].size)
  {
    read_idx = 0;
  }
  tpl_fifo_rw[tpl_h_prio].read = read_idx;
  tpl_fifo_rw[tpl_h_prio].size--;

  /*  Adjust the highest priority non empty fifo index                */
  while ((tpl_h_prio >= 0) && (tpl_fifo_rw[tpl_h_prio].size == 0))
  {
    tpl_h_prio--;
  }

  DOW_DO(printrl("tpl_get_exec_object - apres");)

  return elected;
}

/**
 * @internal
 *
 * tpl_put_preempted_proc put a preempted executable object
 * in the ready executable object list
 *
 * This version of the function works for a priority queue of any size
 *
 * @param proc_id   id of the process
 */
FUNC(void, OS_CODE)
tpl_put_preempted_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  Get the current priority of the executable object               */
  VAR(tpl_priority, AUTOMATIC)                prio;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA) fifo;
  VAR(u8, AUTOMATIC)                          write_idx;
  DOW_DO(VAR(u8, AUTOMATIC) size_before;)

  DOW_DO(printrl("tpl_put_prempted_exec_object - avant");)

  /*  the priority used as level in the ready list
      for a preempted object is the current priority                  */
  prio = tpl_dyn_proc_table[proc_id]->priority;

  DOW_ASSERT((prio >= 0) && (prio < PRIO_LEVEL_COUNT))
  DOW_ASSERT(tpl_fifo_rw[prio].size < tpl_ready_list[prio].size)

  DOW_DO(size_before = tpl_fifo_rw[prio].size;)

  /*  a preempted executable object is put at the head of the fifo    */
  write_idx = tpl_fifo_rw[prio].read - 1 ;

  /*  since write_idx is unsigned, an overflow could occur            */
  if (write_idx >= tpl_ready_list[prio].size) {
    write_idx = tpl_ready_list[prio].size - 1;
  }
  tpl_fifo_rw[prio].read = write_idx;

  /*  Get the corresponding fifo                                      */
  fifo = tpl_ready_list[prio].fifo;

  /*  put the executable object in it                                 */
  fifo[write_idx] = proc_id ;

  /* adjust the size                                                  */
  tpl_fifo_rw[prio].size++;

  DOW_ASSERT(tpl_fifo_rw[prio].size == (size_before + 1));

  /* adjust the highest priority non empty fifo                       */
  if (prio > tpl_h_prio) {
    tpl_h_prio = prio;
  }

  DOW_DO(printrl("tpl_put_preempted_exec_object - apres");)
}

/**
 * @internal
 *
 * tpl_put_new_proc put a newly activated executable object
 * in the ready executable object list
 *
 * This version of the function works for a priority queue of any size
 *
 * @param proc_id   id of the process
 */
FUNC(void, OS_CODE) tpl_put_new_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  Get the current priority of the executable object */
  VAR(tpl_priority, AUTOMATIC)                prio;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA) fifo;
  VAR(u8, AUTOMATIC)                          write_idx;
  DOW_DO(VAR(u8, AUTOMATIC) size_before;)

  DOW_DO(printrl("tpl_put_new_exec_object - avant");)

  /*  the priority used as level in the ready list
      for a newly activated object is the base priority */
  prio = tpl_stat_proc_table[proc_id]->base_priority ;

  DOW_ASSERT((prio >= 0) && (prio < PRIO_LEVEL_COUNT))
  DOW_ASSERT(tpl_fifo_rw[prio].size < tpl_ready_list[prio].size)

  DOW_DO(size_before = tpl_fifo_rw[prio].size;)

  /*  a newly activated executable object
      is put at the end of the fifo                     */
  write_idx = tpl_fifo_rw[prio].read + tpl_fifo_rw[prio].size;

  /*  adjust the write index                            */
  if (write_idx >= tpl_ready_list[prio].size) {
    write_idx -= tpl_ready_list[prio].size;
  }

  /*  Get the corresponding fifo                        */
  fifo = tpl_ready_list[prio].fifo;

  /*  put the executable object in it                   */
  fifo[write_idx] = proc_id ;

  /* adjust the size                                    */
  tpl_fifo_rw[prio].size++;

  DOW_ASSERT(tpl_fifo_rw[prio].size == (size_before + 1));

  /* adjust the highest priority non empty fifo         */
  if (prio > tpl_h_prio) {
    tpl_h_prio = prio;
  }

  DOW_DO(printrl("tpl_put_new_exec_object - apres");)
}


#endif /* WITH_POWEROF2QUEUE */

#ifdef WITH_OSAPPLICATION
/**
 * @internal
 *
 * tpl_remove_proc_for_prio removes all the process instances at the given
 * priority queue
 */
FUNC(void, OS_CODE) tpl_remove_proc_for_prio(
  CONST(tpl_proc_id, AUTOMATIC)   proc_id,
  CONST(tpl_priority, AUTOMATIC)  prio)
{
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA)
    fifo = tpl_ready_list[prio].fifo;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA)
    end_fifo = fifo + tpl_ready_list[prio].size - 1;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA)
    r = fifo + tpl_fifo_rw[prio].read;
  P2VAR(tpl_proc_id, AUTOMATIC, OS_APPL_DATA) w = r;
  VAR(u8, AUTOMATIC) size = tpl_fifo_rw[prio].size;
  VAR(u8, AUTOMATIC) new_size = size;

  while (size > 0)
  {
    if (*r != proc_id)
    {
      *w = *r;
      w = (w == end_fifo) ? fifo : w + 1 ;
    }
    else {
      new_size--;
    }
    r = (r == end_fifo) ? fifo : r + 1 ;
    size--;
  }
  tpl_fifo_rw[prio].size = new_size;

  /*  Adjust the highest priority non empty fifo index                */
  while ((tpl_h_prio >= 0) && (tpl_fifo_rw[tpl_h_prio].size == 0))
  {
    tpl_h_prio--;
  }
}

/**
 * @internal
 *
 * tpl_remove_proc removes all the process instances in the ready queue
 */
FUNC(void, OS_CODE) tpl_remove_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  the process may be present in 2 priority levels:
      - in its current priority level (1 time)
      - in its base priority level (possibly many times)
   */
  CONST(tpl_priority, AUTOMATIC) prio = tpl_dyn_proc_table[proc_id]->priority;
  CONST(tpl_priority, AUTOMATIC) base_prio =
    tpl_stat_proc_table[proc_id]->base_priority;

  DOW_DO(printf("\n**** remove proc %d ****\n",proc_id);)
  DOW_DO(printrl("tpl_remove_proc - before");)

  /*  First clean the current prio fifo if needed */
  if (prio != base_prio)
  {
    tpl_remove_proc_for_prio(proc_id, base_prio);
  }
  /*  Then clean the base_prio fifo */
  tpl_remove_proc_for_prio(proc_id, prio);

  DOW_DO(printrl("tpl_remove_proc - after");)
}

#endif

/**
 * @internal
 *
 * tpl_current_os_state returns the current state of the OS.
 *
 * @see #tpl_os_state
 */
FUNC(tpl_os_state, OS_CODE) tpl_current_os_state(void)
{
  VAR(tpl_os_state, OS_APPL_DATA) state = OS_UNKNOWN;

  if (tpl_kern.running_id == -2) {
    state = OS_INIT;
  }
  else if (tpl_kern.running_id == INVALID_TASK)
  {
    state = OS_IDLE;
  }
  else if (tpl_kern.running_id >= TASK_COUNT)
  {
    state = OS_ISR2;
  }
  else
  {
    state = OS_TASK;
  }

  return state;
}

/**
 * @internal
 *
 * Get an internal resource
 *
 * @param task task from which internal resource is got
 */
FUNC(void, OS_CODE) tpl_get_internal_resource(
  CONST(tpl_proc_id, AUTOMATIC) task_id)
{
  CONSTP2VAR(tpl_internal_resource, AUTOMATIC, OS_APPL_DATA) rez =
    tpl_stat_proc_table[task_id]->internal_resource;

  if ((rez != NULL) && (rez->taken == FALSE))
  {
    rez->taken = TRUE;
    rez->owner_prev_priority = tpl_dyn_proc_table[task_id]->priority;
    tpl_dyn_proc_table[task_id]->priority = rez->ceiling_priority;
  }
}

/**
 * @internal
 *
 * Release an internal resource
 *
 * @param task task from which internal resource is released
 */
FUNC(void, OS_CODE) tpl_release_internal_resource(
    CONST(tpl_proc_id, AUTOMATIC) task_id)
{
  CONSTP2VAR(tpl_internal_resource, AUTOMATIC, OS_APPL_DATA) rez =
    tpl_stat_proc_table[task_id]->internal_resource;

  if ((rez != NULL) && (rez->taken == TRUE))
  {
    rez->taken = FALSE;
    tpl_dyn_proc_table[task_id]->priority = rez->owner_prev_priority;
  }
}

/**
 * @internal
 *
 * Does the scheduling when called from a running object.
 *
 * This function is called by the OSEK/VDX Schedule
 * and ActivateTask services
 *
 * @param from can be one of #FROM_TASK_LEVEL or #FROM_IT_LEVEL
 *
 */
FUNC(void, OS_CODE) tpl_schedule_from_running(void)
{
  VAR(u8, AUTOMATIC) need_switch = NO_NEED_SWITCH;

  /*  the tpl_running_obj is never NULL and is in the state RUNNING  */
  DOW_ASSERT(tpl_kern.running != NULL)
  DOW_ASSERT(tpl_kern.running->state == RUNNING)
  DOW_ASSERT(tpl_h_prio != -1)

#ifdef WITH_AUTOSAR_STACK_MONITORING
  tpl_check_stack (tpl_kern.running_id);
#endif /* WITH_AUTOSAR_STACK_MONITORING */

  if (tpl_h_prio > tpl_kern.running->priority)
  {
    /*  a task switch will occur. It is time to call the
        PostTaskHook while the soon descheduled task is running   */
    CALL_POST_TASK_HOOK()

    /*  the current running task become READY                     */
    tpl_kern.running->state = (tpl_proc_state)READY;
    /*  put the running task in the ready task list               */
    /*  Bug fix. preempted objects are put at the head of the
        set while newly activated objects are put at the end of
        the set. So we have to distinguish them                   */
    tpl_put_preempted_proc(tpl_kern.running_id);
    /*  copy it in old slot of tpl_kern                           */
    tpl_kern.old = tpl_kern.running;
    tpl_kern.s_old = tpl_kern.s_running;


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /*  pause the budget monitor                                  */
    tpl_pause_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */


    /*  get the ready task from the ready task list               */
    tpl_kern.running_id = tpl_get_proc();
    tpl_kern.running = tpl_dyn_proc_table[tpl_kern.running_id];
    tpl_kern.s_running = tpl_stat_proc_table[tpl_kern.running_id];

      TRACE_ISR_PREEMPT(tpl_kern)
      TRACE_TASK_PREEMPT(tpl_kern)

    if (tpl_kern.running->state == READY_AND_NEW)
    {
      /*  the object has not be preempted. So its
          descriptor must be initialized                          */
      tpl_init_proc(tpl_kern.running_id);
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
      /*  start the budget monitor for the activated task or isr  */
      tpl_start_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
    }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    else
    {
      tpl_continue_budget_monitor(tpl_kern.running_id);
    }
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

    /*  the inserted task become RUNNING                          */
    TRACE_TASK_EXECUTE(tpl_kern.running_id)
    TRACE_ISR_RUN(tpl_kern.running_id)
    tpl_kern.running->state = RUNNING;
    /*  If an internal resource is assigned to the task
        and it is not already taken by it, take it                */
    tpl_get_internal_resource(tpl_kern.running_id);

    /*  A new task has been elected. It is time to call
        PreTaskHook while the rescheduled task is running         */
    CALL_PRE_TASK_HOOK()

    need_switch = NEED_SWITCH | NEED_SAVE;
  }

  tpl_kern.need_switch = need_switch;
}

/**
 * @internal
 *
 * Does the scheduling form a dying object
 *
 * This function is called by the OSEK/VDX TerminateTask, ChainTask,
 * and by the function TerminateISR
 *
 */
FUNC(void, OS_CODE) tpl_schedule_from_dying(void)
{
#ifdef WITH_AUTOSAR_STACK_MONITORING
  tpl_check_stack(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_STACK_MONITORING */

  /*  a task switch will occur. It is time to call the
   PostTaskHook while the soon descheduled task is running             */
  CALL_POST_TASK_HOOK()

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  /*  pause the budget monitoring when a running obj has ended            */
  tpl_stop_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

  /*  the task loses the CPU because it has been put in the WAITING or
   in the DYING state, its internal resource is released.              */
  tpl_release_internal_resource(tpl_kern.running_id);

  /*  and checked to compute its state.                                 */
  if (tpl_kern.running->activate_count > 0)
  {
    /*  there is at least one instance of the dying running object in
        the ready list. So it is put in the READY_AND_NEW state. This
        way when the next instance will be prepared to run it will
        be initialized.                                                 */
    tpl_kern.running->state = READY_AND_NEW;
  }
  else
  {
    /*  there is no instance of the dying running object in the ready
        list. So it is put in the SUSPENDED state.                      */
    tpl_kern.running->state = SUSPENDED;
  }

  /*  copy it in old slot of tpl_kern                           */
  tpl_kern.old = tpl_kern.running;
  tpl_kern.s_old = tpl_kern.s_running;
  /*  get the ready task from the ready task list                       */
  tpl_kern.running_id = tpl_get_proc();
  tpl_kern.running = tpl_dyn_proc_table[tpl_kern.running_id];
  tpl_kern.s_running = tpl_stat_proc_table[tpl_kern.running_id];

  if (tpl_kern.running->state == READY_AND_NEW)
  {
    /*  the object has not be preempted. So its
        descriptor must be initialized                                  */
    tpl_init_proc(tpl_kern.running_id);
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start the budget monitor for the activated task or isr           */
    tpl_start_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  }
  else
  {
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_continue_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  }
  /*  the inserted task become RUNNING                                  */
  TRACE_ISR_RUN(tpl_kern.running_id)
  TRACE_TASK_EXECUTE(tpl_kern.running_id)
  tpl_kern.running->state = RUNNING;
  /*  If an internal resource is assigned to the task
      and it is not already taken by it, take it                        */
  tpl_get_internal_resource(tpl_kern.running_id);

  /*  A new task has been elected. It is time to call PreTaskHook while
      the rescheduled task is running                                   */
  CALL_PRE_TASK_HOOK()

  tpl_kern.need_switch = NEED_SWITCH;
}

/**
 * @internal
 *
 * Does the scheduling from the waiting state
 *
 * This function is called by the OSEK/VDX WaitEvent
 *
 */
FUNC(void, OS_CODE) tpl_schedule_from_waiting(void)
{
#ifdef WITH_AUTOSAR_STACK_MONITORING
  tpl_check_stack(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_STACK_MONITORING */

  /*  a task switch will occur. It is time to call the
      PostTaskHook while the soon descheduled task is running     */
  CALL_POST_TASK_HOOK()

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  /*  pause the budget monitoring when a task has ended           */
  tpl_pause_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

  /*  the task loses the CPU because it has been put in the
      WAITING or in the DYING state, its internal resource
      is released.                                                */
  tpl_release_internal_resource(tpl_kern.running_id);


  /*  copy it in old slot of tpl_kern                           */
  tpl_kern.old = tpl_kern.running;
  tpl_kern.s_old = tpl_kern.s_running;
  /*  get the ready task from the ready task list                 */
  tpl_kern.running_id = tpl_get_proc();
  tpl_kern.running = tpl_dyn_proc_table[tpl_kern.running_id];
  tpl_kern.s_running = tpl_stat_proc_table[tpl_kern.running_id];

  TRACE_ISR_PREEMPT(tpl_kern)
  TRACE_TASK_PREEMPT(tpl_kern)

  if (tpl_kern.running->state == READY_AND_NEW)
  {
    /*  the object has not be preempted. So its
        descriptor must be initialized                            */
    tpl_init_proc(tpl_kern.running_id);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /*  start the budget monitor for the activated task           */
    tpl_start_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  }
  else
  {
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_continue_budget_monitor(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  }
  /*  the inserted task become RUNNING                            */
  TRACE_ISR_RUN(tpl_kern.running_id)
  TRACE_TASK_EXECUTE(tpl_kern.running_id)
  tpl_kern.running->state = RUNNING;
  /*  If an internal resource is assigned to the task
      and it is not already taken by it, take it                  */
  tpl_get_internal_resource(tpl_kern.running_id);

  /*  A new task has been elected
   It is time to call PreTaskHook while the
   rescheduled task is running                     */
  CALL_PRE_TASK_HOOK()

  /*  Switch the context  */

  tpl_kern.need_switch = NEED_SWITCH | NEED_SAVE;
}


/**
 * @internal
 *
 * This function is called by OSEK/VDX ActivateTask and ChainTask
 * and by all events that lead to the activation of a task (alarm,
 * notification, schedule table).
 *
 * the activation count is incremented
 * if the task is in the SUSPENDED state, it is moved
 * to the task list
 *
 * @param task_id   the identifier of the task
 */
FUNC(tpl_status, OS_CODE) tpl_activate_task(
  CONST(tpl_task_id, AUTOMATIC) task_id)
{
  VAR(tpl_status, AUTOMATIC)                              result = E_OS_LIMIT;
  CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)           task =
    tpl_dyn_proc_table[task_id];
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)  s_task =
    tpl_stat_proc_table[task_id];

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  /*  if this is the first activation in the time frame                 */
  if (task->activation_allowed == TRUE)
  {
#endif
    if (task->activate_count < s_task->max_activate_count)
    {
      if (task->activate_count == 0)
      {
        /*  the initialization is postponed to the time it will
            get the CPU as indicated by READY_AND_NEW state             */
        TRACE_TASK_ACTIVATE(task_id)

        task->state = (tpl_proc_state)READY_AND_NEW;

#ifndef NO_EXTENDED_TASK
        /*  if the object is an extended task, init the events          */
        if (task_id < EXTENDED_TASK_COUNT)
        {
          CONSTP2VAR(tpl_task_events, AUTOMATIC, OS_APPL_DATA) events =
            tpl_task_events_table[task_id];
          events->evt_set = events->evt_wait = 0;
        }
#endif

      }
      /*  put it in the list                                            */
      tpl_put_new_proc(task_id);
      /*  inc the task activation count. When the task will terminate
          it will dec this count and if not zero it will be reactivated */
      task->activate_count++;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
      tpl_start_timeframe(task_id);
#endif

      result = (tpl_status)E_OK_AND_SCHEDULE;
    }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  }
  else
  {
    result = (tpl_status)E_OS_PROTECTION_TIME;
    tpl_call_protection_hook(E_OS_PROTECTION_TIME);
  }
#endif
  return result;
}

/**
 * @internal
 *
 * This function is used by SetEvent and by tpl_raise_alarm
 *
 * @param task              Pointer to the task descriptor
 * @param incoming_event    Event mask
 */
FUNC(tpl_status, OS_CODE) tpl_set_event(
  CONST(tpl_task_id, AUTOMATIC)     task_id,
  CONST(tpl_event_mask, AUTOMATIC)  incoming_event)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_EXTENDED_TASK
  CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA) task =
    tpl_dyn_proc_table[task_id];
  CONSTP2VAR(tpl_task_events, AUTOMATIC, OS_APPL_DATA) events =
    tpl_task_events_table[task_id];

  if (task->state != (tpl_proc_state)SUSPENDED)
  {
    /*  merge the incoming event mask with the old one  */
    events->evt_set |= incoming_event;
    /*  cross check the event the task is
        waiting for and the incoming event              */
    if ((events->evt_wait & incoming_event) != 0)
    {
      /*  the task was waiting for at least one of the
          event set the wait mask is reset to 0         */
      events->evt_wait = (tpl_event_mask)0;
      /*  anyway check it is in the WAITING state       */
      if (task->state == (tpl_proc_state)WAITING)
      {
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        if(task->activation_allowed == TRUE)
        {
#endif
          /*  set the state to READY  */
          task->state = (tpl_proc_state)READY;
          /*  put the task in the READY list          */
          TRACE_TASK_RELEASED(task_id,incoming_event)
          tpl_put_new_proc(task_id);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
          tpl_start_timeframe(task_id);
#endif

          /*  notify a scheduling needs to be done    */
          result = (tpl_status)E_OK_AND_SCHEDULE;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        }
        else
        {
          tpl_call_protection_hook(E_OS_PROTECTION_TIME);
          result = (tpl_status)E_OS_PROTECTION_TIME;
        }
#endif
      }
    }
  }
  else
  {
    result = E_OS_STATE;
  }
#endif

  return result;
}

/**
 * @internal
 *
 * Executable object initialization.
 *
 * This function initialize the common part of task
 * or category 2 interrupt service routine to make them ready
 * for execution. If the object is an task it initializes
 * the event masks too (this has no effect on basic tasks).
 *
 * @param exec_obj address of the executable object descriptor
 */
FUNC(void, OS_CODE) tpl_init_proc(
    CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA) dyn =
    tpl_dyn_proc_table[proc_id];

  /*  The priority is set to the base priority of the executable object */
  dyn->priority = tpl_stat_proc_table[proc_id]->base_priority;
  /*  set the resources list to NULL                                    */
  dyn->resources = NULL;
  /*  context init is machine dependant
      tpl_init_context is declared in tpl_machine_interface.h           */
  tpl_init_context(proc_id);
}

/**
 * @internal
 *
 * Initialization of Trampoline
 */
FUNC(void, OS_CODE) tpl_init_os(CONST(tpl_application_mode, AUTOMATIC) app_mode)
{
  VAR(u16, AUTOMATIC) i;
  VAR(tpl_status, AUTOMATIC) result;
#ifndef NO_ALARM
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) auto_time_obj;
#endif

#ifdef WITH_AUTOSAR
#ifdef NO_ALARM
#ifndef NO_SCHEDTABLE
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) auto_time_obj;
#endif
#endif
#endif

#ifndef NO_TASK
  /*  Look for autostart tasks    */
  for (i = 0; i < TASK_COUNT; i++)
  {
    if (tpl_dyn_proc_table[i]->state == (tpl_proc_state)AUTOSTART)
    {
      /*  each AUTOSTART task is activated   */
      result = tpl_activate_task(i);
    }
  }
#endif
#ifndef NO_ALARM

  /*  Look for autostart alarms    */

  for (i = 0; i < ALARM_COUNT; i++)
  {
    auto_time_obj =
      (P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA))tpl_alarm_table[i];
    if (auto_time_obj->state == (tpl_time_obj_state)ALARM_AUTOSTART)
    {
      auto_time_obj->state = ALARM_ACTIVE;
      tpl_insert_time_obj(auto_time_obj);
    }
  }

#endif
#if defined WITH_AUTOSAR && !defined NO_SCHEDTABLE
  /*  Look for autostart schedule tables  */

  for (i = 0; i < SCHEDTABLE_COUNT; i++)
  {
    auto_time_obj =
      (P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA))tpl_schedtable_table[i];
    if (auto_time_obj->state == (tpl_time_obj_state)SCHEDULETABLE_AUTOSTART)
    {
      auto_time_obj->state = SCHEDULETABLE_RUNNING;
      tpl_insert_time_obj(auto_time_obj);
    }
  }
#endif
}

FUNC(tpl_application_mode, OS_CODE) tpl_get_active_application_mode_service(
  void)
{
  return application_mode;
}

FUNC(void, OS_CODE) tpl_start_os_service(
  CONST(tpl_application_mode, AUTOMATIC) mode)
{
  LOCK_KERNEL()

  application_mode = mode;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_init_timing_protection();
#endif

  TRACE_TPL_INIT()

  tpl_init_os(mode);

  /*  Call the startup hook. According to the spec, it should be called
      after the os is initialized and before the scheduler is running     */
  CALL_STARTUP_HOOK()

  /*  Call tpl_schedule to elect the greatest priority task */
  if(tpl_h_prio != -1)
  {
    tpl_schedule_from_running();

#ifndef WITH_SYSTEM_CALL
    if (tpl_kern.need_switch != NO_NEED_SWITCH)
    {
      tpl_switch_context(
        &(tpl_kern.s_old->context),
        &(tpl_kern.s_running->context)
      );
    }
#endif
  }

  UNLOCK_KERNEL()
}

FUNC(void, OS_CODE) tpl_shutdown_os_service(
    CONST(tpl_status, AUTOMATIC) error  /*@unused@*/)
{
    CALL_SHUTDOWN_HOOK(error)
    TRACE_TPL_TERMINATE()
    /* architecture dependant shutdown. */
    tpl_shutdown();

}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_kernel.c */
