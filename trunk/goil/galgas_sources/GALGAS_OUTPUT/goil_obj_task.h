//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_obj_task.h'                           *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     november 9th, 2009, at 20h9'27"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_task_DEFINED
#define goil_obj_task_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_data.h"
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
#include "goil_options.h"
#include "goil_semantics.h"
#include "goil_types_timing_prot.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                  Parser class goil_obj_task declaration                   *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_task {
  public : virtual ~goil_obj_task (void) {}

  protected : virtual void nt_task_ (goil_lexique &,
                                GGS_task_map  &) = 0 ;

  protected : virtual void nt_task_attributes_ (goil_lexique &,
                                GGS_basic_type  &,
                                GGS_lstring  &,
                                GGS_basic_type  &,
                                GGS_task_autostart_obj  &,
                                GGS_lstringlist  &,
                                GGS_lstringlist  &,
                                GGS_lstringlist  &,
                                GGS_lstringlist  &,
                                GGS_timing_prot  &,
                                GGS_ident_map  &) = 0 ;

  protected : virtual void nt_task_autostart_params_ (goil_lexique &,
                                GGS_task_autostart_obj  &) = 0 ;

  protected : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_free_field_ (goil_lexique &,
                                GGS_ident_map  &) = 0 ;

  protected : virtual void nt_timing_prot_attrs_ (goil_lexique &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_rezlock_map  &) = 0 ;

  protected : void pr_task_goil_obj_task_66_11_ (goil_lexique &,
                                GGS_task_map  &) ;

  protected : void pr_task_attributes_goil_obj_task_156_22_ (goil_lexique &,
                                GGS_basic_type  &,
                                GGS_lstring  &,
                                GGS_basic_type  &,
                                GGS_task_autostart_obj  &,
                                GGS_lstringlist  &,
                                GGS_lstringlist  &,
                                GGS_lstringlist  &,
                                GGS_lstringlist  &,
                                GGS_timing_prot  &,
                                GGS_ident_map  &) ;

  protected : virtual PMSInt16 select_repeat_goil_obj_task_0 (goil_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_obj_task_1 (goil_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_obj_task_2 (goil_lexique &) = 0 ;

  protected : virtual PMSInt16 select_goil_obj_task_3 (goil_lexique &) = 0 ;

  protected : void pr_task_autostart_params_goil_obj_task_259_28_ (goil_lexique &,
                                GGS_task_autostart_obj  &) ;

  protected : virtual PMSInt16 select_repeat_goil_obj_task_4 (goil_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
