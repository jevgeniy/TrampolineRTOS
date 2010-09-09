//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'template_functions.cpp'                        *
//                        Generated by version 2.0.1                         *
//                    september 3rd, 2010, at 11h11'23"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 837
  #error "This file has been compiled with a version of GALGAS that uses libpm version 837, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "template_functions.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "template_functions.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of function "trueFalse"                   *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_string function_trueFalse (C_Compiler &,
                                const GGS_bool  var_cas_inBool COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER function_trueFalse at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result ;
  const GGS_bool cond_1024 = var_cas_inBool ;
  if (cond_1024.isBuiltAndTrue ()) {
    var_cas_result = GGS_string ("true") ;
  }else if (cond_1024.isBuiltAndFalse ()) {
    var_cas_result = GGS_string ("false") ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_trueFalse\n") ;
  #endif
  return var_cas_result ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_trueFalse (C_Compiler & inLexique,
                           const GGS_objectlist & inEffectiveParameterArray,
                           const GGS_location & inErrorLocation
                           COMMA_LOCATION_ARGS) {
  const GGS_bool arg_0 = GGS_bool::castFromObject (inLexique, inEffectiveParameterArray.reader_mValueAtIndex (inLexique, GGS_uint (0) COMMA_THERE), inErrorLocation COMMA_THERE) ;
  const GGS_string result = function_trueFalse (inLexique,
                            arg_0
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

static const C_galgas_type_descriptorEX *
kArgumentTypeList_trueFalse [1] = {& kTypeDescriptor_GGS_bool} ;

const C_galgas_function_descriptorEX
kFunction_descriptor_trueFalse ("trueFalse",
                              functionForGenericCall_trueFalse,
                              & kTypeDescriptor_GGS_string,
                              1,
                              kArgumentTypeList_trueFalse) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Implementation of function "yesNo"                     *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_string function_yesNo (C_Compiler &,
                                const GGS_bool  var_cas_inBool COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER function_yesNo at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result ;
  const GGS_bool cond_1165 = var_cas_inBool ;
  if (cond_1165.isBuiltAndTrue ()) {
    var_cas_result = GGS_string ("YES") ;
  }else if (cond_1165.isBuiltAndFalse ()) {
    var_cas_result = GGS_string ("NO") ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_yesNo\n") ;
  #endif
  return var_cas_result ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_yesNo (C_Compiler & inLexique,
                           const GGS_objectlist & inEffectiveParameterArray,
                           const GGS_location & inErrorLocation
                           COMMA_LOCATION_ARGS) {
  const GGS_bool arg_0 = GGS_bool::castFromObject (inLexique, inEffectiveParameterArray.reader_mValueAtIndex (inLexique, GGS_uint (0) COMMA_THERE), inErrorLocation COMMA_THERE) ;
  const GGS_string result = function_yesNo (inLexique,
                            arg_0
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

static const C_galgas_type_descriptorEX *
kArgumentTypeList_yesNo [1] = {& kTypeDescriptor_GGS_bool} ;

const C_galgas_function_descriptorEX
kFunction_descriptor_yesNo ("yesNo",
                              functionForGenericCall_yesNo,
                              & kTypeDescriptor_GGS_string,
                              1,
                              kArgumentTypeList_yesNo) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of function "TRUEFALSE"                   *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_string function_TRUEFALSE (C_Compiler &,
                                const GGS_bool  var_cas_inBool COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER function_TRUEFALSE at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result ;
  const GGS_bool cond_1308 = var_cas_inBool ;
  if (cond_1308.isBuiltAndTrue ()) {
    var_cas_result = GGS_string ("TRUE") ;
  }else if (cond_1308.isBuiltAndFalse ()) {
    var_cas_result = GGS_string ("FALSE") ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_TRUEFALSE\n") ;
  #endif
  return var_cas_result ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_TRUEFALSE (C_Compiler & inLexique,
                           const GGS_objectlist & inEffectiveParameterArray,
                           const GGS_location & inErrorLocation
                           COMMA_LOCATION_ARGS) {
  const GGS_bool arg_0 = GGS_bool::castFromObject (inLexique, inEffectiveParameterArray.reader_mValueAtIndex (inLexique, GGS_uint (0) COMMA_THERE), inErrorLocation COMMA_THERE) ;
  const GGS_string result = function_TRUEFALSE (inLexique,
                            arg_0
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

static const C_galgas_type_descriptorEX *
kArgumentTypeList_TRUEFALSE [1] = {& kTypeDescriptor_GGS_bool} ;

const C_galgas_function_descriptorEX
kFunction_descriptor_TRUEFALSE ("TRUEFALSE",
                              functionForGenericCall_TRUEFALSE,
                              & kTypeDescriptor_GGS_string,
                              1,
                              kArgumentTypeList_TRUEFALSE) ;

//---------------------------------------------------------------------------*

