//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'goil_syntax.h'                            *
//                        Generated by version 1.8.3                         *
//                       may 29th, 2009, at 11h47'8"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_syntax_DEFINED
#define goil_syntax_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/GGS_binaryset.h"
#include "galgas/GGS_filewrapper.h"
#include "galgas/predefined_types.h"
#include "galgas/AC_galgas_class.h"
#include "galgas/AC_galgas_domain.h"
#include "galgas/AC_galgas_mapindex.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_listmap.h"
#include "galgas/AC_galgas_list.h"
#include "galgas/AC_galgas_sortedlist.h"

//---------------------------------------------------------------------------*

#include "goil_lexique.h"

// Include imported semantics
#include "cfg_types.h"
#include "com_type.h"
#include "config_type.h"
#include "goil_env_verification.h"
#include "goil_semantics.h"
#include "goil_types_app.h"
#include "goil_types_networkmessage.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                   Parser class goil_syntax declaration                    *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_syntax {
  public : virtual ~goil_syntax (void) {}

  protected : virtual void nt_start_ (goil_lexique &) = 0 ;

  protected : virtual void nt_file_ (goil_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) = 0 ;

  protected : virtual void nt_OIL_version_ (goil_lexique &,
                                GGS_lstring  &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_application_definition_ (goil_lexique &,
                                GGS_root_obj  &) = 0 ;

  protected : virtual void nt_object_definition_list_ (goil_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) = 0 ;

  protected : virtual void nt_nm_ (goil_lexique &) = 0 ;

  protected : virtual void nt_boolean_ (goil_lexique &,
                                GGS_lbool  &) = 0 ;

  protected : virtual void nt_free_field_ (goil_lexique &,
                                GGS_ident_map  &) = 0 ;

  protected : virtual void nt_include_file_level_ (goil_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) = 0 ;

  protected : virtual void nt_include_cpu_level_ (goil_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) = 0 ;

  protected : virtual void nt_implementation_definition_ (goil_lexique &,
                                GGS_implementation  &) = 0 ;

  protected : virtual void nt_os_ (goil_lexique &,
                                GGS_os_obj  &) = 0 ;

  protected : virtual void nt_appmode_ (goil_lexique &) = 0 ;

  protected : virtual void nt_task_ (goil_lexique &,
                                GGS_task_map  &) = 0 ;

  protected : virtual void nt_counter_ (goil_lexique &,
                                GGS_counter_map  &) = 0 ;

  protected : virtual void nt_alarm_ (goil_lexique &,
                                GGS_alarm_map  &) = 0 ;

  protected : virtual void nt_resource_ (goil_lexique &,
                                GGS_resource_map  &) = 0 ;

  protected : virtual void nt_event_ (goil_lexique &,
                                GGS_event_map  &) = 0 ;

  protected : virtual void nt_isr_ (goil_lexique &,
                                GGS_isr_map  &) = 0 ;

  protected : virtual void nt_mess_ (goil_lexique &,
                                GGS_message_map  &) = 0 ;

  protected : virtual void nt_scheduletable_ (goil_lexique &,
                                GGS_scheduletable_map  &) = 0 ;

  protected : virtual void nt_appli_ (goil_lexique &,
                                GGS_app_map  &) = 0 ;

  protected : virtual void nt_networkmess_ (goil_lexique &,
                                GGS_netmess_map  &) = 0 ;

  protected : virtual void nt_com_ (goil_lexique &,
                                GGS_com  &) = 0 ;

  protected : virtual void nt_ipdu_ (goil_lexique &) = 0 ;

  protected : void pr_start_goil_syntax_133_12_ (goil_lexique &) ;

  protected : void pr_file_goil_syntax_215_11_ (goil_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) ;

  protected : virtual sint16 select_repeat_goil_syntax_0 (goil_lexique &) = 0 ;

  protected : void pr_description_goil_syntax_237_18_ (goil_lexique &,
                                GGS_lstring  &) ;

  protected : virtual sint16 select_goil_syntax_1 (goil_lexique &) = 0 ;

  protected : void pr_OIL_version_goil_syntax_249_18_ (goil_lexique &,
                                GGS_lstring  &,
                                GGS_lstring  &) ;

  protected : void pr_application_definition_goil_syntax_260_29_ (goil_lexique &,
                                GGS_root_obj  &) ;

  protected : void pr_object_definition_list_goil_syntax_313_29_ (goil_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) ;

  protected : virtual sint16 select_repeat_goil_syntax_2 (goil_lexique &) = 0 ;

  protected : void pr_nm_goil_syntax_361_9_ (goil_lexique &) ;

  protected : void pr_boolean_goil_syntax_372_14_ (goil_lexique &,
                                GGS_lbool  &) ;

  protected : virtual sint16 select_goil_syntax_3 (goil_lexique &) = 0 ;

  protected : void pr_free_field_goil_syntax_382_17_ (goil_lexique &,
                                GGS_ident_map  &) ;

  protected : virtual sint16 select_goil_syntax_4 (goil_lexique &) = 0 ;

  protected : void pr_include_file_level_goil_syntax_403_25_ (goil_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) ;

  protected : virtual sint16 select_goil_syntax_5 (goil_lexique &) = 0 ;

  protected : void pr_include_cpu_level_goil_syntax_421_24_ (goil_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) ;

  protected : virtual sint16 select_goil_syntax_6 (goil_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
