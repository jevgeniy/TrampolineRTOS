//---------------------------------------------------------------------------*
//                                                                           *
//                   File 'goil_template_invocation.cpp'                     *
//                        Generated by version 1.9.7                         *
//                     december 18th, 2009, at 10h53'0"                      *
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
#include "goil_template_invocation.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_template_invocation.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//             Include directives generated by grammar includes              *
//                                                                           *
//---------------------------------------------------------------------------*

#include "goil_template_grammar.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of once function "allowedFunctions"             *
//                                                                           *
//---------------------------------------------------------------------------*

static GGS_stringset  gCachedResultForOnceFunction_allowedFunctions ;
static bool gCacheFlagForOnceFunction_allowedFunctions = false ;

//---------------------------------------------------------------------------*

GGS_stringset  function_allowedFunctions (C_Compiler & COMMA_UNUSED_LOCATION_ARGS) {
  if (! gCacheFlagForOnceFunction_allowedFunctions) {
    #ifdef DEBUG_TRACE_ENABLED
      printf ("ENTER function_allowedFunctions at %s:%d\n", __FILE__, __LINE__) ;
    #endif
  GGS_stringset  var_cas_outAllowedFunctionSet ;
    var_cas_outAllowedFunctionSet = GGS_stringset ::constructor_emptySet () ;
    var_cas_outAllowedFunctionSet.addAssign_operation (GGS_string ("testFunction")) ;
    var_cas_outAllowedFunctionSet.addAssign_operation (GGS_string ("tasks")) ;
    #ifdef DEBUG_TRACE_ENABLED
      printf ("LEAVE function_allowedFunctions\n") ;
    #endif
    gCacheFlagForOnceFunction_allowedFunctions = true ;
    gCachedResultForOnceFunction_allowedFunctions = var_cas_outAllowedFunctionSet ;
  }
  return gCachedResultForOnceFunction_allowedFunctions ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_allowedFunctions (C_Compiler & inLexique,
                           const GGS_objectlist & /* inEffectiveParameterArray */,
                           const GGS_location & /* inErrorLocation */
                           COMMA_LOCATION_ARGS) {
  const GGS_stringset  result = function_allowedFunctions (inLexique
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

const C_galgas_function_descriptor kFunction_descriptor_allowedFunctions ("allowedFunctions",
                              functionForGenericCall_allowedFunctions,
                              & kTypeDescriptor_GGS_stringset ,
                              0,
                              NULL) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "addBoolValue"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addBoolValue (C_Compiler & inLexique,
                                GGS_goilTemplateVariableMap  & var_cas_ioTemplateVariableMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_bool  var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addBoolValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateVariableMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_boolType (inLexique COMMA_HERE), GGS_goilTemplateValue::constructor_new (((var_cas_inValue).isBuiltAndTrue () ? (GGS_uint64 (1ULL)) : (GGS_uint64 (0ULL))), GGS_string (""), GGS_goilTemplateFieldMapList ::constructor_emptyList ()) COMMA_SOURCE_FILE_AT_LINE (41)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addBoolValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "addUnsignedValue"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addUnsignedValue (C_Compiler & inLexique,
                                GGS_goilTemplateVariableMap  & var_cas_ioTemplateVariableMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_uint64   var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addUnsignedValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateVariableMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_unsignedType (inLexique COMMA_HERE), GGS_goilTemplateValue::constructor_new (var_cas_inValue, GGS_string (""), GGS_goilTemplateFieldMapList ::constructor_emptyList ()) COMMA_SOURCE_FILE_AT_LINE (55)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addUnsignedValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of routine "addStringValue"                 *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addStringValue (C_Compiler & inLexique,
                                GGS_goilTemplateVariableMap  & var_cas_ioTemplateVariableMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_string  var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addStringValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateVariableMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_stringType (inLexique COMMA_HERE), GGS_goilTemplateValue::constructor_new (GGS_uint64 (0ULL), var_cas_inValue, GGS_goilTemplateFieldMapList ::constructor_emptyList ()) COMMA_SOURCE_FILE_AT_LINE (69)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addStringValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "addListValue"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addListValue (C_Compiler & inLexique,
                                GGS_goilTemplateVariableMap  & var_cas_ioTemplateVariableMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_goilTemplateFieldMapList   var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addListValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateVariableMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_listType (inLexique COMMA_HERE), GGS_goilTemplateValue::constructor_new (GGS_uint64 (0ULL), GGS_string (""), var_cas_inValue) COMMA_SOURCE_FILE_AT_LINE (83)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addListValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "addBoolFieldValue"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addBoolFieldValue (C_Compiler & inLexique,
                                GGS_goilTemplateFieldMap  & var_cas_ioTemplateFieldMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_bool  var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addBoolFieldValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateFieldMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_boolType (inLexique COMMA_HERE), ((var_cas_inValue).isBuiltAndTrue () ? (GGS_uint64 (1ULL)) : (GGS_uint64 (0ULL))), GGS_string (""), GGS_goilTemplateFieldMapList ::constructor_emptyList () COMMA_SOURCE_FILE_AT_LINE (101)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addBoolFieldValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "addUnsignedFieldValue"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addUnsignedFieldValue (C_Compiler & inLexique,
                                GGS_goilTemplateFieldMap  & var_cas_ioTemplateFieldMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_uint64   var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addUnsignedFieldValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateFieldMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_unsignedType (inLexique COMMA_HERE), var_cas_inValue, GGS_string (""), GGS_goilTemplateFieldMapList ::constructor_emptyList () COMMA_SOURCE_FILE_AT_LINE (117)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addUnsignedFieldValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "addStringFieldValue"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addStringFieldValue (C_Compiler & inLexique,
                                GGS_goilTemplateFieldMap  & var_cas_ioTemplateFieldMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_string  var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addStringFieldValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateFieldMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_stringType (inLexique COMMA_HERE), GGS_uint64 (0ULL), var_cas_inValue, GGS_goilTemplateFieldMapList ::constructor_emptyList () COMMA_SOURCE_FILE_AT_LINE (133)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addStringFieldValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "addListFieldValue"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_addListFieldValue (C_Compiler & inLexique,
                                GGS_goilTemplateFieldMap  & var_cas_ioTemplateFieldMap,
                                const GGS_lstring   var_cas_inVariableName,
                                const GGS_goilTemplateFieldMapList   var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_addListFieldValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_ioTemplateFieldMap.modifier_insertKey (inLexique, var_cas_inVariableName, GGS_goilTemplateType::constructor_listType (inLexique COMMA_HERE), GGS_uint64 (0ULL), GGS_string (""), var_cas_inValue COMMA_SOURCE_FILE_AT_LINE (149)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_addListFieldValue\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of function "displayTypeAndValue"              *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_string function_displayTypeAndValue (C_Compiler & inLexique,
                                const GGS_goilTemplateType  var_cas_inType,
                                const GGS_goilTemplateValue  var_cas_inValue COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER function_displayTypeAndValue at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_outResult ;
  switch (var_cas_inType.enumValue ()) {
  case GGS_goilTemplateType::enum_boolType:
    {
    var_cas_outResult = (GGS_string ("bool: ")).operator_concat ((((var_cas_inValue.reader_mUnsigned64Value (inLexique COMMA_SOURCE_FILE_AT_LINE (171))).operator_isEqual (GGS_uint64 (1ULL))).isBuiltAndTrue () ? (GGS_string ("yes")) : (GGS_string ("no")))) ;
    }
    break ;
  case GGS_goilTemplateType::enum_unsignedType:
    {
    var_cas_outResult = (GGS_string ("unsigned: ")).operator_concat (var_cas_inValue.reader_mUnsigned64Value (inLexique COMMA_SOURCE_FILE_AT_LINE (173)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (173))) ;
    }
    break ;
  case GGS_goilTemplateType::enum_stringType:
    {
    var_cas_outResult = ((GGS_string ("string: '")).operator_concat (var_cas_inValue.reader_mStringValue (inLexique COMMA_SOURCE_FILE_AT_LINE (175)))).operator_concat (GGS_string ("'")) ;
    }
    break ;
  case GGS_goilTemplateType::enum_listType:
    {
    var_cas_outResult = ((((GGS_string ("list, ")).operator_concat (var_cas_inValue.reader_mMapListValue (inLexique COMMA_SOURCE_FILE_AT_LINE (177)).reader_length ().reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (177)))).operator_concat (GGS_string (" element"))).operator_concat ((((var_cas_inValue.reader_mMapListValue (inLexique COMMA_SOURCE_FILE_AT_LINE (177)).reader_length ()).operator_strictSup (GGS_uint (1U))).isBuiltAndTrue () ? (GGS_string ("s")) : (GGS_string (""))))).operator_concat (GGS_string (":")) ;
    {
        GGS_uint var_cas_idx (true, 0) ;
      GGS_goilTemplateFieldMapList::cEnumerator enumerator_6447 (var_cas_inValue.reader_mMapListValue (inLexique COMMA_SOURCE_FILE_AT_LINE (178)), true) ;
      const GGS_goilTemplateFieldMapList::cElement * operand_6447 = NULL ;
      while (((operand_6447 = enumerator_6447.nextObject ()))) {
        macroValidPointer (operand_6447) ;
        var_cas_outResult.appendCString ("\n"
          "  #") ;
        var_cas_outResult.dotAssign_operation (var_cas_idx.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (179))) ;
        var_cas_outResult.appendCString (":") ;
        {
          GGS_goilTemplateFieldMap::cEnumerator enumerator_6551 (operand_6447->mMap, true) ;
          const GGS_goilTemplateFieldMap::cElement * operand_6551 = enumerator_6551.nextObject () ;
          if ((operand_6551 != NULL)) {
            bool _foreach_loop_6551 ;
            do{
              macroValidPointer (operand_6551) ;
              var_cas_outResult.appendCString ("'") ;
              var_cas_outResult.dotAssign_operation (operand_6551->mKey) ;
              var_cas_outResult.appendCString ("' ") ;
              switch (operand_6551->mInfo.mType.enumValue ()) {
              case GGS_goilTemplateType::enum_boolType:
                {
                var_cas_outResult.appendCString ("bool: ") ;
                var_cas_outResult.dotAssign_operation ((((operand_6551->mInfo.mUnsigned64Value).operator_isEqual (GGS_uint64 (1ULL))).isBuiltAndTrue () ? (GGS_string ("yes")) : (GGS_string ("no")))) ;
                }
                break ;
              case GGS_goilTemplateType::enum_unsignedType:
                {
                var_cas_outResult.appendCString ("unsigned: ") ;
                var_cas_outResult.dotAssign_operation (operand_6551->mInfo.mUnsigned64Value.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (186))) ;
                }
                break ;
              case GGS_goilTemplateType::enum_stringType:
                {
                var_cas_outResult.appendCString ("string: '") ;
                var_cas_outResult.dotAssign_operation (operand_6551->mInfo.mStringValue) ;
                var_cas_outResult.appendCString ("'") ;
                }
                break ;
              case GGS_goilTemplateType::enum_listType:
                {
                }
                break ;
              case GGS_goilTemplateType::kNotBuilt:
                break ;
              }
              operand_6551 = enumerator_6551.nextObject () ;
              _foreach_loop_6551 = ((operand_6551 != NULL)) ;
              if (_foreach_loop_6551) {
                var_cas_outResult.appendCString (", ") ;
              }
            }while (_foreach_loop_6551) ;
          }
        }
        var_cas_idx.mValue ++ ;
      }
    }
    }
    break ;
  case GGS_goilTemplateType::kNotBuilt:
    break ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_displayTypeAndValue\n") ;
  #endif
  return var_cas_outResult ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_displayTypeAndValue (C_Compiler & inLexique,
                           const GGS_objectlist & inEffectiveParameterArray,
                           const GGS_location & inErrorLocation
                           COMMA_LOCATION_ARGS) {
  const GGS_goilTemplateType arg_0 = GGS_goilTemplateType::castFromObject (inLexique, inEffectiveParameterArray.reader_mValueAtIndex (inLexique, GGS_uint (0) COMMA_THERE), inErrorLocation COMMA_THERE) ;
  const GGS_goilTemplateValue arg_1 = GGS_goilTemplateValue::castFromObject (inLexique, inEffectiveParameterArray.reader_mValueAtIndex (inLexique, GGS_uint (1) COMMA_THERE), inErrorLocation COMMA_THERE) ;
  const GGS_string result = function_displayTypeAndValue (inLexique,
                            arg_0,
                            arg_1
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

static const C_galgas_type_descriptor *
kArgumentTypeList_displayTypeAndValue [2] = {& kTypeDescriptor_GGS_goilTemplateType,
                              & kTypeDescriptor_GGS_goilTemplateValue} ;

const C_galgas_function_descriptor
kFunction_descriptor_displayTypeAndValue ("displayTypeAndValue",
                              functionForGenericCall_displayTypeAndValue,
                              & kTypeDescriptor_GGS_string,
                              2,
                              kArgumentTypeList_displayTypeAndValue) ;

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "displayTemplateVariableMap"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_displayTemplateVariableMap (C_Compiler & inLexique,
                                const GGS_goilTemplateVariableMap   var_cas_inTemplateVariableMap COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_displayTemplateVariableMap at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_goilTemplateVariableMap::cEnumerator enumerator_7254 (var_cas_inTemplateVariableMap, true) ;
    const GGS_goilTemplateVariableMap::cElement * operand_7254 = NULL ;
    while (((operand_7254 = enumerator_7254.nextObject ()))) {
      macroValidPointer (operand_7254) ;
      inLexique.printMessage (((((GGS_string ("'")).operator_concat (operand_7254->mKey)).operator_concat (GGS_string ("' "))).operator_concat (function_displayTypeAndValue (inLexique, operand_7254->mInfo.mType, operand_7254->mInfo.mValue COMMA_SOURCE_FILE_AT_LINE (203)))).operator_concat (GGS_string ("\n")) COMMA_SOURCE_FILE_AT_LINE (203)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_displayTemplateVariableMap\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "displayPathList"                 *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_displayPathList (C_Compiler & inLexique,
                                const GGS_stringlist   var_cas_pathList COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_displayPathList at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  inLexique.printMessage (GGS_string (" -----------------------------------------\n") COMMA_SOURCE_FILE_AT_LINE (210)) ;
  {
    GGS_stringlist::cEnumerator enumerator_7493 (var_cas_pathList, true) ;
    const GGS_stringlist::cElement * operand_7493 = NULL ;
    while (((operand_7493 = enumerator_7493.nextObject ()))) {
      macroValidPointer (operand_7493) ;
      inLexique.printMessage (((GGS_string (" - '")).operator_concat (operand_7493->mValue)).operator_concat (GGS_string ("'\n")) COMMA_SOURCE_FILE_AT_LINE (212)) ;
    }
  }
  inLexique.printMessage (GGS_string (" -----------------------------------------\n") COMMA_SOURCE_FILE_AT_LINE (214)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_displayPathList\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "goilTemplateInvocation"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_goilTemplateInvocation (C_Compiler & inLexique,
                                const GGS_lstring   var_cas_inTemplateName,
                                const GGS_string  var_cas_inPrefix,
                                const GGS_string  var_cas_inPath,
                                const GGS_systemConfig   var_cas_inCfg,
                                const GGS_goilTemplateVariableMap   var_cas_inTemplateVariableMap,
                                GGS_string & var_cas_ioResultingString COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_goilTemplateInvocation at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  const GGS_bool cond_11302 = (GGS_uint ::constructor_errorCount (inLexique COMMA_HERE)).operator_isEqual (GGS_uint (0U)) ;
  if (cond_11302.isBuiltAndTrue ()) {
    const GGS_string var_cas_templateDir = function_root_templates_directory (inLexique COMMA_SOURCE_FILE_AT_LINE (227)) ;
    const GGS_bool cond_8267 = (var_cas_templateDir.reader_length ()).operator_isEqual (GGS_uint (0U)) ;
    if (cond_8267.isBuiltAndTrue ()) {
      var_cas_inTemplateName.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("the '--goil-templates' option or the environment variable GOIL_TEMPLATES is required for generating code") COMMA_SOURCE_FILE_AT_LINE (230)) ;
    }else if (cond_8267.isBuiltAndFalse ()) {
      const GGS_bool cond_8427 = (var_cas_templateDir.reader_directoryExists ()).operator_not () ;
      if (cond_8427.isBuiltAndTrue ()) {
        var_cas_inTemplateName.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("the template path '")).operator_concat (var_cas_templateDir)).operator_concat (GGS_string ("' exists but is not a valid directory path")) COMMA_SOURCE_FILE_AT_LINE (232)) ;
      }else if (cond_8427.isBuiltAndFalse ()) {
        const GGS_string var_cas_targetDir = gOption_goil_5F_options_target_5F_platform.reader_value () ;
        const GGS_bool cond_8653 = (var_cas_targetDir.reader_length ()).operator_isEqual (GGS_uint (0U)) ;
        if (cond_8653.isBuiltAndTrue ()) {
          var_cas_inTemplateName.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("the '--target' (or '-t') option is required for generating code") COMMA_SOURCE_FILE_AT_LINE (236)) ;
        }else if (cond_8653.isBuiltAndFalse ()) {
          const GGS_bool cond_9145 = (((var_cas_templateDir).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inPrefix).reader_directoryExists ()).operator_not () ;
          if (cond_9145.isBuiltAndTrue ()) {
            var_cas_inTemplateName.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((GGS_string ("internal. no '")).operator_concat (var_cas_templateDir)).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inPrefix)).operator_concat (GGS_string ("' template found")) COMMA_SOURCE_FILE_AT_LINE (243)) ;
          }else if (cond_9145.isBuiltAndFalse ()) {
            GGS_stringlist  var_cas_pathList = GGS_stringlist ::constructor_emptyList () ;
            GGS_bool var_cas_found = GGS_bool (false) ;
            const GGS_bool cond_9701 = (var_cas_inPath).operator_isNotEqual (GGS_string ("")) ;
            if (cond_9701.isBuiltAndTrue ()) {
              const GGS_string var_cas_fullTemplatePath = (((((var_cas_inPath).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inPrefix)).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inTemplateName)).operator_concat (GGS_string (".goilTemplate")) ;
              var_cas_pathList.addAssign_operation (var_cas_fullTemplatePath) ;
              var_cas_found = var_cas_fullTemplatePath.reader_fileExists () ;
              const GGS_bool cond_9684 = var_cas_found ;
              if (cond_9684.isBuiltAndTrue ()) {
                const GGS_string _depExtension = GGS_string ("") ;
                const GGS_string _depPath = GGS_string ("") ;
                if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
                  goil_template_grammar::_performSourceFileParsing_ (inLexique,
                                                _depExtension.string (),
                                                _depPath.string (),
                                                NULL,
                                                GGS_lstring ::constructor_new (inLexique, var_cas_fullTemplatePath, GGS_location (inLexique) COMMA_HERE),
                                                var_cas_inPrefix,
                                                var_cas_inPath,
                                                var_cas_inCfg,
                                                var_cas_inTemplateVariableMap,
                                                var_cas_ioResultingString
                                                COMMA_SOURCE_FILE_AT_LINE (252)) ;
                }
              }
            }
            GGS_string var_cas_targetTemplatePartialPath = var_cas_targetDir ;
            GGS_uint _variant_10487 = var_cas_targetDir.reader_length () ;
            GGS_bool _condition_10487 (_variant_10487.isBuilt (), true) ;
            while (_condition_10487.isBuiltAndTrue ()) {
              _condition_10487 = ((var_cas_targetTemplatePartialPath.reader_length ()).operator_strictSup (GGS_uint (0U))).operator_and ((var_cas_found).operator_not ()) ;
              if (_condition_10487.isBuiltAndTrue ()) {
                if (_variant_10487.uintValue () == 0) {
                  inLexique.onTheFlyRunTimeError ("loop variant error" COMMA_SOURCE_FILE_AT_LINE (268)) ;
                  _condition_10487 = GGS_bool (false) ;
                }else{
                  _variant_10487.decrement_operation (inLexique COMMA_HERE) ;
                  const GGS_string var_cas_fullTemplatePath = (((((((var_cas_templateDir).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inPrefix)).operator_concat (GGS_string ("/"))).operator_concat (var_cas_targetTemplatePartialPath)).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inTemplateName)).operator_concat (GGS_string (".goilTemplate")) ;
                  var_cas_pathList.addAssign_operation (var_cas_fullTemplatePath) ;
                  var_cas_found = var_cas_fullTemplatePath.reader_fileExists () ;
                  const GGS_bool cond_10351 = var_cas_found ;
                  if (cond_10351.isBuiltAndTrue ()) {
                    const GGS_string _depExtension = GGS_string ("") ;
                    const GGS_string _depPath = GGS_string ("") ;
                    if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
                      goil_template_grammar::_performSourceFileParsing_ (inLexique,
                                                    _depExtension.string (),
                                                    _depPath.string (),
                                                    NULL,
                                                    GGS_lstring ::constructor_new (inLexique, var_cas_fullTemplatePath, GGS_location (inLexique) COMMA_HERE),
                                                    var_cas_inPrefix,
                                                    var_cas_inPath,
                                                    var_cas_inCfg,
                                                    var_cas_inTemplateVariableMap,
                                                    var_cas_ioResultingString
                                                    COMMA_SOURCE_FILE_AT_LINE (264)) ;
                    }
                  }else if (cond_10351.isBuiltAndFalse ()) {
                    var_cas_targetTemplatePartialPath = var_cas_targetTemplatePartialPath.reader_stringByDeletingLastPathComponent () ;
                  }
                }
              }
            }
            const GGS_bool cond_10977 = (var_cas_found).operator_not () ;
            if (cond_10977.isBuiltAndTrue ()) {
              const GGS_string var_cas_fullTemplatePath = (((((var_cas_templateDir).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inPrefix)).operator_concat (GGS_string ("/"))).operator_concat (var_cas_inTemplateName)).operator_concat (GGS_string (".goilTemplate")) ;
              var_cas_pathList.addAssign_operation (var_cas_fullTemplatePath) ;
              var_cas_found = var_cas_fullTemplatePath.reader_fileExists () ;
              const GGS_bool cond_10961 = var_cas_found ;
              if (cond_10961.isBuiltAndTrue ()) {
                const GGS_string _depExtension = GGS_string ("") ;
                const GGS_string _depPath = GGS_string ("") ;
                if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
                  goil_template_grammar::_performSourceFileParsing_ (inLexique,
                                                _depExtension.string (),
                                                _depPath.string (),
                                                NULL,
                                                GGS_lstring ::constructor_new (inLexique, var_cas_fullTemplatePath, GGS_location (inLexique) COMMA_HERE),
                                                var_cas_inPrefix,
                                                var_cas_inPath,
                                                var_cas_inCfg,
                                                var_cas_inTemplateVariableMap,
                                                var_cas_ioResultingString
                                                COMMA_SOURCE_FILE_AT_LINE (275)) ;
                }
              }
            }
            const GGS_bool cond_11263 = (var_cas_found).operator_not () ;
            if (cond_11263.isBuiltAndTrue ()) {
              GGS_string var_cas_m = ((GGS_string ("cannot find a valid path for the '")).operator_concat (var_cas_inTemplateName)).operator_concat (GGS_string ("' template; I have tried:")) ;
              {
                GGS_stringlist::cEnumerator enumerator_11143 (var_cas_pathList, true) ;
                const GGS_stringlist::cElement * operand_11143 = NULL ;
                while (((operand_11143 = enumerator_11143.nextObject ()))) {
                  macroValidPointer (operand_11143) ;
                  var_cas_m.appendCString ("\n"
                    "  - '") ;
                  var_cas_m.dotAssign_operation (operand_11143->mValue) ;
                  var_cas_m.appendCString ("';") ;
                }
              }
              var_cas_inTemplateName.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, var_cas_m COMMA_SOURCE_FILE_AT_LINE (284)) ;
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_goilTemplateInvocation\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      Prologue and epilogue actions                        *
//                                                                           *
//---------------------------------------------------------------------------*

static void epilogueRoutineFor_goil_template_invocation (void) {
  gCachedResultForOnceFunction_allowedFunctions.drop () ;
}

//---------------------------------------------------------------------------*

C_PrologueEpilogueAction prologueEpilogueObjectFor_goil_template_invocation (NULL,
                                   epilogueRoutineFor_goil_template_invocation) ;

//---------------------------------------------------------------------------*

