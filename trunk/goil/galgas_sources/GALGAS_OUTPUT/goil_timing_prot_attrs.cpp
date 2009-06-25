//---------------------------------------------------------------------------*
//                                                                           *
//                    File 'goil_timing_prot_attrs.cpp'                      *
//                        Generated by version 1.8.5                         *
//                      june 19th, 2009, at 17h48'14"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 515
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_timing_prot_attrs.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_timing_prot_attrs.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'timing_prot_attrs'            *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_timing_prot_attrs::
pr_timing_prot_attrs_goil_timing_prot_attrs_20_24_ (goil_lexique & inLexique,
                                GGS_basic_type  &var_cas_exe_budget,
                                GGS_basic_type  &var_cas_exe_time,
                                GGS_basic_type  &var_cas_count_limit,
                                GGS_basic_type  &var_cas_time_frame,
                                GGS_basic_type  &var_cas_os_it_lock,
                                GGS_basic_type  &var_cas_all_it_lock,
                                GGS_rezlock_map  &var_cas_rezlocks) {
  var_cas_exe_budget = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  var_cas_exe_time = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  var_cas_count_limit = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  var_cas_time_frame = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  var_cas_os_it_lock = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  var_cas_all_it_lock = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  var_cas_rezlocks = GGS_rezlock_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_timing_prot_attrs_0 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_eb ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_EXECUTIONBUDGET) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_eb) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_1413 = var_cas_exe_budget ; // CAST instruction
            if (_var_1413.getPtr () != NULL) {
              macroValidPointer (_var_1413.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_1413.getPtr ()))) {
                var_cas_exe_budget = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_eb.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (41)) COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EXECUTIONBUDGET already declared") COMMA_SOURCE_FILE_AT_LINE (44)) ;
                var_cas_exe_budget.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (44)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (45)) ;
              }
            }
          }
          } break ;
        case 3 : {
          GGS_luint64  var_cas_et ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_EXECUTIONTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_et) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_1770 = var_cas_exe_time ; // CAST instruction
            if (_var_1770.getPtr () != NULL) {
              macroValidPointer (_var_1770.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_1770.getPtr ()))) {
                var_cas_exe_time = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_et.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (50)) COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EXECUTIONTIME already declared") COMMA_SOURCE_FILE_AT_LINE (53)) ;
                var_cas_exe_time.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (53)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (54)) ;
              }
            }
          }
          } break ;
        case 4 : {
          GGS_luint64  var_cas_cl ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COUNTLIMIT) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_cl) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_2137 = var_cas_count_limit ; // CAST instruction
            if (_var_2137.getPtr () != NULL) {
              macroValidPointer (_var_2137.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_2137.getPtr ()))) {
                var_cas_count_limit = GGS_uint32_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_cl.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (59)).reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (59)) COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("COUNTLIMIT already declared") COMMA_SOURCE_FILE_AT_LINE (62)) ;
                var_cas_count_limit.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (62)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (63)) ;
              }
            }
          }
          } break ;
        case 5 : {
          GGS_luint64  var_cas_tf ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TIMEFRAME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_tf) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_2492 = var_cas_time_frame ; // CAST instruction
            if (_var_2492.getPtr () != NULL) {
              macroValidPointer (_var_2492.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_2492.getPtr ()))) {
                var_cas_time_frame = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_tf.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (68)) COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TIMEFRAME already declared") COMMA_SOURCE_FILE_AT_LINE (71)) ;
                var_cas_time_frame.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (71)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (72)) ;
              }
            }
          }
          } break ;
        case 6 : {
          GGS_luint64  var_cas_moilt ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MAXOSINTERRUPTLOCKTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_moilt) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_2882 = var_cas_os_it_lock ; // CAST instruction
            if (_var_2882.getPtr () != NULL) {
              macroValidPointer (_var_2882.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_2882.getPtr ()))) {
                var_cas_os_it_lock = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_moilt.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (77)) COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXOSINTERRUPTLOCKTIME already declared") COMMA_SOURCE_FILE_AT_LINE (80)) ;
                var_cas_os_it_lock.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (80)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (81)) ;
              }
            }
          }
          } break ;
        case 7 : {
          GGS_luint64  var_cas_maitl ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MAXALLINTERRUPTLOCKTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_maitl) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_3277 = var_cas_all_it_lock ; // CAST instruction
            if (_var_3277.getPtr () != NULL) {
              macroValidPointer (_var_3277.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_3277.getPtr ()))) {
                var_cas_all_it_lock = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_maitl.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (86)) COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXALLINTERRUPTLOCKTIME already declared") COMMA_SOURCE_FILE_AT_LINE (89)) ;
                var_cas_all_it_lock.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (89)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (90)) ;
              }
            }
          }
          } break ;
        case 8 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_LOCKINGTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESOURCELOCK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
          GGS_lstring  var_cas_rez ;
          var_cas_rez = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
          GGS_basic_type  var_cas_lock ;
          var_cas_lock = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
          { bool syntaxRepeat_1 = true ;
            while (syntaxRepeat_1) {
              switch (select_repeat_goil_timing_prot_attrs_1 (inLexique)) {
                case 2 : {
                  GGS_lstring  var_cas_r ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESOURCE) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
                  inLexique.assignFromAttribute_att_token (var_cas_r) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  if (((var_cas_rez.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (99))).operator_isNotEqual (GGS_string (""))).isBuiltAndTrue ()) {
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("RESOURCE already declared") COMMA_SOURCE_FILE_AT_LINE (101)) ;
                    var_cas_rez.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (102)) ;
                  }else{
                    var_cas_rez = var_cas_r ;
                  }
                  } break ;
                case 3 : {
                  GGS_luint64  var_cas_mrlt ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MAXRESOURCELOCKTIME) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
                  inLexique.assignFromAttribute_integerNumber (var_cas_mrlt) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  { const GGS_basic_type _var_4164 = var_cas_lock ; // CAST instruction
                    if (_var_4164.getPtr () != NULL) {
                      macroValidPointer (_var_4164.getPtr ()) ;
                      if (typeid (cPtr_void) == typeid (* (_var_4164.getPtr ()))) {
                        var_cas_lock = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_mrlt.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (109)) COMMA_HERE) ;
                      }else{
                        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXRESOURCELOCKTIME already declared") COMMA_SOURCE_FILE_AT_LINE (112)) ;
                        var_cas_lock.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (112)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (113)) ;
                      }
                    }
                  }
                  } break ;
                default :
                  syntaxRepeat_1 = false ;
                  break ;
              }
            }
          }
          if (((var_cas_rez.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (115))).operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("No RESOURCE declared for LOCKINGTIME") COMMA_SOURCE_FILE_AT_LINE (117)) ;
          }
          GGS_uint64  var_cas_l ;
          var_cas_l = GGS_uint64 (0U) ;
          { const GGS_basic_type _var_4513 = var_cas_lock ; // CAST instruction
            if (_var_4513.getPtr () != NULL) {
              macroValidPointer (_var_4513.getPtr ()) ;
              if (typeid (cPtr_uint64_class) == typeid (* (_var_4513.getPtr ()))) {
                const GGS_uint64_class var_cas_lu (_var_4513.getPtr ()) ;
                var_cas_l = var_cas_lu.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (121)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("No MAXRESOURCELOCKTIME declared for LOCKINGTIME") COMMA_SOURCE_FILE_AT_LINE (124)) ;
              }
            }
          }
          var_cas_rezlocks.modifier_put (inLexique, var_cas_rez, var_cas_l COMMA_SOURCE_FILE_AT_LINE (125)) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  { const GGS_basic_type _var_4682 = var_cas_time_frame ; // CAST instruction
    if (_var_4682.getPtr () != NULL) {
      macroValidPointer (_var_4682.getPtr ()) ;
      if (typeid (cPtr_void) == typeid (* (_var_4682.getPtr ()))) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TIMEFRAME not declared") COMMA_SOURCE_FILE_AT_LINE (129)) ;
      }else{
      }
    }
  }
  { const GGS_basic_type _var_4791 = var_cas_os_it_lock ; // CAST instruction
    if (_var_4791.getPtr () != NULL) {
      macroValidPointer (_var_4791.getPtr ()) ;
      if (typeid (cPtr_void) == typeid (* (_var_4791.getPtr ()))) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXOSINTERRUPTLOCKTIME not declared") COMMA_SOURCE_FILE_AT_LINE (130)) ;
      }else{
      }
    }
  }
  { const GGS_basic_type _var_4901 = var_cas_all_it_lock ; // CAST instruction
    if (_var_4901.getPtr () != NULL) {
      macroValidPointer (_var_4901.getPtr ()) ;
      if (typeid (cPtr_void) == typeid (* (_var_4901.getPtr ()))) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXALLINTERRUPTLOCKTIME not declared") COMMA_SOURCE_FILE_AT_LINE (131)) ;
      }else{
      }
    }
  }
}

//---------------------------------------------------------------------------*

