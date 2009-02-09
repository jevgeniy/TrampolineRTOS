/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline avr specifics
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_MACHINE_AVR_H__
#define __TPL_MACHINE_AVR_H__

#include "tpl_os_custom_types.h"

struct AVR_CONTEXT {
	u8 *sp;
	u8 regist[33];  //registers: R0-R15,R17-R31,SREG,R16
} ;

typedef struct AVR_CONTEXT avr_context;


//typedef u16 * avr_context;
//typedef u8 avr_register;

struct TPL_CONTEXT {
	avr_context * ic;
};

typedef struct TPL_CONTEXT tpl_context;


extern avr_context idle_task_context;
#define IDLE_CONTEXT {&idle_task_context} 


/**
 * tpl_stack_word is the basic element of a stack in order to have a proper
 * data alignement.
 */
typedef u16 tpl_stack_word;

/**
 * tpl_stack_size is the data type used to store the stack size
 */
typedef u16 tpl_stack_size;


struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size   stack_size; 
};
typedef struct TPL_STACK tpl_stack;

#define IDLE_STACK {NULL,0}

#endif
