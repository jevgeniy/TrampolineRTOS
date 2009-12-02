//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_target_posix.cpp'                        *
//                        Generated by version 1.9.6                         *
//                    november 30th, 2009, at 10h44'45"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 621
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_target_posix.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_target_posix.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "generate_target_posix"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_target_posix (C_Compiler & inLexique,
                                GGS_lstring   var_cas_name,
                                GGS_ident_map   var_cas_others,
                                GGS_oil_obj   var_cas_exe,
                                GGS_string & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_target_posix at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$STACK_ZONE$"),  (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (15))).operator_concat (GGS_string ("_stack_zone")) COMMA_SOURCE_FILE_AT_LINE (15)) ;
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$STACK$"),  (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (16))).operator_concat (GGS_string ("_stack")) COMMA_SOURCE_FILE_AT_LINE (16)) ;
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$EXEC_ALL_CONTEXT$"),  (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (17))).operator_concat (GGS_string ("_int_context")) COMMA_SOURCE_FILE_AT_LINE (17)) ;
  GGS_uint  var_cas_stack_size ;
  ::routine_additional_int_key_required (inLexique,  GGS_string ("STACKSIZE"),  var_cas_others,  var_cas_name,  var_cas_stack_size COMMA_SOURCE_FILE_AT_LINE (20)) ;
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$STACK_SIZE$"),  var_cas_stack_size.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (21)) COMMA_SOURCE_FILE_AT_LINE (21)) ;
  { const GGS_oil_obj _var_984 = var_cas_exe ; // CAST instruction
    if (_var_984.getPtr () != NULL) {
      macroValidPointer (_var_984.getPtr ()) ;
      if (typeid (cPtr_isr_obj) == typeid (* (_var_984.getPtr ()))) {
        GGS_string var_cas_sig ;
        ::routine_additional_string_key_required (inLexique,  GGS_string ("SOURCE"),  var_cas_others,  var_cas_name,  var_cas_sig COMMA_SOURCE_FILE_AT_LINE (28)) ;
      }else{
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_target_posix\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "generate_isr_posix"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_posix (C_Compiler & inLexique,
                                const GGS_isr_map   var_cas_isrs,
                                GGS_string & var_cas_code COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_isr_posix at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result = GGS_string ("") ;
  GGS_bool var_cas_first = GGS_bool (true) ;
  GGS_isr_list  var_cas_list_isr = GGS_isr_list ::constructor_emptySortedList () ;
  const GGS_bool cond_2034 = (gOption_goil_5F_options_posix_5F_it.reader_value ()).operator_not () ;
  if (cond_2034.isBuiltAndTrue ()) {
    {
      GGS_isr_map::cEnumerator enumerator_1248 (var_cas_isrs, true) ;
      const GGS_isr_map::cElement * operand_1248 = NULL ;
      while (((operand_1248 = enumerator_1248.nextObject ()))) {
        macroValidPointer (operand_1248) ;
        var_cas_list_isr.addAssign_operation (operand_1248->mKey, operand_1248->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (43))) ;
      }
    }
    {
      GGS_isr_list::cEnumerator enumerator_1366 (var_cas_list_isr, true) ;
      const GGS_isr_list::cElement * operand_1366 = NULL ;
      while (((operand_1366 = enumerator_1366.nextObject ()))) {
        macroValidPointer (operand_1366) ;
        GGS_isr_obj  var_cas_isr ;
        const GGS_isr_map  temp_1427 = var_cas_isrs ;
        if (temp_1427.isBuilt ()) {
          temp_1427 (HERE)->method_get (inLexique, operand_1366->key, var_cas_isr COMMA_SOURCE_FILE_AT_LINE (48)) ;
        }
        const GGS_bool cond_1495 = (var_cas_first).operator_not () ;
        if (cond_1495.isBuiltAndTrue ()) {
          var_cas_result.appendCString (",\n") ;
        }
        var_cas_first = GGS_bool (false) ;
        GGS_string var_cas_key = GGS_string ("SOURCE") ;
        GGS_ident_map  var_cas_others = var_cas_isr.reader_other_fields (inLexique COMMA_SOURCE_FILE_AT_LINE (53)) ;
        const GGS_bool cond_1943 = var_cas_others.reader_hasKey (var_cas_key) ;
        if (cond_1943.isBuiltAndTrue ()) {
          GGS_basic_type  var_cas_value ;
          const GGS_ident_map  temp_1692 = var_cas_others ;
          if (temp_1692.isBuilt ()) {
            temp_1692 (HERE)->method_get (inLexique, GGS_lstring ::constructor_new (inLexique, var_cas_key, GGS_location (inLexique) COMMA_HERE), var_cas_value COMMA_SOURCE_FILE_AT_LINE (57)) ;
          }
          { const GGS_basic_type _var_1925 = var_cas_value ; // CAST instruction
            if (_var_1925.getPtr () != NULL) {
              macroValidPointer (_var_1925.getPtr ()) ;
              if (typeid (cPtr_string_class) == typeid (* (_var_1925.getPtr ()))) {
                const GGS_string_class var_cas_s (_var_1925.getPtr ()) ;
                var_cas_result = ((var_cas_result).operator_concat (GGS_string ("\t"))).operator_concat (var_cas_s.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (60))) ;
              }else{
                operand_1366->key.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (var_cas_key).operator_concat (GGS_string (" should be a string")) COMMA_SOURCE_FILE_AT_LINE (63)) ;
              }
            }
          }
        }else if (cond_1943.isBuiltAndFalse ()) {
          operand_1366->key.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("no ")).operator_concat (var_cas_key)).operator_concat (GGS_string (" specified")) COMMA_SOURCE_FILE_AT_LINE (66)) ;
        }
      }
    }
  }
  var_cas_code = var_cas_code.reader_stringByReplacingStringByString (inLexique, GGS_string ("$ISR_SIGNAL_LIST$"), var_cas_result COMMA_SOURCE_FILE_AT_LINE (69)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_isr_posix\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "generate_counter_posix"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_posix (C_Compiler & inLexique,
                                const GGS_counter_map   var_cas_counters,
                                GGS_string & var_cas_code COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_counter_posix at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result = GGS_string ("") ;
  {
    GGS_counter_map::cEnumerator enumerator_2252 (var_cas_counters, true) ;
    const GGS_counter_map::cElement * operand_2252 = NULL ;
    while (((operand_2252 = enumerator_2252.nextObject ()))) {
      macroValidPointer (operand_2252) ;
      { const GGS_counter_type _var_2545 = operand_2252->mInfo.counter.reader_type (inLexique COMMA_SOURCE_FILE_AT_LINE (78)) ; // CAST instruction
        if (_var_2545.getPtr () != NULL) {
          macroValidPointer (_var_2545.getPtr ()) ;
          if (typeid (cPtr_software_counter) == typeid (* (_var_2545.getPtr ()))) {
          }else{
            GGS_string var_cas_tmp = function_template_string (inLexique, GGS_string ("code"), GGS_string ("counter_list_specific") COMMA_SOURCE_FILE_AT_LINE (81)) ;
            ::routine_doReplace (inLexique,  var_cas_tmp,  GGS_string ("$COUNTER$"),  (operand_2252->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (82))).operator_concat (GGS_string ("_counter_desc")) COMMA_SOURCE_FILE_AT_LINE (82)) ;
            var_cas_result.dotAssign_operation (var_cas_tmp) ;
          }
        }
      }
    }
  }
  ::routine_doReplace (inLexique,  var_cas_code,  GGS_string ("$COUNTER_LIST$"),  var_cas_result COMMA_SOURCE_FILE_AT_LINE (87)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_counter_posix\n") ;
  #endif
}

//---------------------------------------------------------------------------*

