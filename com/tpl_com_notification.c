/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline notification implementation.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_application_def.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_com_base_mo.h"
#include "tpl_com_definitions.h"
#include "tpl_com_notification.h"

/**
 *  action function for action set flag
 */
tpl_status tpl_action_setflag(const tpl_action *action)
{
    /*
     * A tpl_action * is cast to a tpl_callback_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_flag_action * is a tpl_action *
     * This cast behaves correctly.
     */
    ((const tpl_flag_action *)action)->setflag();
    
    return E_OK;
}

/*!
 *  \brief
 *
 *
 */
void tpl_notify_receiving_mos(tpl_status result, u8 from)
{
  /*
     * Walk along the receiving message object chain and call the notification
     * for each one when the notication exists.
     */
	/*
    while (rmo != NULL) {
        tpl_action *notification = rmo->notification;
        if (notification != NULL) {
            result |= notification->action(notification);
        }
        rmo = rmo->next_mo;
    }*/
	
    if ((result & NEED_RESCHEDULING) != 0)
    {
      tpl_schedule_from_running();
#ifndef WITH_SYSTEM_CALL
      if (tpl_kern.need_switch != NO_NEED_SWITCH)
      {
        if (from == FROM_IT_LEVEL)
        {
          tpl_switch_context_from_it(
            &(tpl_kern.s_old->context),
            &(tpl_kern.s_running->context)
          );
        }
        else
        {
          tpl_switch_context(
            &(tpl_kern.s_old->context),
            &(tpl_kern.s_running->context)
          );
        }
      }
#endif
    }
  


}