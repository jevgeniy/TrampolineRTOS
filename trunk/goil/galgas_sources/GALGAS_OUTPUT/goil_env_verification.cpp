//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_env_verification.cpp'                      *
//                       Generated by version 1.9.10                         *
//                      april 9th, 2010, at 10h17'47"                        *
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
#include "goil_env_verification.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_env_verification.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "getAbsoluteSourceFilePath"            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_getAbsoluteSourceFilePath (C_Compiler & inLexique,
                                const GGS_string  var_cas_fileName,
                                GGS_string & var_cas_absoluteFilePath COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_getAbsoluteSourceFilePath at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_sourceFilePath = GGS_string::constructor_stringWithSourceFilePath (inLexique COMMA_HERE).reader_stringByDeletingLastPathComponent () ;
  const GGS_bool cond_966 = (var_cas_sourceFilePath).operator_isEqual (GGS_string ("")) ;
  if (cond_966.isBuiltAndTrue ()) {
    const GGS_bool cond_956 = (GGS_string::constructor_stringWithSourceFilePath (inLexique COMMA_HERE).reader_firstCharacterOrNul ()).operator_isNotEqual (GGS_char (TO_UNICODE ('/'))) ;
    if (cond_956.isBuiltAndTrue ()) {
      var_cas_sourceFilePath = GGS_string (".") ;
    }
  }
  var_cas_absoluteFilePath = var_cas_fileName.reader_absolutePathFromPath (var_cas_sourceFilePath) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_getAbsoluteSourceFilePath\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "checkFileExists"                 *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_checkFileExists (C_Compiler & inLexique,
                                const GGS_lstring   var_cas_fileName COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_checkFileExists at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_absoluteFilePath ;
  ::routine_getAbsoluteSourceFilePath (inLexique,  var_cas_fileName.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (49)),  var_cas_absoluteFilePath COMMA_SOURCE_FILE_AT_LINE (49)) ;
  const GGS_bool cond_1408 = (var_cas_absoluteFilePath.reader_fileExists ()).operator_not () ;
  if (cond_1408.isBuiltAndTrue ()) {
    var_cas_fileName.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (51)).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("The file '")).operator_concat (var_cas_absoluteFilePath)).operator_concat (GGS_string ("' does not exists!")) COMMA_SOURCE_FILE_AT_LINE (51)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_checkFileExists\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "checkFileDoesNotExists"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_checkFileDoesNotExists (C_Compiler & inLexique,
                                const GGS_lstring   var_cas_fileName COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_checkFileDoesNotExists at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_absoluteFilePath ;
  ::routine_getAbsoluteSourceFilePath (inLexique,  var_cas_fileName.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (64)),  var_cas_absoluteFilePath COMMA_SOURCE_FILE_AT_LINE (64)) ;
  const GGS_bool cond_2189 = var_cas_fileName.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (65)).reader_directoryExists () ;
  if (cond_2189.isBuiltAndTrue ()) {
    var_cas_fileName.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (66)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("The file '")).operator_concat (var_cas_absoluteFilePath)).operator_concat (GGS_string ("' already exists and is a directory. It will not be overwritten.")) COMMA_SOURCE_FILE_AT_LINE (69)) ;
  }else if (cond_2189.isBuiltAndFalse ()) {
    GGS_string var_cas_projectDir = function_projectName (inLexique COMMA_SOURCE_FILE_AT_LINE (71)) ;
    var_cas_projectDir = var_cas_projectDir.reader_absolutePathFromPath (GGS_string::constructor_stringWithCurrentDirectory (inLexique COMMA_HERE)) ;
    const GGS_bool cond_2567 = (var_cas_projectDir).operator_isEqual (var_cas_absoluteFilePath) ;
    if (cond_2567.isBuiltAndTrue ()) {
      var_cas_fileName.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (74)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("The file '")).operator_concat (var_cas_absoluteFilePath)).operator_concat (GGS_string ("' is already the project directory. It will not be overwritten.")) COMMA_SOURCE_FILE_AT_LINE (75)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_checkFileDoesNotExists\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "checkTrampolinePath"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_checkTrampolinePath (C_Compiler & inLexique,
                                const GGS_lstring   var_cas_path COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_checkTrampolinePath at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_absolutePath ;
  ::routine_getAbsoluteSourceFilePath (inLexique,  var_cas_path.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (88)),  var_cas_absolutePath COMMA_SOURCE_FILE_AT_LINE (88)) ;
  GGS_string var_cas_osPath = (var_cas_absolutePath).operator_concat (GGS_string ("/os")) ;
  const GGS_bool cond_3218 = (var_cas_osPath.reader_directoryExists ()).operator_not () ;
  if (cond_3218.isBuiltAndTrue ()) {
    var_cas_path.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (92)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (((GGS_string ("The directory '")).operator_concat (var_cas_absolutePath)).operator_concat (GGS_string ("' does not seem to be the Trampoline base path."))).operator_concat (GGS_string (" I can't find the os/ subfolder.")) COMMA_SOURCE_FILE_AT_LINE (94)) ;
  }
  GGS_string var_cas_machinesPath = (var_cas_absolutePath).operator_concat (GGS_string ("/machines")) ;
  const GGS_bool cond_3535 = (var_cas_machinesPath.reader_directoryExists ()).operator_not () ;
  if (cond_3535.isBuiltAndTrue ()) {
    var_cas_path.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (98)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (((GGS_string ("The directory '")).operator_concat (var_cas_absolutePath)).operator_concat (GGS_string ("' does not seem to be the Trampoline base path."))).operator_concat (GGS_string ("I can't find the machines/ subfolder.")) COMMA_SOURCE_FILE_AT_LINE (100)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_checkTrampolinePath\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "check_target"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_target (C_Compiler & inLexique,
                                const GGS_string  var_cas_trampoline_path COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_target at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_machines_path ;
  ::routine_getAbsoluteSourceFilePath (inLexique,  var_cas_trampoline_path,  var_cas_machines_path COMMA_SOURCE_FILE_AT_LINE (109)) ;
  var_cas_machines_path.appendCString ("/machines") ;
  GGS_string var_cas_arch_path = ((var_cas_machines_path).operator_concat (GGS_string ("/"))).operator_concat (function_arch (inLexique COMMA_SOURCE_FILE_AT_LINE (111))) ;
  GGS_string var_cas_chip_path = ((var_cas_arch_path).operator_concat (GGS_string ("/"))).operator_concat (function_chip (inLexique COMMA_SOURCE_FILE_AT_LINE (112))) ;
  GGS_string var_cas_board_path = ((var_cas_chip_path).operator_concat (GGS_string ("/"))).operator_concat (function_board (inLexique COMMA_SOURCE_FILE_AT_LINE (113))) ;
  const GGS_bool cond_4064 = (var_cas_arch_path.reader_directoryExists ()).operator_not () ;
  if (cond_4064.isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("The directory '")).operator_concat (var_cas_arch_path)).operator_concat (GGS_string ("' does not exist")) COMMA_SOURCE_FILE_AT_LINE (115)) ;
  }else if (cond_4064.isBuiltAndFalse ()) {
    const GGS_bool cond_4177 = (var_cas_chip_path.reader_directoryExists ()).operator_not () ;
    if (cond_4177.isBuiltAndTrue ()) {
      GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("The directory '")).operator_concat (var_cas_chip_path)).operator_concat (GGS_string ("' does not exist")) COMMA_SOURCE_FILE_AT_LINE (117)) ;
    }else if (cond_4177.isBuiltAndFalse ()) {
      const GGS_bool cond_4290 = (var_cas_board_path.reader_directoryExists ()).operator_not () ;
      if (cond_4290.isBuiltAndTrue ()) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("The directory '")).operator_concat (var_cas_board_path)).operator_concat (GGS_string ("' does not exist")) COMMA_SOURCE_FILE_AT_LINE (119)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_target\n") ;
  #endif
}

//---------------------------------------------------------------------------*

