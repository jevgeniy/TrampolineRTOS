//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_obj_os.cpp'                           *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                       june 12th, 2009, at 14h45'5"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 502
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_obj_os.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_os.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of production rule 'os'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_os::
pr_os_goil_obj_os_48_9_ (goil_lexique & inLexique,
                                GGS_os_obj  &var_cas_os) {
  GGS_lstring  var_cas_status ;
  var_cas_status = var_cas_os.reader_status (inLexique COMMA_SOURCE_FILE_AT_LINE (51)) ;
  GGS_basic_type  var_cas_startuphook ;
  var_cas_startuphook = var_cas_os.reader_startuphook (inLexique COMMA_SOURCE_FILE_AT_LINE (52)) ;
  GGS_basic_type  var_cas_shutdownhook ;
  var_cas_shutdownhook = var_cas_os.reader_shutdownhook (inLexique COMMA_SOURCE_FILE_AT_LINE (53)) ;
  GGS_basic_type  var_cas_errorhook ;
  var_cas_errorhook = var_cas_os.reader_errorhook (inLexique COMMA_SOURCE_FILE_AT_LINE (54)) ;
  GGS_basic_type  var_cas_pretaskhook ;
  var_cas_pretaskhook = var_cas_os.reader_pretaskhook (inLexique COMMA_SOURCE_FILE_AT_LINE (55)) ;
  GGS_basic_type  var_cas_posttaskhook ;
  var_cas_posttaskhook = var_cas_os.reader_posttaskhook (inLexique COMMA_SOURCE_FILE_AT_LINE (56)) ;
  GGS_basic_type  var_cas_protectionhook ;
  var_cas_protectionhook = var_cas_os.reader_protectionhook (inLexique COMMA_SOURCE_FILE_AT_LINE (57)) ;
  GGS_lstring  var_cas_scalabilityclass ;
  var_cas_scalabilityclass = var_cas_os.reader_scalabilityclass (inLexique COMMA_SOURCE_FILE_AT_LINE (58)) ;
  GGS_basic_type  var_cas_stackmonitoring ;
  var_cas_stackmonitoring = var_cas_os.reader_stackmonitoring (inLexique COMMA_SOURCE_FILE_AT_LINE (59)) ;
  GGS_basic_type  var_cas_usegetserviceid ;
  var_cas_usegetserviceid = var_cas_os.reader_usegetserviceid (inLexique COMMA_SOURCE_FILE_AT_LINE (60)) ;
  GGS_basic_type  var_cas_useparameteraccess ;
  var_cas_useparameteraccess = var_cas_os.reader_useparameteraccess (inLexique COMMA_SOURCE_FILE_AT_LINE (61)) ;
  GGS_basic_type  var_cas_useresscheduler ;
  var_cas_useresscheduler = var_cas_os.reader_useresscheduler (inLexique COMMA_SOURCE_FILE_AT_LINE (62)) ;
  GGS_basic_type  var_cas_systemcall ;
  var_cas_systemcall = var_cas_os.reader_systemcall (inLexique COMMA_SOURCE_FILE_AT_LINE (63)) ;
  GGS_lstringlist  var_cas_app_src ;
  var_cas_app_src = var_cas_os.reader_app_src (inLexique COMMA_SOURCE_FILE_AT_LINE (64)) ;
  GGS_lstringlist  var_cas_cflags ;
  var_cas_cflags = var_cas_os.reader_cflags (inLexique COMMA_SOURCE_FILE_AT_LINE (65)) ;
  GGS_lstringlist  var_cas_asflags ;
  var_cas_asflags = var_cas_os.reader_asflags (inLexique COMMA_SOURCE_FILE_AT_LINE (66)) ;
  GGS_lstringlist  var_cas_ldflags ;
  var_cas_ldflags = var_cas_os.reader_ldflags (inLexique COMMA_SOURCE_FILE_AT_LINE (67)) ;
  GGS_lstring  var_cas_app_name ;
  var_cas_app_name = var_cas_os.reader_app_name (inLexique COMMA_SOURCE_FILE_AT_LINE (68)) ;
  GGS_lstring  var_cas_tpl_base_path ;
  var_cas_tpl_base_path = var_cas_os.reader_tpl_base_path (inLexique COMMA_SOURCE_FILE_AT_LINE (69)) ;
  GGS_trace  var_cas_trace ;
  var_cas_trace = var_cas_os.reader_trace (inLexique COMMA_SOURCE_FILE_AT_LINE (70)) ;
  GGS_ident_map  var_cas_others ;
  var_cas_others = var_cas_os.reader_others (inLexique COMMA_SOURCE_FILE_AT_LINE (71)) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_OS) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_obj_os_0 (inLexique)) {
        case 2 : {
          GGS_lstring  var_cas_st ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STATUS) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          switch (select_goil_obj_os_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_EXTENDED) COMMA_HERE) ;
              var_cas_st = GGS_lstring ::constructor_new (inLexique, GGS_string ("extended"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STANDARD) COMMA_HERE) ;
              var_cas_st = GGS_lstring ::constructor_new (inLexique, GGS_string ("standard"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_0 ;
          nt_description_ (inLexique, automatic_var_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_lstring_if_empty (inLexique,  var_cas_status,  var_cas_st,  GGS_string ("STATUS") COMMA_SOURCE_FILE_AT_LINE (86)) ;
          } break ;
        case 3 : {
          GGS_lbool  var_cas_suh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STARTUPHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_suh) ;
          ::routine_set_bool (inLexique,  var_cas_startuphook,  var_cas_suh,  GGS_string ("STARTUPHOOK") COMMA_SOURCE_FILE_AT_LINE (90)) ;
          GGS_lstring  automatic_var_1 ;
          nt_description_ (inLexique, automatic_var_1) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 4 : {
          GGS_lbool  var_cas_sdh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SHUTDOWNHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_sdh) ;
          GGS_lstring  automatic_var_2 ;
          nt_description_ (inLexique, automatic_var_2) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_bool (inLexique,  var_cas_shutdownhook,  var_cas_sdh,  GGS_string ("SHUTDOWNHOOK") COMMA_SOURCE_FILE_AT_LINE (95)) ;
          } break ;
        case 5 : {
          GGS_lbool  var_cas_eh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ERRORHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_eh) ;
          GGS_lstring  automatic_var_3 ;
          nt_description_ (inLexique, automatic_var_3) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_bool (inLexique,  var_cas_errorhook,  var_cas_eh,  GGS_string ("ERRORHOOK") COMMA_SOURCE_FILE_AT_LINE (99)) ;
          } break ;
        case 6 : {
          GGS_lbool  var_cas_preth ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_PRETASKHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_preth) ;
          GGS_lstring  automatic_var_4 ;
          nt_description_ (inLexique, automatic_var_4) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_bool (inLexique,  var_cas_pretaskhook,  var_cas_preth,  GGS_string ("PRETASKHOOK") COMMA_SOURCE_FILE_AT_LINE (103)) ;
          } break ;
        case 7 : {
          GGS_lbool  var_cas_posth ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_POSTTASKHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_posth) ;
          GGS_lstring  automatic_var_5 ;
          nt_description_ (inLexique, automatic_var_5) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_bool (inLexique,  var_cas_posttaskhook,  var_cas_posth,  GGS_string ("POSTTASKHOOK") COMMA_SOURCE_FILE_AT_LINE (107)) ;
          } break ;
        case 8 : {
          GGS_lbool  var_cas_proth ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_PROTECTIONHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_proth) ;
          GGS_lstring  automatic_var_6 ;
          nt_description_ (inLexique, automatic_var_6) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          if (((GGS_bool (inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (111)))).operator_isEqual (GGS_bool (false))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use PROTECTIONHOOK attribute in OS object") COMMA_SOURCE_FILE_AT_LINE (113)) ;
          }
          ::routine_set_bool (inLexique,  var_cas_protectionhook,  var_cas_proth,  GGS_string ("PROTECTIONHOOK") COMMA_SOURCE_FILE_AT_LINE (114)) ;
          } break ;
        case 9 : {
          if (((GGS_bool (inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (116)))).operator_isEqual (GGS_bool (false))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use SCALABILITYCLASS attribute in OS object") COMMA_SOURCE_FILE_AT_LINE (118)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SCALABILITYCLASS) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          if (((var_cas_scalabilityclass.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (120))).operator_isNotEqual (GGS_string (""))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("SCALABILITYCLASS already defined for OS object") COMMA_SOURCE_FILE_AT_LINE (122)) ;
          }
          switch (select_goil_obj_os_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SC1) COMMA_HERE) ;
              var_cas_scalabilityclass = GGS_lstring ::constructor_new (inLexique, GGS_string ("sc1"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SC2) COMMA_HERE) ;
              var_cas_scalabilityclass = GGS_lstring ::constructor_new (inLexique, GGS_string ("sc2"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 3 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SC3) COMMA_HERE) ;
              var_cas_scalabilityclass = GGS_lstring ::constructor_new (inLexique, GGS_string ("sc3"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 4 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SC4) COMMA_HERE) ;
              var_cas_scalabilityclass = GGS_lstring ::constructor_new (inLexique, GGS_string ("sc4"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 5 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_AUTO) COMMA_HERE) ;
              var_cas_scalabilityclass = GGS_lstring ::constructor_new (inLexique, GGS_string ("auto"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_7 ;
          nt_description_ (inLexique, automatic_var_7) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 10 : {
          if (((GGS_bool (inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (136)))).operator_isEqual (GGS_bool (false))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use STACKMONITORING attribute in OS object") COMMA_SOURCE_FILE_AT_LINE (138)) ;
          }
          GGS_lbool  var_cas_stackmon ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STACKMONITORING) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_stackmon) ;
          ::routine_set_bool (inLexique,  var_cas_stackmonitoring,  var_cas_stackmon,  GGS_string ("STACKMONITORING") COMMA_SOURCE_FILE_AT_LINE (141)) ;
          GGS_lstring  automatic_var_8 ;
          nt_description_ (inLexique, automatic_var_8) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 11 : {
          GGS_lbool  var_cas_ugsi ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_USEGETSERVICEID) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_ugsi) ;
          ::routine_set_bool (inLexique,  var_cas_usegetserviceid,  var_cas_ugsi,  GGS_string ("USEGETSERVICEID") COMMA_SOURCE_FILE_AT_LINE (146)) ;
          GGS_lstring  automatic_var_9 ;
          nt_description_ (inLexique, automatic_var_9) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 12 : {
          GGS_lbool  var_cas_upa ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_USEPARAMETERACCESS) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_upa) ;
          ::routine_set_bool (inLexique,  var_cas_useparameteraccess,  var_cas_upa,  GGS_string ("USEPARAMETERACCESS") COMMA_SOURCE_FILE_AT_LINE (151)) ;
          GGS_lstring  automatic_var_10 ;
          nt_description_ (inLexique, automatic_var_10) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 13 : {
          GGS_lbool  var_cas_urs ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_USERESSCHEDULER) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_urs) ;
          ::routine_set_bool (inLexique,  var_cas_useresscheduler,  var_cas_urs,  GGS_string ("USERESSCHEDULER") COMMA_SOURCE_FILE_AT_LINE (156)) ;
          GGS_lstring  automatic_var_11 ;
          nt_description_ (inLexique, automatic_var_11) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 14 : {
          GGS_lbool  var_cas_sc ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SYSTEM_5FCALL) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_boolean_ (inLexique, var_cas_sc) ;
          ::routine_set_bool (inLexique,  var_cas_systemcall,  var_cas_sc,  GGS_string ("SYSTEM_CALL") COMMA_SOURCE_FILE_AT_LINE (161)) ;
          GGS_lstring  automatic_var_12 ;
          nt_description_ (inLexique, automatic_var_12) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 15 : {
          GGS_lstring  var_cas_src ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_APP_5FSRC) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_a_string (var_cas_src) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
          GGS_lstring  automatic_var_13 ;
          nt_description_ (inLexique, automatic_var_13) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_checkFileExists (inLexique,  var_cas_src COMMA_SOURCE_FILE_AT_LINE (166)) ;
          var_cas_app_src._addAssign_operation (var_cas_src) ;
          } break ;
        case 16 : {
          GGS_lstring  var_cas_flag ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_CFLAGS) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_a_string (var_cas_flag) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
          GGS_lstring  automatic_var_14 ;
          nt_description_ (inLexique, automatic_var_14) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          var_cas_cflags._addAssign_operation (var_cas_flag) ;
          } break ;
        case 17 : {
          GGS_lstring  var_cas_flag ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ASFLAGS) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_a_string (var_cas_flag) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
          GGS_lstring  automatic_var_15 ;
          nt_description_ (inLexique, automatic_var_15) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          var_cas_asflags._addAssign_operation (var_cas_flag) ;
          } break ;
        case 18 : {
          GGS_lstring  var_cas_flag ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_LDFLAGS) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_a_string (var_cas_flag) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
          GGS_lstring  automatic_var_16 ;
          nt_description_ (inLexique, automatic_var_16) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          var_cas_ldflags._addAssign_operation (var_cas_flag) ;
          } break ;
        case 19 : {
          GGS_lstring  var_cas_an ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_APP_5FNAME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_a_string (var_cas_an) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
          GGS_lstring  automatic_var_17 ;
          nt_description_ (inLexique, automatic_var_17) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_lstring_if_empty (inLexique,  var_cas_app_name,  var_cas_an,  GGS_string ("APP_NAME") COMMA_SOURCE_FILE_AT_LINE (183)) ;
          } break ;
        case 20 : {
          GGS_lstring  var_cas_tbp ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRAMPOLINE_5FBASE_5FPATH) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_a_string (var_cas_tbp) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
          GGS_lstring  automatic_var_18 ;
          nt_description_ (inLexique, automatic_var_18) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_set_lstring_if_empty (inLexique,  var_cas_tpl_base_path,  var_cas_tbp,  GGS_string ("TRAMPOLINE_BASE_PATH") COMMA_SOURCE_FILE_AT_LINE (187)) ;
          } break ;
        case 21 : {
          GGS_trace  var_cas_t ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRACE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          switch (select_goil_obj_os_3 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
              GGS_trace_method  var_cas_m ;
              var_cas_m = GGS_trace_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              GGS_lstring  var_cas_f ;
              var_cas_f = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
              GGS_void  var_cas_void_obj ;
              var_cas_void_obj = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              GGS_basic_type  var_cas_tt ;
              var_cas_tt = var_cas_void_obj ;
              GGS_basic_type  var_cas_ti ;
              var_cas_ti = var_cas_void_obj ;
              GGS_basic_type  var_cas_tr ;
              var_cas_tr = var_cas_void_obj ;
              GGS_basic_type  var_cas_ta ;
              var_cas_ta = var_cas_void_obj ;
              GGS_basic_type  var_cas_tu ;
              var_cas_tu = var_cas_void_obj ;
              GGS_basic_type  var_cas_ds ;
              var_cas_ds = var_cas_void_obj ;
              { bool syntaxRepeat_4 = true ;
                while (syntaxRepeat_4) {
                  switch (select_repeat_goil_obj_os_4 (inLexique)) {
                    case 2 : {
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_METHOD) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      GGS_lstring  var_cas_file ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FILE) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_NAME) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      inLexique._assignFromAttribute_a_string (var_cas_file) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
                      ::routine_set_method (inLexique,  var_cas_m,  GGS_trace_file ::constructor_new (inLexique, GGS_location (inLexique), var_cas_file COMMA_HERE),  GGS_string ("NAME") COMMA_SOURCE_FILE_AT_LINE (207)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 3 : {
                      GGS_lstring  var_cas_fmt ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FORMAT) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      inLexique._assignFromAttribute_att_token (var_cas_fmt) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
                      ::routine_set_lstring_if_empty (inLexique,  var_cas_f,  var_cas_fmt,  GGS_string ("FORMAT") COMMA_SOURCE_FILE_AT_LINE (213)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 4 : {
                      GGS_lbool  var_cas_b ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRACE_5FTASK) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      nt_boolean_ (inLexique, var_cas_b) ;
                      ::routine_set_bool (inLexique,  var_cas_tt,  var_cas_b,  GGS_string ("TRACE_TASK") COMMA_SOURCE_FILE_AT_LINE (217)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 5 : {
                      GGS_lbool  var_cas_b ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRACE_5FISR) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      nt_boolean_ (inLexique, var_cas_b) ;
                      ::routine_set_bool (inLexique,  var_cas_ti,  var_cas_b,  GGS_string ("TRACE_ISR") COMMA_SOURCE_FILE_AT_LINE (221)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 6 : {
                      GGS_lbool  var_cas_b ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRACE_5FRESOURCE) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      nt_boolean_ (inLexique, var_cas_b) ;
                      ::routine_set_bool (inLexique,  var_cas_tr,  var_cas_b,  GGS_string ("TRACE_RESOURCE") COMMA_SOURCE_FILE_AT_LINE (225)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 7 : {
                      GGS_lbool  var_cas_b ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRACE_5FALARM) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      nt_boolean_ (inLexique, var_cas_b) ;
                      ::routine_set_bool (inLexique,  var_cas_ta,  var_cas_b,  GGS_string ("TRACE_ALARM") COMMA_SOURCE_FILE_AT_LINE (229)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 8 : {
                      GGS_lbool  var_cas_b ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRACE_5FUSER) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      nt_boolean_ (inLexique, var_cas_b) ;
                      ::routine_set_bool (inLexique,  var_cas_tu,  var_cas_b,  GGS_string ("TRACE_USER") COMMA_SOURCE_FILE_AT_LINE (233)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    case 9 : {
                      GGS_lbool  var_cas_b ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_DESCRIPTION) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
                      nt_boolean_ (inLexique, var_cas_b) ;
                      ::routine_set_bool (inLexique,  var_cas_ds,  var_cas_b,  GGS_string ("DESCRIPTION") COMMA_SOURCE_FILE_AT_LINE (237)) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
                      } break ;
                    default :
                      syntaxRepeat_4 = false ;
                      break ;
                  }
                }
              }
              if (((var_cas_f.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (239))).operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Missing FORMAT in TRACE") COMMA_SOURCE_FILE_AT_LINE (241)) ;
              }
              { const GGS_trace_method _var_7711 = var_cas_m ; // CAST instruction
                if (_var_7711.getPtr () != NULL) {
                  macroValidPointer (_var_7711.getPtr ()) ;
                  if (typeid (cPtr_trace_void) == typeid (* (_var_7711.getPtr ()))) {
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Missing METHOD in TRACE") COMMA_SOURCE_FILE_AT_LINE (245)) ;
                  }else{
                  }
                }
              }
              var_cas_t = GGS_trace_on ::constructor_new (inLexique, GGS_location (inLexique), var_cas_f, var_cas_m, var_cas_tt, var_cas_ti, var_cas_tr, var_cas_ta, var_cas_tu, var_cas_ds COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_t = GGS_trace_off ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          { const GGS_trace _var_8118 = var_cas_trace ; // CAST instruction
            if (_var_8118.getPtr () != NULL) {
              macroValidPointer (_var_8118.getPtr ()) ;
              if (typeid (cPtr_trace) == typeid (* (_var_8118.getPtr ()))) {
                var_cas_trace = var_cas_t ;
              }else{
                var_cas_t.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (265)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinition of TRACE") COMMA_SOURCE_FILE_AT_LINE (266)) ;
                var_cas_trace.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (266)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (267)) ;
              }
            }
          }
          } break ;
        case 22 : {
          nt_free_field_ (inLexique, var_cas_others) ;
          GGS_lstring  automatic_var_19 ;
          nt_description_ (inLexique, automatic_var_19) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
  GGS_lstring  var_cas_desc ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
  var_cas_os = GGS_os_obj ::constructor_new (inLexique, var_cas_desc, var_cas_status, var_cas_startuphook, var_cas_shutdownhook, var_cas_errorhook, var_cas_pretaskhook, var_cas_posttaskhook, var_cas_protectionhook, var_cas_scalabilityclass, var_cas_stackmonitoring, var_cas_usegetserviceid, var_cas_useparameteraccess, var_cas_useresscheduler, var_cas_systemcall, var_cas_app_src, var_cas_cflags, var_cas_asflags, var_cas_ldflags, var_cas_app_name, var_cas_tpl_base_path, var_cas_trace, var_cas_others COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

