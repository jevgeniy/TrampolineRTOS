#---------------------------------------------------------------*

#--- LIBPM directory
LIBPM_DIRECTORY_PATH := ../galgas_sources/GALGAS_OUTPUT/libpm

#---------------------------------------------------------------*
#                                                               *
#     Project source files directories                          *
#                                                               *
#---------------------------------------------------------------*

SOURCES_DIR := ../galgas_sources/GALGAS_OUTPUT
SOURCES_DIR += ../galgas_sources/GALGAS_OUTPUT/include-files

#---------------------------------------------------------------*
#                                                               *
#     Source files names list (without their actual path)       *
#                                                               *
#---------------------------------------------------------------*

SOURCES :=

#---------------------------------------------------------------*

#--- Hand-coded files ---------------------

#--- Files generated by GALGAS ------------
SOURCES += template_semantics.cpp
SOURCES += template_scanner.cpp
SOURCES += template_expression_parser.cpp
SOURCES += template_parser.cpp
SOURCES += template_grammar.cpp
SOURCES += template_invocation.cpp
SOURCES += template_routines.cpp
SOURCES += template_functions.cpp
SOURCES += goil_lexique.cpp
SOURCES += goil_options.cpp
SOURCES += goil_syntax.cpp
SOURCES += implementation_parser.cpp
SOURCES += implementation_types.cpp
SOURCES += goil_semantics.cpp
SOURCES += goil_basic_types.cpp
SOURCES += goil_routines.cpp
SOURCES += systemConfig.cpp
SOURCES += defaults.cpp
SOURCES += semantic_verification.cpp
SOURCES += goil_types_root.cpp
SOURCES += goil_code_generation.cpp
SOURCES += goil_grammar.cpp
SOURCES += goil_file_level_include.cpp
SOURCES += goil_cpu_level_include.cpp
SOURCES += goil_program.cpp


#---------------------------------------------------------------*
#                                                               *
#     Files from LIBPM                                          *
#                                                               *
#---------------------------------------------------------------*

#--- Command Line Option
SOURCES += C_CommandLineOption.cpp
SOURCES += C_BoolCommandLineOption.cpp
SOURCES += C_UIntCommandLineOption.cpp
SOURCES += C_StringCommandLineOption.cpp
SOURCES += C_builtin_CLI_Options.cpp
SOURCES += C_galgas_CLI_Options.cpp
SOURCES += F_Analyze_CLI_Options.cpp

#--- BDD
SOURCES += C_Display_BDD.cpp
SOURCES += C_BDD.cpp
SOURCES += C_BDD-find-or-add.cpp
SOURCES += C_BDD-single-operand-ops.cpp
SOURCES += C_BDD-and-operation.cpp
SOURCES += C_BDD_Set1.cpp
SOURCES += C_BDD_Set2.cpp
SOURCES += C_BDD_Set3.cpp
SOURCES += C_BDD_Descriptor.cpp

#--- Files
SOURCES += C_TextFileWrite.cpp
SOURCES += C_HTML_FileWrite.cpp

#--- Streams
SOURCES += AC_OutputStream.cpp
SOURCES += C_ColoredConsole.cpp
SOURCES += C_ConsoleOut.cpp
SOURCES += C_ErrorOut.cpp

#--- Strings
SOURCES += unicode_character_cpp.cpp
SOURCES += unicode_string_routines.cpp
SOURCES += C_String.cpp
SOURCES += md5.cpp

#--- Time
SOURCES += C_Timer.cpp
SOURCES += C_DateTime.cpp

#--- Utilities
SOURCES += F_main.cpp
SOURCES += C_PrologueEpilogue.cpp
SOURCES += C_SharedObject.cpp
SOURCES += F_DisplayException.cpp
SOURCES += MF_Assert.cpp
SOURCES += F_GetPrime.cpp
SOURCES += MF_MemoryControl.cpp
SOURCES += cpp-allocation.cpp
SOURCES += basic-allocation.cpp

#---------------------------------------------------------------*
#    G A L G A S    2                                           *
#---------------------------------------------------------------*

SOURCES += typeComparisonResult.cpp
SOURCES += C_Compiler.cpp
SOURCES += C_Lexique.cpp
SOURCES += C_LocationInSource.cpp
SOURCES += C_SourceTextInString.cpp
SOURCES += C_galgas_type_descriptor.cpp
SOURCES += C_galgas_function_descriptor.cpp
SOURCES += C_galgas_io.cpp
SOURCES += C_galgas_class_inspector.cpp
SOURCES += cObjectArray.cpp
SOURCES += cCollectionElement.cpp
SOURCES += capCollectionElement.cpp
SOURCES += capCollectionElementArray.cpp
SOURCES += cSortedListElement.cpp
SOURCES += capSortedListElement.cpp
SOURCES += cGenericAbstractEnumerator.cpp
SOURCES += cIndexingDictionary.cpp

SOURCES += AC_GALGAS_root.cpp
SOURCES += AC_GALGAS_list.cpp
SOURCES += AC_GALGAS_sortedlist.cpp
SOURCES += AC_GALGAS_map.cpp
SOURCES += AC_GALGAS_uniqueMap.cpp
SOURCES += AC_GALGAS_class.cpp
SOURCES += AC_GALGAS_graph.cpp
SOURCES += acPtr_class.cpp
SOURCES += cPtr_object.cpp

SOURCES += GALGAS_application.cpp
SOURCES += GALGAS_binaryset.cpp
SOURCES += GALGAS_bool.cpp
SOURCES += GALGAS_char.cpp
SOURCES += GALGAS_data.cpp
SOURCES += GALGAS_double.cpp
SOURCES += GALGAS_filewrapper.cpp
SOURCES += GALGAS_function.cpp
SOURCES += GALGAS_location.cpp
SOURCES += GALGAS_sint.cpp
SOURCES += GALGAS_sint_36__34_.cpp
SOURCES += GALGAS_string.cpp
SOURCES += GALGAS_stringset.cpp
SOURCES += GALGAS_type.cpp
SOURCES += GALGAS_object.cpp
SOURCES += GALGAS_uint.cpp
SOURCES += GALGAS_uint_36__34_.cpp
SOURCES += predefined-types.cpp
SOURCES += scanner_actions.cpp

#---------------------------------------------------------------*
