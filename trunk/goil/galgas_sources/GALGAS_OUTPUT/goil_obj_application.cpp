//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_obj_application.cpp'                       *
//                        Generated by version 1.9.7                         *
//                     december 17th, 2009, at 9h55'29"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 629
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_application.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_application.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'appli'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_application::
pr_appli_goil_obj_application_43_12_ (goil_lexique & inLexique,
                                GGS_app_map  &var_cas_applis) {
  GGS_lstring  var_cas_name ;
  GGS_lstring  var_cas_desc ;
  GGS_app_obj  var_cas_app ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_APPLICATION) COMMA_HERE) ;
  const GGS_bool cond_1086 = (gOption_goil_5F_options_autosar_5F_on.reader_value ()).operator_isEqual (GGS_bool (false)) ;
  if (cond_1086.isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use APPLICATION objects") COMMA_SOURCE_FILE_AT_LINE (54)) ;
  }
  inLexique.assignFromAttribute_att_token (var_cas_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  const GGS_bool cond_1198 = var_cas_applis.reader_hasKey (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (57))) ;
  if (cond_1198.isBuiltAndTrue ()) {
    var_cas_applis.modifier_del (inLexique, var_cas_name, var_cas_app COMMA_SOURCE_FILE_AT_LINE (58)) ;
  }else if (cond_1198.isBuiltAndFalse ()) {
    var_cas_app = GGS_app_obj ::constructor_new (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), GGS_app_trusted_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE) COMMA_HERE) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  nt_app_attributes_ (inLexique, var_cas_app, var_cas_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
  var_cas_applis.modifier_put (inLexique, var_cas_name, var_cas_app COMMA_SOURCE_FILE_AT_LINE (83)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of production rule 'app_attributes'             *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_application::
pr_app_attributes_goil_obj_application_87_21_ (goil_lexique & inLexique,
                                GGS_app_obj  &var_cas_app,
                                GGS_lstring  var_cas_name) {
  GGS_app_trusted_obj  var_cas_trusted = var_cas_app.reader_trusted (inLexique COMMA_SOURCE_FILE_AT_LINE (91)) ;
  GGS_basic_type  var_cas_startuphook = var_cas_app.reader_startuphook (inLexique COMMA_SOURCE_FILE_AT_LINE (92)) ;
  GGS_basic_type  var_cas_shutdownhook = var_cas_app.reader_shutdownhook (inLexique COMMA_SOURCE_FILE_AT_LINE (93)) ;
  GGS_basic_type  var_cas_errorhook = var_cas_app.reader_errorhook (inLexique COMMA_SOURCE_FILE_AT_LINE (94)) ;
  GGS_basic_type  var_cas_restart = var_cas_app.reader_restart (inLexique COMMA_SOURCE_FILE_AT_LINE (95)) ;
  GGS_ident_map  var_cas_tasks = var_cas_app.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (96)) ;
  GGS_ident_map  var_cas_isrs = var_cas_app.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (97)) ;
  GGS_ident_map  var_cas_alarms = var_cas_app.reader_alarms (inLexique COMMA_SOURCE_FILE_AT_LINE (98)) ;
  GGS_ident_map  var_cas_schedtables = var_cas_app.reader_schedtables (inLexique COMMA_SOURCE_FILE_AT_LINE (99)) ;
  GGS_ident_map  var_cas_counters = var_cas_app.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (100)) ;
  GGS_ident_map  var_cas_resources = var_cas_app.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (101)) ;
  GGS_ident_map  var_cas_messages = var_cas_app.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (102)) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_obj_application_0 (inLexique)) {
        case 2 : {
          GGS_app_trusted_obj  var_cas_trust ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUSTED) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              nt_trusted_fcts_ (inLexique, var_cas_trust) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_trust = GGS_app_trusted_false ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_0 ;
          nt_description_ (inLexique, automatic_var_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_app_trusted_obj _var_3286 = var_cas_trusted ; // CAST instruction
            if (_var_3286.getPtr () != NULL) {
              macroValidPointer (_var_3286.getPtr ()) ;
              if (typeid (cPtr_app_trusted_void) == typeid (* (_var_3286.getPtr ()))) {
                var_cas_trusted = var_cas_trust ;
              }else{
                var_cas_trust.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (118)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("TRUSTED attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (118))) COMMA_SOURCE_FILE_AT_LINE (119)) ;
                var_cas_trusted.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (119)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (120)) ;
              }
            }
          }
          } break ;
        case 3 : {
          GGS_bool var_cas_sh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STARTUPHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_3758 = var_cas_startuphook ; // CAST instruction
            if (_var_3758.getPtr () != NULL) {
              macroValidPointer (_var_3758.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_3758.getPtr ()))) {
                var_cas_startuphook = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_sh COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("STARTUPHOOK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (132))) COMMA_SOURCE_FILE_AT_LINE (133)) ;
                var_cas_startuphook.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (133)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (134)) ;
              }
            }
          }
          GGS_lstring  automatic_var_1 ;
          nt_description_ (inLexique, automatic_var_1) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          GGS_bool var_cas_sh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SHUTDOWNHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_3 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_4267 = var_cas_shutdownhook ; // CAST instruction
            if (_var_4267.getPtr () != NULL) {
              macroValidPointer (_var_4267.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_4267.getPtr ()))) {
                var_cas_shutdownhook = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_sh COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("SHUTDOWNHOOK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (147))) COMMA_SOURCE_FILE_AT_LINE (148)) ;
                var_cas_shutdownhook.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (148)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (149)) ;
              }
            }
          }
          GGS_lstring  automatic_var_2 ;
          nt_description_ (inLexique, automatic_var_2) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_bool var_cas_eh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ERRORHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_4 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              var_cas_eh = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_eh = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_4762 = var_cas_errorhook ; // CAST instruction
            if (_var_4762.getPtr () != NULL) {
              macroValidPointer (_var_4762.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_4762.getPtr ()))) {
                var_cas_errorhook = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_eh COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("ERRORHOOK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (162))) COMMA_SOURCE_FILE_AT_LINE (163)) ;
                var_cas_errorhook.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (163)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (164)) ;
              }
            }
          }
          GGS_lstring  automatic_var_3 ;
          nt_description_ (inLexique, automatic_var_3) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 6 : {
          GGS_basic_type  var_cas_hr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_HAS_5F_RESTARTTASK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_5 (inLexique)) {
            case 1 : {
              GGS_lstring  var_cas_res_task ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESTARTTASK) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
              inLexique.assignFromAttribute_att_token (var_cas_res_task) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
              var_cas_hr = GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_res_task.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (172)) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_hr = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), GGS_bool (false) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_5419 = var_cas_restart ; // CAST instruction
            if (_var_5419.getPtr () != NULL) {
              macroValidPointer (_var_5419.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_5419.getPtr ()))) {
                var_cas_restart = var_cas_hr ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("RESTARTTASK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (180))) COMMA_SOURCE_FILE_AT_LINE (181)) ;
                var_cas_restart.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (181)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (182)) ;
              }
            }
          }
          GGS_lstring  automatic_var_4 ;
          nt_description_ (inLexique, automatic_var_4) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 7 : {
          GGS_lstring  var_cas_task ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TASK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_task) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_tasks.modifier_put (inLexique, var_cas_task, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_task.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (187)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (187)) ;
          GGS_lstring  automatic_var_5 ;
          nt_description_ (inLexique, automatic_var_5) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 8 : {
          GGS_lstring  var_cas_isr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ISR) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_isr) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_isrs.modifier_put (inLexique, var_cas_isr, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_isr.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (192)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (192)) ;
          GGS_lstring  automatic_var_6 ;
          nt_description_ (inLexique, automatic_var_6) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 9 : {
          GGS_lstring  var_cas_alarm ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ALARM) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_alarm) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_alarms.modifier_put (inLexique, var_cas_alarm, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_alarm.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (197)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (197)) ;
          GGS_lstring  automatic_var_7 ;
          nt_description_ (inLexique, automatic_var_7) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 10 : {
          GGS_lstring  var_cas_st ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SCHEDULETABLE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_st) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_schedtables.modifier_put (inLexique, var_cas_st, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_st.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (202)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (202)) ;
          GGS_lstring  automatic_var_8 ;
          nt_description_ (inLexique, automatic_var_8) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 11 : {
          GGS_lstring  var_cas_ct ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COUNTER) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_ct) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_counters.modifier_put (inLexique, var_cas_ct, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_ct.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (207)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (207)) ;
          GGS_lstring  automatic_var_9 ;
          nt_description_ (inLexique, automatic_var_9) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 12 : {
          GGS_lstring  var_cas_rez ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESOURCE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_rez) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_resources.modifier_put (inLexique, var_cas_rez, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_rez.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (212)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (212)) ;
          GGS_lstring  automatic_var_10 ;
          nt_description_ (inLexique, automatic_var_10) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 13 : {
          GGS_lstring  var_cas_mes ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MESSAGE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_mes) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_messages.modifier_put (inLexique, var_cas_mes, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_mes.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (217)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (217)) ;
          GGS_lstring  automatic_var_11 ;
          nt_description_ (inLexique, automatic_var_11) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  var_cas_app = GGS_app_obj ::constructor_new (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), var_cas_trusted, var_cas_startuphook, var_cas_shutdownhook, var_cas_errorhook, var_cas_restart, var_cas_tasks, var_cas_isrs, var_cas_alarms, var_cas_schedtables, var_cas_counters, var_cas_resources, var_cas_messages COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'trusted_fcts'              *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_application::
