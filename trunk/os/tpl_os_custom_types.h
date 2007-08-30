/**
 * @file tpl_os_custom_types.h
 *
 * @section File description
 *
 * This file gathers all data types which can be changed by user for the
 * needs of its application. Please refer to comment of each type for more
 * details.
 * 
 * @section Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
 
#ifndef TPL_OS_CUSTOM_TYPES_H
#define TPL_OS_CUSTOM_TYPES_H

#include "tpl_os_std_types.h"

/**
 * tpl_task_id is used for task identifiers.
 *
 * Default aliased type is "short int"
 *
 * @warning This data type must be signed
 * because -1 is used for INVALID_TASK
 */
typedef s16 tpl_task_id;

/**
 * tpl_priority represents a task's or a resource's priority.
 *
 * Default aliased type is "signed char"
 *
 * @warning This type must be signed as -1 is used for
 * the priority of idle task.
 */
typedef s8 tpl_priority;

/**
 * tpl_activate_counter is used to count
 * how many time a task has been activated while
 * it was not suspended.
 *
 * Default aliased type is "unsigned char"
 */
typedef u8 tpl_activate_counter;

/**
 * tpl_event_mask is used for event.
 * An event is a bit vector. By default 8 events per task are available.
 * If more events per task are needed, feel free to set tpl_event_mask to
 * an unsigned short int (16 events) or an unsigned long int (32 events).
 *
 * Default aliased type is "unsigned char"
 */
typedef u8 tpl_event_mask;

/**
 * tpl_tick is used for relative and absolute dates.
 * tpl_tick should be an unsigned datatype.
 *
 * Default aliased type is "unsigned short int"
 */
typedef u32 tpl_tick;

/**
 * tpl_alarm_type is used for alarm identifiers.
 *
 * Default aliased type is "unsigned char", so up to 256 alarms are available.
 */
typedef u8 tpl_alarm_id;

/**
 * tpl_resource_id is used for resource identifiers.
 *
 * Default aliased type is "signed char"
 *
 * @warning RES_SCHEDULER is -1 so tpl_resource_id have to be signed
 */
typedef s8 tpl_resource_id;

/**
 * tpl_stack_word is the basic element of a stack in order to have a proper
 * data alignement.
 */
typedef u32 tpl_stack_word;

/**
 * tpl_stack_size is the data type used to store the stack size
 */
typedef u16 tpl_stack_size;

/**
 * tpl_buffer is a pointer to a chunk of data in memory
 */
typedef u8 *tpl_buffer;

#ifdef WITH_AUTOSAR
/**
 * tpl_locking_monitor_id is the index of a locking monitor in the related
 * array in structure #TPL_TIMING_PROTECTION
 *
 * @see #tpl_timing_protection
 */
typedef u8 tpl_locking_monitor_id;
#endif

#endif /* TPL_OS_CUSTOM_TYPES_H */

/* End of file tpl_os_custom_types.h */
