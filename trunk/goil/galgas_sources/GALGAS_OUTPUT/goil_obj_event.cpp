//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_event.cpp'                          *
//                       Generated by version 1.9.10                         *
//                      april 9th, 2010, at 10h18'13"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 688
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_event.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_event.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'event'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_event::rule_goil_5F_obj_5F_event_event_i0_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_event_map  &var_cas_events) {
  GGS_event_obj  var_cas_event ;
  GGS_lstring  var_cas_event_name ;
  GGS_event_mask_obj  var_cas_mask ;
  GGS_lstring  var_cas_desc ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_EVENT) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_5F_token (var_cas_event_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  const GGS_bool cond_1145 = var_cas_events.reader_hasKey (var_cas_event_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (53))) ;
  if (cond_1145.isBuiltAndTrue ()) {
    var_cas_events.modifier_del (inLexique, var_cas_event_name, var_cas_event COMMA_SOURCE_FILE_AT_LINE (54)) ;
    var_cas_mask = var_cas_event.reader_mask (inLexique COMMA_SOURCE_FILE_AT_LINE (55)) ;
    var_cas_desc = var_cas_event.reader_desc (inLexique COMMA_SOURCE_FILE_AT_LINE (56)) ;
  }else if (cond_1145.isBuiltAndFalse ()) {
    var_cas_mask = GGS_event_mask_void_obj ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    var_cas_desc = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
    var_cas_event = GGS_event_obj ::constructor_new (inLexique, var_cas_desc, var_cas_mask COMMA_HERE) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  nt_event_5F_attributes_ (inLexique, var_cas_mask) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
  var_cas_event = GGS_event_obj ::constructor_new (inLexique, var_cas_desc, var_cas_mask COMMA_HERE) ;
  var_cas_events.modifier_put (inLexique, var_cas_event_name, var_cas_event COMMA_SOURCE_FILE_AT_LINE (69)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of production rule 'event_attributes'            *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_event::rule_goil_5F_obj_5F_event_event_5F_attributes_i1_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_event_mask_obj  &var_cas_mask) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_event_0 (inLexique)) {
        case 2 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_MASK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_event_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_HERE) ;
              { const GGS_event_mask_obj _var_1928 = var_cas_mask ; // CAST instruction
                if (_var_1928.getPtr () != NULL) {
                  macroValidPointer (_var_1928.getPtr ()) ;
                  if (typeid (cPtr_event_mask_void_obj) == typeid (* (_var_1928.getPtr ()))) {
                    var_cas_mask = GGS_event_mask_auto_obj ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
                  }else{
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MASK attribute already defined for this EVENT") COMMA_SOURCE_FILE_AT_LINE (85)) ;
                    var_cas_mask.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (85)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (86)) ;
                  }
                }
              }
              } break ;
            case 2 : {
              GGS_luint64  var_cas_mask_value ;
              inLexique.assignFromAttribute_integerNumber (var_cas_mask_value) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
              { const GGS_event_mask_obj _var_3045 = var_cas_mask ; // CAST instruction
                if (_var_3045.getPtr () != NULL) {
                  macroValidPointer (_var_3045.getPtr ()) ;
                  if (typeid (cPtr_event_mask_void_obj) == typeid (* (_var_3045.getPtr ()))) {
                    var_cas_mask = GGS_event_mask_user_obj ::constructor_new (inLexique, GGS_location (inLexique), var_cas_mask_value COMMA_HERE) ;
                    const GGS_bool cond_2325 = (var_cas_mask_value.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (93))).operator_strictSup (GGS_uint ::constructor_max (inLexique COMMA_HERE).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (93))) ;
                    if (cond_2325.isBuiltAndTrue ()) {
                      GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MASK attribute should be a 32 bits integer") COMMA_SOURCE_FILE_AT_LINE (95)) ;
                    }else if (cond_2325.isBuiltAndFalse ()) {
                      GGS_uint  var_cas_nbbits = GGS_uint (0U) ;
                      GGS_uint64  var_cas_pof2 = GGS_uint64 (1ULL) ;
                      GGS_uint _variant_2672 = GGS_uint (32U) ;
                      GGS_bool _condition_2672 (_variant_2672.isBuilt (), true) ;
                      while (_condition_2672.isBuiltAndTrue ()) {
                        _condition_2672 = (var_cas_pof2).operator_strictInf (GGS_uint ::constructor_max (inLexique COMMA_HERE).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (99))) ;
                        if (_condition_2672.isBuiltAndTrue ()) {
                          if (_variant_2672.uintValue () == 0) {
                            inLexique.onTheFlyRunTimeError ("loop variant error" COMMA_SOURCE_FILE_AT_LINE (104)) ;
                            _condition_2672 = GGS_bool (false) ;
                          }else{
                            _variant_2672.decrement_operation (inLexique COMMA_HERE) ;
                            const GGS_bool cond_2605 = ((var_cas_pof2).operator_and (var_cas_mask_value.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (100)))).operator_isNotEqual (GGS_uint64 (0ULL)) ;
                            if (cond_2605.isBuiltAndTrue ()) {
                              var_cas_nbbits.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (101)) ;
                            }
                            var_cas_pof2 = var_cas_pof2.left_shift_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (103)) ;
                          }
                        }
                      }
                      const GGS_bool cond_2813 = (var_cas_nbbits).operator_strictSup (GGS_uint (1U)) ;
                      if (cond_2813.isBuiltAndTrue ()) {
                        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, GGS_string ("MASK attribute uses more than 1 bit") COMMA_SOURCE_FILE_AT_LINE (106)) ;
                      }
                    }
                  }else{
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MASK attribute already defined for this EVENT") COMMA_SOURCE_FILE_AT_LINE (111)) ;
                    var_cas_mask.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (111)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (112)) ;
                  }
                }
              }
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_3100_0 ;
          nt_description_ (inLexique, automatic_var_3100_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

