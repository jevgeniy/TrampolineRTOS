//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'tasks_verif.cpp'                           *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h44'54"                        *
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
#include "tasks_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "tasks_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "tasks_well_formed"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_tasks_well_formed (C_Compiler & inLexique,
                                const GGS_task_map   var_cas_tasks COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_tasks_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_task_map::cEnumerator enumerator_861 (var_cas_tasks, true) ;
    const GGS_task_map::cElement * operand_861 = NULL ;
    while (((operand_861 = enumerator_861.nextObject ()))) {
      macroValidPointer (operand_861) ;
      { const GGS_basic_type _var_1057 = operand_861->mInfo.task.reader_priority (inLexique COMMA_SOURCE_FILE_AT_LINE (48)) ; // CAST instruction
        if (_var_1057.getPtr () != NULL) {
          macroValidPointer (_var_1057.getPtr ()) ;
          if (typeid (cPtr_void) == typeid (* (_var_1057.getPtr ()))) {
            operand_861->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("PRIORITY attribute not defined for TASK ")).operator_concat (operand_861->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (50))) COMMA_SOURCE_FILE_AT_LINE (51)) ;
          }else{
          }
        }
      }
      { const GGS_basic_type _var_1690 = operand_861->mInfo.task.reader_activation (inLexique COMMA_SOURCE_FILE_AT_LINE (54)) ; // CAST instruction
        if (_var_1690.getPtr () != NULL) {
          macroValidPointer (_var_1690.getPtr ()) ;
          if (typeid (cPtr_void) == typeid (* (_var_1690.getPtr ()))) {
            operand_861->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("ACTIVATION attribute not defined for TASK ")).operator_concat (operand_861->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (56))) COMMA_SOURCE_FILE_AT_LINE (57)) ;
          }else if (typeid (cPtr_uint32_class) == typeid (* (_var_1690.getPtr ()))) {
            const GGS_uint32_class var_cas_ui (_var_1690.getPtr ()) ;
            GGS_lstringlist  var_cas_defined_events ;
            var_cas_defined_events = operand_861->mInfo.task.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (58)) ;
            if ((((var_cas_defined_events.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (59))).operator_strictSup (GGS_uint (0U))).operator_and ((var_cas_ui.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (59))).operator_strictSup (GGS_uint (1U)))).isBuiltAndTrue ()) {
              operand_861->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("ACTIVATION attribute for extended task ")).operator_concat (operand_861->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (60)))).operator_concat (GGS_string (" should be set to 1")) COMMA_SOURCE_FILE_AT_LINE (61)) ;
              var_cas_ui.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (61)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("ACTIVATION attribute set to ")).operator_concat (var_cas_ui.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (61)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (61)))).operator_concat (GGS_string (" here")) COMMA_SOURCE_FILE_AT_LINE (62)) ;
            }
          }else{
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("Internal error, wrong datatype for ACTIVATION in task ")).operator_concat (operand_861->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (64))) COMMA_SOURCE_FILE_AT_LINE (65)) ;
          }
        }
      }
      if (((operand_861->mInfo.task.reader_schedule (inLexique COMMA_SOURCE_FILE_AT_LINE (67)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (67))).operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
        operand_861->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("SCHEDULE attribute not defined for TASK ")).operator_concat (operand_861->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (68))) COMMA_SOURCE_FILE_AT_LINE (69)) ;
      }
      { const GGS_task_autostart_obj _var_2012 = operand_861->mInfo.task.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (71)) ; // CAST instruction
        if (_var_2012.getPtr () != NULL) {
          macroValidPointer (_var_2012.getPtr ()) ;
          if (typeid (cPtr_task_autostart_void) == typeid (* (_var_2012.getPtr ()))) {
            operand_861->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("AUTOSTART attribute not defined for TASK ")).operator_concat (operand_861->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (73))) COMMA_SOURCE_FILE_AT_LINE (74)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_tasks_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*

