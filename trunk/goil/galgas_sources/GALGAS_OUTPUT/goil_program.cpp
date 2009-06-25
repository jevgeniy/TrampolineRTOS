//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_program.cpp'                           *
//                        Generated by version 1.8.5                         *
//                      june 19th, 2009, at 17h58'12"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if LIBPM_VERSION != 515
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include "utilities/F_DisplayException.h"
#include "utilities/MF_MemoryControl.h"
#include "collections/TC_UniqueArray.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/mainForLIBPM.h"
#include "utilities/MF_MemoryControl.h"

#ifdef TARGET_API_MAC_CARBON
  #include <SIOUX.H>
#endif

#ifdef COMPILE_FOR_WIN32
  #ifdef __MWERKS__
    #include <WINSIOUX.H>
  #endif
#endif

#include <typeinfo>

//---------------------------------------------------------------------------*

#include "goil_grammar.h"
#include "goil_program.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_program.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                 C_options_for_goil_program  CONSTRUCTOR                   *
//                                                                           *
//---------------------------------------------------------------------------*

C_options_for_goil_program::
C_options_for_goil_program (const bool inAcceptsDebugOption) :
mBuiltinOptions (inAcceptsDebugOption),
mGalgasOptions (),
mOptions_goil_options (){
  add (& mBuiltinOptions) ;
  add (& mGalgasOptions) ;
  add (& mOptions_goil_options) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    P R O L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

static void
goil_program_prologue (C_Compiler & /* inLexique */,
                     const TC_UniqueArray <C_String> & /* inSourceFilesArray */) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    E P I L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

static void
goil_program_epilogue (C_Compiler & /* inLexique */,
                     const TC_UniqueArray <C_String> & /* inSourceFilesArray */) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      M A I N    F O R    L I B P M                        *
//                                                                           *
//---------------------------------------------------------------------------*

int mainForLIBPM  (const int argc, const char * argv []) {
  bool verboseOptionOn = true ;
  sint16 returnCode = 0 ; // No error
//--- Fix parameters for BDD package
  C_BDD::setHashMapSize (19) ;
  C_BDD::setITEcacheSize (17) ;
  C_BDD::setANDcacheSize (1) ;
  C_BDD::forAllOnBitsGreaterCacheSize (18) ;
  C_PrologueEpilogueAction::runPrologueActions () ;
  {
  //--- Input/output parameters
    C_options_for_goil_program options (false) ;
    const char * extensions [] = {"oil", "OIL", NULL} ;
    const char * helpMessages [] = {"an '.oil' source file", "an '.OIL' source file", NULL} ;
    TC_UniqueArray <C_String> sourceFilesArray ;
  //--- Analyze Command Line Options
    bool cocoaOutput = false ;
    F_Analyze_CLI_Options (argc, argv,
                           "version 2.0b28",
                           options,
                           sourceFilesArray,
                           extensions,
                           helpMessages,
                           cocoaOutput) ;
    C_galgas_io_parameters IOparameters  (& options,
      cocoaOutput,
      #ifndef DO_NOT_GENERATE_CHECKINGS
        "version 2.0b28" " [debug]",
      #else
        "version 2.0b28",
      #endif
      argv [1]) ;
  //--- Build galgas io object
    C_galgas_io * galgasIOptr = NULL ;
    macroMyNew (galgasIOptr, C_galgas_io (IOparameters, C_galgas_io::kTerminalOutputKind COMMA_HERE)) ;
  //--- Common lexique object
    C_Compiler * _commonLexique = NULL ;
    macroMyNew (_commonLexique, C_Compiler (NULL, "", "", galgasIOptr COMMA_HERE)) ;
  //--- Ask Save On Close ? (Carbon and Windows SIOUX Only)
    #ifdef SIOUX_IS_IMPLEMENTED
      SIOUXSettings.asktosaveonclose = options.boolOptionValueFromKeys ("generic_cli_options",
                                                                        ASK_TO_SAVE_ON_CLOSE,
                                                                        false) ;
    #endif
  //--- Enable 64 bit alloc debug ? Only if compiled in 64 bit and in debug mode
    #ifndef DO_NOT_GENERATE_CHECKINGS
      #ifdef __LP64__
        if (options.boolOptionValueFromKeys ("generic_cli_options",
                                             "enable_allocation_debugging",
                                             false)) {
          enableAllocDebugFor64BitTool () ;
        }
      #endif
    #endif
    try{
      verboseOptionOn = options.boolOptionValueFromKeys ("generic_galgas_cli_options",
                                                         "verbose_output",
                                                         false) ;
      goil_program_prologue (* _commonLexique, sourceFilesArray) ;
      for (sint32 i=0 ; i<sourceFilesArray.count () ; i++) {
        try {
          const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
          sint16 r = 0 ;
          if (fileExtension.compare ("oil") == 0) {
            C_Compiler & inLexique = * _commonLexique ;
            const GGS_string _source (true, sourceFilesArray (i COMMA_HERE)) ;
            const GGS_location _here (inLexique) ;
            const GGS_lstring var_cas_inSourceFile (GGS_lstring::constructor_new (inLexique, _source, _here COMMA_HERE)) ;
            const GGS_string _depExtension = GGS_string ("") ;
            const GGS_string _depPath = GGS_string ("") ;
            if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
              goil_grammar::_performSourceFileParsing_ (inLexique,
                                            _depExtension.string (),
                                            _depPath.string (),
                                            NULL,
                                            var_cas_inSourceFile
                                            COMMA_SOURCE_FILE_AT_LINE (13)) ;
            }
            if (verboseOptionOn) {
              co << "Analysis of '" << sourceFilesArray (i COMMA_HERE).lastPathComponent () << "' completed. " ;
              switch (_commonLexique->totalErrorCount ()) {
              case 0 :
                co << "No error, " ;
                break ;
              case 1 :
                co << "1 error, " ;
                returnCode = 1 ; // Error code
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalErrorCount ()) << " errors, " ;
                returnCode = 1 ; // Error code
                break ;
              }
              switch (_commonLexique->totalWarningCount ()) {
              case 0 :
                co << "no warning" ;
                break ;
              case 1 :
                co << "1 warning" ;
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalWarningCount ()) << " warnings" ;
                break ;
              }
              if (verboseOptionOn || ((_commonLexique->totalErrorCount () + _commonLexique->totalWarningCount ()) > 0)) {
                co << ".\n" ;
              }
            }
          }else if (fileExtension.compare ("OIL") == 0) {
            C_Compiler & inLexique = * _commonLexique ;
            const GGS_string _source (true, sourceFilesArray (i COMMA_HERE)) ;
            const GGS_location _here (inLexique) ;
            const GGS_lstring var_cas_inSourceFile (GGS_lstring::constructor_new (inLexique, _source, _here COMMA_HERE)) ;
            const GGS_string _depExtension = GGS_string ("") ;
            const GGS_string _depPath = GGS_string ("") ;
            if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
              goil_grammar::_performSourceFileParsing_ (inLexique,
                                            _depExtension.string (),
                                            _depPath.string (),
                                            NULL,
                                            var_cas_inSourceFile
                                            COMMA_SOURCE_FILE_AT_LINE (17)) ;
            }
            if (verboseOptionOn) {
              co << "Analysis of '" << sourceFilesArray (i COMMA_HERE).lastPathComponent () << "' completed. " ;
              switch (_commonLexique->totalErrorCount ()) {
              case 0 :
                co << "No error, " ;
                break ;
              case 1 :
                co << "1 error, " ;
                returnCode = 1 ; // Error code
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalErrorCount ()) << " errors, " ;
                returnCode = 1 ; // Error code
                break ;
              }
              switch (_commonLexique->totalWarningCount ()) {
              case 0 :
                co << "no warning" ;
                break ;
              case 1 :
                co << "1 warning" ;
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalWarningCount ()) << " warnings" ;
                break ;
              }
              if (verboseOptionOn || ((_commonLexique->totalErrorCount () + _commonLexique->totalWarningCount ()) > 0)) {
                co << ".\n" ;
              }
            }
          }else{
            printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
            r = 1 ;
          }
          if (r != 0) {
            returnCode = r ;
          }
        }catch (C_ScanOrParseOnlyException) { // Raised when scan only or parse only options are set
          // Do nothing: accept silently exception
        }
      }
    //--- Error or warnings ?
      if (_commonLexique->totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (_commonLexique->totalWarningCount () > 0) {
        const bool warningsAreTreatedAsError
            = options.boolOptionValueFromKeys ("generic_galgas_cli_options",
                                               TREAT_WARNINGS_AS_ERRORS,
                                               false) ;
        if (warningsAreTreatedAsError) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      goil_program_epilogue (* _commonLexique, sourceFilesArray) ;
    }catch (const M_STD_NAMESPACE exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      throw ;
    }
    macroDetachPointer (galgasIOptr, C_galgas_io) ;
    macroDetachPointer (_commonLexique, C_Compiler) ;
    C_PrologueEpilogueAction::runEpilogueActions () ;
    runAllReleaseRoutines () ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    C_GGS_Object::checkAllObjectsHaveBeenReleased () ;
  #endif
  if (verboseOptionOn) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      const uint64 maxUsedMemorySize = getMaxUsedMemorySize () ;
      const uint64 oneMegaByte = 1 << 20 ;
      const uint64 megaBytes = maxUsedMemorySize / oneMegaByte ;
      const uint64 fraction = ((maxUsedMemorySize % oneMegaByte) * 1000) / oneMegaByte ;
      co << cStringWithSigned (getCreatedDynamicObjectsTotalCount ())
         << " C++ objects have been created (" ;
      co.appendUnsigned64 (megaBytes) ;
      co << "." ;
      co.appendUnsignedWithZeroFill ((uint32) fraction, 3) ;
      co << " MB).\n" ;
      deactivateMemoryControl () ;
      if ((getAllocationBalance () != 0) && (returnCode == 0)) {
        display_pointers () ;
      }
    #endif
  }
  return returnCode ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