pr_trusted_fcts_goil_obj_application_239_19_ (goil_lexique & inLexique,
                                GGS_app_trusted_obj  &var_cas_trust_attr) {
  GGS_stringset  var_cas_t_funcs = GGS_stringset ::constructor_emptySet () ;
  switch (select_goil_obj_application_6 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
      { bool syntaxRepeat_7 = true ;
        while (syntaxRepeat_7) {
          switch (select_goil_obj_application_7 (inLexique)) {
            case 2 : {
              GGS_lstring  var_cas_f_name = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUSTED_5F_FUNCTION) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
              GGS_bool var_cas_tfok = GGS_bool (false) ;
              switch (select_goil_obj_application_8 (inLexique)) {
                case 1 : {
                  inLexique.assignFromAttribute_att_token (var_cas_f_name) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  var_cas_tfok = GGS_bool (true) ;
                  } break ;
                case 2 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_NAME) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
                  inLexique.assignFromAttribute_a_string (var_cas_f_name) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  var_cas_tfok = GGS_bool (true) ;
                  } break ;
                case 3 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              const GGS_bool cond_7954 = var_cas_tfok ;
              if (cond_7954.isBuiltAndTrue ()) {
                var_cas_t_funcs.addAssign_operation (var_cas_f_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (259))) ;
              }
              } break ;
            default :
              syntaxRepeat_7 = false ;
              break ;
          }
        }
      }
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
      } break ;
    case 2 : {
      } break ;
    default :
      break ;
  }
  var_cas_trust_attr = GGS_app_trusted_true ::constructor_new (inLexique, GGS_location (inLexique), var_cas_t_funcs COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

