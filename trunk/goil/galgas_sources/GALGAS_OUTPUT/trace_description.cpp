//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'trace_description.cpp'                        *
//                        Generated by version 1.8.3                         *
//                       may 29th, 2009, at 11h49'40"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 491
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "trace_description.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "trace_description.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "generate_description"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_description (C_Compiler & _inLexique,
                                const GGS_root_obj   var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_description at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_trace  var_cas_tr ;
  var_cas_tr = var_cas_cpu.reader_os (_inLexique COMMA_SOURCE_FILE_AT_LINE (34)).reader_trace (_inLexique COMMA_SOURCE_FILE_AT_LINE (34)) ;
  { const GGS_trace _var_2844 = var_cas_tr ; // CAST instruction
    if (_var_2844.getPtr () != NULL) {
      macroValidPointer (_var_2844.getPtr ()) ;
      if (typeid (cPtr_trace_on) == typeid (* (_var_2844.getPtr ()))) {
        const GGS_trace_on var_cas_to (_var_2844.getPtr ()) ;
        if ((function_get_bool (_inLexique, var_cas_to.reader_desc (_inLexique COMMA_SOURCE_FILE_AT_LINE (37)), GGS_bool (false) COMMA_SOURCE_FILE_AT_LINE (37))).isBuiltAndTrue ()) {
          GGS_string var_cas_res ;
          var_cas_res = GGS_string ("<\?xml version=\"1.0\" encoding=\"ISO-8859-1\"\?>\n") ;
          var_cas_res.appendCString ("<app name=\"") ;
          var_cas_res._dotAssign_operation (function_project_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (39)).reader_lastPathComponent (_inLexique COMMA_SOURCE_FILE_AT_LINE (39))) ;
          var_cas_res.appendCString ("\">\n") ;
          GGS_tasks_by_type  var_cas_stasks ;
          var_cas_stasks = GGS_tasks_by_type ::constructor_emptySortedList () ;
          {
            GGS_task_map::cEnumerator enumerator_1019 (var_cas_cpu.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (43)), true) ;
            const GGS_task_map::cElement * operand_1019 = NULL ;
            while (((operand_1019 = enumerator_1019.nextObject ()))) {
              macroValidPointer (operand_1019) ;
              if (((operand_1019->mInfo.task.reader_events (_inLexique COMMA_SOURCE_FILE_AT_LINE (44)).reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (44)))._operator_strictSup (GGS_uint (0U))).isBuiltAndTrue ()) {
                var_cas_stasks._addAssign_operation (GGS_uint (0U), operand_1019->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (45))) ;
              }else{
                var_cas_stasks._addAssign_operation (GGS_uint (1U), operand_1019->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (47))) ;
              }
            }
          }
          GGS_uint  var_cas_id ;
          var_cas_id = GGS_uint (0U) ;
          if ((function_get_bool (_inLexique, var_cas_to.reader_trace_task (_inLexique COMMA_SOURCE_FILE_AT_LINE (52)), GGS_bool (true) COMMA_SOURCE_FILE_AT_LINE (52))).isBuiltAndTrue ()) {
            var_cas_res.appendCString ("<tasks>\n") ;
            GGS_tasks_by_type  var_cas_stasks ;
            var_cas_stasks = GGS_tasks_by_type ::constructor_emptySortedList () ;
            {
              GGS_task_map::cEnumerator enumerator_1424 (var_cas_cpu.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (56)), true) ;
              const GGS_task_map::cElement * operand_1424 = NULL ;
              while (((operand_1424 = enumerator_1424.nextObject ()))) {
                macroValidPointer (operand_1424) ;
                if (((operand_1424->mInfo.task.reader_events (_inLexique COMMA_SOURCE_FILE_AT_LINE (57)).reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (57)))._operator_strictSup (GGS_uint (0U))).isBuiltAndTrue ()) {
                  var_cas_stasks._addAssign_operation (GGS_uint (0U), operand_1424->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (58))) ;
                }else{
                  var_cas_stasks._addAssign_operation (GGS_uint (1U), operand_1424->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (60))) ;
                }
              }
            }
            {
              GGS_tasks_by_type::cEnumerator enumerator_1647 (var_cas_stasks, true) ;
              const GGS_tasks_by_type::cElement * operand_1647 = NULL ;
              while (((operand_1647 = enumerator_1647.nextObject ()))) {
                macroValidPointer (operand_1647) ;
                var_cas_res.appendCString ("  <task name=\"") ;
                var_cas_res._dotAssign_operation (operand_1647->name) ;
                var_cas_res.appendCString ("\" id=\"") ;
                var_cas_res._dotAssign_operation (var_cas_id.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (65))) ;
                var_cas_res.appendCString ("\"/>\n") ;
                var_cas_id._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (66)) ;
              }
            }
            var_cas_res.appendCString ("</tasks>\n") ;
          }
          var_cas_id = var_cas_stasks.reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (71)) ;
          if ((function_get_bool (_inLexique, var_cas_to.reader_trace_isr (_inLexique COMMA_SOURCE_FILE_AT_LINE (72)), GGS_bool (true) COMMA_SOURCE_FILE_AT_LINE (72))).isBuiltAndTrue ()) {
            var_cas_res.appendCString ("<isrs>\n") ;
            {
              GGS_isr_map::cEnumerator enumerator_1928 (var_cas_cpu.reader_isrs (_inLexique COMMA_SOURCE_FILE_AT_LINE (74)), true) ;
              const GGS_isr_map::cElement * operand_1928 = NULL ;
              while (((operand_1928 = enumerator_1928.nextObject ()))) {
                macroValidPointer (operand_1928) ;
                var_cas_res.appendCString ("  <isr name=\"") ;
                var_cas_res._dotAssign_operation (operand_1928->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (75))) ;
                var_cas_res.appendCString ("\" id=\"") ;
                var_cas_res._dotAssign_operation (var_cas_id.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (75))) ;
                var_cas_res.appendCString ("\"/>\n") ;
                var_cas_id._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (76)) ;
              }
            }
            var_cas_res.appendCString ("</isrs>\n") ;
          }
          if ((function_get_bool (_inLexique, var_cas_to.reader_trace_resource (_inLexique COMMA_SOURCE_FILE_AT_LINE (81)), GGS_bool (true) COMMA_SOURCE_FILE_AT_LINE (81))).isBuiltAndTrue ()) {
            var_cas_id = GGS_uint (0U) ;
            var_cas_res.appendCString ("<resources>\n") ;
            {
              GGS_resource_map::cEnumerator enumerator_2222 (var_cas_cpu.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (84)), true) ;
              const GGS_resource_map::cElement * operand_2222 = NULL ;
              while (((operand_2222 = enumerator_2222.nextObject ()))) {
                macroValidPointer (operand_2222) ;
                var_cas_res.appendCString ("  <resource name=\"") ;
                var_cas_res._dotAssign_operation (operand_2222->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (85))) ;
                var_cas_res.appendCString ("\" id=\"") ;
                var_cas_res._dotAssign_operation (var_cas_id.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (85))) ;
                var_cas_res.appendCString ("\"/>\n") ;
                var_cas_id._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (86)) ;
              }
            }
            var_cas_res.appendCString ("</resources>\n") ;
          }
          if ((function_get_bool (_inLexique, var_cas_to.reader_trace_alarm (_inLexique COMMA_SOURCE_FILE_AT_LINE (91)), GGS_bool (true) COMMA_SOURCE_FILE_AT_LINE (91))).isBuiltAndTrue ()) {
            var_cas_id = GGS_uint (0U) ;
            var_cas_res.appendCString ("<alarms>\n") ;
            {
              GGS_alarm_map::cEnumerator enumerator_2521 (var_cas_cpu.reader_alarms (_inLexique COMMA_SOURCE_FILE_AT_LINE (94)), true) ;
              const GGS_alarm_map::cElement * operand_2521 = NULL ;
              while (((operand_2521 = enumerator_2521.nextObject ()))) {
                macroValidPointer (operand_2521) ;
                var_cas_res.appendCString ("  <alarm name=\"") ;
                var_cas_res._dotAssign_operation (operand_2521->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (95))) ;
                var_cas_res.appendCString ("\" id=\"") ;
                var_cas_res._dotAssign_operation (var_cas_id.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (95))) ;
                var_cas_res.appendCString ("\"/>\n") ;
                var_cas_id._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (96)) ;
              }
            }
            var_cas_res.appendCString ("</alarms>\n") ;
          }
          var_cas_res.appendCString ("</app>\n") ;
          GGS_string var_cas_desc_file_name ;
          var_cas_desc_file_name = (function_project_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (103)))._operator_concat (GGS_string (".desc")) ;
          const GGS_string _temp_2804 = var_cas_res ;
          if (_temp_2804.isBuilt ()) {
            _temp_2804 (HERE)->method_writeToFile (_inLexique, var_cas_desc_file_name COMMA_SOURCE_FILE_AT_LINE (104)) ;
          }
        }
      }else{
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_description\n") ;
  #endif
}

//---------------------------------------------------------------------------*

