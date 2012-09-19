//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_code_generation.cpp'                       *
//                    Generated by version version 2.4.2                     *
//                    september 19th, 2012, at 16h32'26"                     *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "goil_code_generation.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"
#include "template_grammar.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_code_generation.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_signed_type'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_5F_signed_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                         GALGAS_string inArgument_err,
                                         GALGAS_string & outArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_s_38_ = GALGAS_uint_36__34_ ((PMUInt64) 1ULL).left_shift_operation (GALGAS_uint ((PMUInt32) 7U) COMMA_SOURCE_FILE_AT_LINE (56)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_s_31__36_ = GALGAS_uint_36__34_ ((PMUInt64) 1ULL).left_shift_operation (GALGAS_uint ((PMUInt32) 15U) COMMA_SOURCE_FILE_AT_LINE (57)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_s_33__32_ = GALGAS_uint_36__34_ ((PMUInt64) 1ULL).left_shift_operation (GALGAS_uint ((PMUInt32) 31U) COMMA_SOURCE_FILE_AT_LINE (58)) ;
  //-------- @ifInstructionForGeneration
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38_)).boolEnum () ;
  if (kBoolTrue == test_0) {
    //-------- @assignmentInstructionForGeneration
    outArgument_type = GALGAS_string ("s8") ;
  }else if (kBoolFalse == test_0) {
    //-------- @ifInstructionForGeneration
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36_)).boolEnum () ;
    if (kBoolTrue == test_1) {
      //-------- @assignmentInstructionForGeneration
      outArgument_type = GALGAS_string ("s16") ;
    }else if (kBoolFalse == test_1) {
      //-------- @ifInstructionForGeneration
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32_)).boolEnum () ;
      if (kBoolTrue == test_2) {
        //-------- @assignmentInstructionForGeneration
        outArgument_type = GALGAS_string ("s32") ;
      }else if (kBoolFalse == test_2) {
        //-------- @assignmentInstructionForGeneration
        outArgument_type = GALGAS_string::makeEmptyString () ;
        //-------- @errorInstructionForGeneration
        inCompiler->emitSemanticError (inCompiler->here (), inArgument_err COMMA_SOURCE_FILE_AT_LINE (70)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'generate_unsigned_type'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_5F_unsigned_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                           GALGAS_string inArgument_err,
                                           GALGAS_string & outArgument_type,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_u_38_ = GALGAS_uint_36__34_ ((PMUInt64) 1ULL).left_shift_operation (GALGAS_uint ((PMUInt32) 8U) COMMA_SOURCE_FILE_AT_LINE (82)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_u_31__36_ = GALGAS_uint_36__34_ ((PMUInt64) 1ULL).left_shift_operation (GALGAS_uint ((PMUInt32) 16U) COMMA_SOURCE_FILE_AT_LINE (83)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_u_33__32_ = GALGAS_uint_36__34_ ((PMUInt64) 1ULL).left_shift_operation (GALGAS_uint ((PMUInt32) 32U) COMMA_SOURCE_FILE_AT_LINE (84)) ;
  //-------- @ifInstructionForGeneration
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38_)).boolEnum () ;
  if (kBoolTrue == test_0) {
    //-------- @assignmentInstructionForGeneration
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    //-------- @ifInstructionForGeneration
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36_)).boolEnum () ;
    if (kBoolTrue == test_1) {
      //-------- @assignmentInstructionForGeneration
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      //-------- @ifInstructionForGeneration
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32_)).boolEnum () ;
      if (kBoolTrue == test_2) {
        //-------- @assignmentInstructionForGeneration
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        //-------- @assignmentInstructionForGeneration
        outArgument_type = GALGAS_string::makeEmptyString () ;
        //-------- @errorInstructionForGeneration
        inCompiler->emitSemanticError (inCompiler->here (), inArgument_err COMMA_SOURCE_FILE_AT_LINE (96)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'generate_mask_type'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_5F_mask_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                       GALGAS_string inArgument_err,
                                       GALGAS_string & outArgument_type,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_u_38_ = GALGAS_uint_36__34_ ((PMUInt64) 8ULL) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_u_31__36_ = GALGAS_uint_36__34_ ((PMUInt64) 16ULL) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_uint_36__34_ var_max_5F_u_33__32_ = GALGAS_uint_36__34_ ((PMUInt64) 32ULL) ;
  //-------- @ifInstructionForGeneration
  const enumGalgasBool test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38_)).boolEnum () ;
  if (kBoolTrue == test_0) {
    //-------- @assignmentInstructionForGeneration
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    //-------- @ifInstructionForGeneration
    const enumGalgasBool test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36_)).boolEnum () ;
    if (kBoolTrue == test_1) {
      //-------- @assignmentInstructionForGeneration
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      //-------- @ifInstructionForGeneration
      const enumGalgasBool test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32_)).boolEnum () ;
      if (kBoolTrue == test_2) {
        //-------- @assignmentInstructionForGeneration
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        //-------- @assignmentInstructionForGeneration
        outArgument_type = GALGAS_string::makeEmptyString () ;
        //-------- @errorInstructionForGeneration
        inCompiler->emitSemanticError (inCompiler->here (), inArgument_err COMMA_SOURCE_FILE_AT_LINE (122)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'generate_all'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_5F_all (const GALGAS_TfieldMap constinArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_string var_temp_5F_dir = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE_AT_LINE (717)) ;
  //-------- @ifInstructionForGeneration
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
    GALGAS_string var_target = GALGAS_string (gOption_goil_5F_options_target_5F_platform.reader_value ()) ;
    //-------- @ifInstructionForGeneration
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_target.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
      GALGAS_string var_goilLog = function_computeTemplate (GALGAS_string::makeEmptyString (), constinArgument_cfg, GALGAS_string ("root"), inCompiler COMMA_SOURCE_FILE_AT_LINE (827)) ;
      //-------- @ifInstructionForGeneration
      const enumGalgasBool test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.reader_value ()).boolEnum () ;
      if (kBoolTrue == test_2) {
        //-------- @methodCallInstructionForGeneration
        var_goilLog.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE_AT_LINE (829)) ;
        //-------- END @methodCallInstructionForGeneration
      }
    }else if (kBoolFalse == test_1) {
      //-------- @messageInstructionForGeneration
      inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n") COMMA_SOURCE_FILE_AT_LINE (849)) ;
    }
  }else if (kBoolFalse == test_0) {
    //-------- @messageInstructionForGeneration
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n") COMMA_SOURCE_FILE_AT_LINE (852)) ;
  }
}


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


