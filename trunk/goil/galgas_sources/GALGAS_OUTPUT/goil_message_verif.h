//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_message_verif.h'                         *
//                        Generated by version 1.8.3                         *
//                       may 29th, 2009, at 11h47'31"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_message_verif_DEFINED
#define goil_message_verif_DEFINED

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

#include "galgas/C_Lexique.h"

// Include imported semantics
#include "goil_semantic_types.h"
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
//                         Routine 'check_net_dir'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_net_dir (C_Compiler &,
                                GGS_lstring  ,
                                GGS_netmess_map  ,
                                GGS_string  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'check_external_sent'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_sent (C_Compiler &,
                                GGS_lstring  ,
                                GGS_netmess_map   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Routine 'check_external_received'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_received (C_Compiler &,
                                GGS_lstring  ,
                                GGS_netmess_map   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'check_external_link_received'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_link_received (C_Compiler &,
                                GGS_link_obj  ,
                                GGS_message_map  ,
                                GGS_netmess_map  ,
                                GGS_location  ,
                                GGS_uint   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'messages_well_formed'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_messages_well_formed (C_Compiler &,
                                const GGS_message_map   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'networkmessages_exist_and_ok'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_networkmessages_exist_and_ok (C_Compiler &,
                                GGS_message_map  ,
                                GGS_netmess_map   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'networkmessages_well_formed'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_networkmessages_well_formed (C_Compiler &,
                                GGS_netmess_map   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif