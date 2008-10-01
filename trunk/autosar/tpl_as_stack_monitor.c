/**
 * @file tpl_as_stack_monitor.c
 *
 * @internal
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
 */
#include "tpl_as_stack_monitor.h"
#include "tpl_os_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#ifdef WITH_AUTOSAR_STACK_MONITORING
FUNC(void, OS_CODE) tpl_check_stack (
    P2CONST(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) this_exec_obj)
{
  /* MISRA RULE 33 VIOLATION: tpl_check_stack_footprint does not need
    to be evaluated if tpl_check_stack_pointer fails */
  if ((!tpl_check_stack_pointer(this_exec_obj)) ||
     (!tpl_check_stack_footprint(this_exec_obj)))
  {
/*
 * see �7.4.2 of AUTOSAR SWS OS 2.1, related to requirements
 * OS068 and OS396
 */
#if (SCALABILITY_CLASS == 1) || (SCALABILITY_CLASS == 2)
    tpl_shutdown_os_service(E_OS_STACKFAULT);
#else
    tpl_call_protection_hook(E_OS_STACKFAULT);
#endif
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_AUTOSAR_STACK_MONITORING */
