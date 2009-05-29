//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'cfg_grammar.cpp'                           *
//                        Generated by version 1.8.3                         *
//                       may 29th, 2009, at 11h56'23"                        *
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

#include "utilities/MF_MemoryControl.h"

//---------------------------------------------------------------------------*

#include "cfg_grammar.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "cfg_grammar.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              L L ( 1 )    P R O D U C T I O N    R U L E S                *
//                                                                           *
//---------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const sint16 gProductions [] = {
// At index 0 : <cfg_attrs>, in file 'cfg_syntax.ggs', line 109
  NONTERMINAL (4) // <select_repeat_cfg_syntax_1>
, END_PRODUCTION
// At index 2 : <cfg_start>, in file 'cfg_syntax.ggs', line 35
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 4 : <interrupts>, in file 'cfg_syntax.ggs', line 121
, TERMINAL (cfg_lexique::cfg_lexique_1_interrupts) // $interrupts$
, TERMINAL (cfg_lexique::cfg_lexique_1__7B) // ${$
, NONTERMINAL (5) // <select_repeat_cfg_syntax_2>
, TERMINAL (cfg_lexique::cfg_lexique_1__7D) // $}$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 10 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, END_PRODUCTION
// At index 11 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, TERMINAL (cfg_lexique::cfg_lexique_1_tp_5Fns_5Fper_5Fcounter_5Ftick) // $tp_ns_per_counter_tick$
, TERMINAL (cfg_lexique::cfg_lexique_1__3D) // $=$
, TERMINAL (cfg_lexique::cfg_lexique_1_uint) // $uint$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 17 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, TERMINAL (cfg_lexique::cfg_lexique_1_stack_5Falignment) // $stack_alignment$
, TERMINAL (cfg_lexique::cfg_lexique_1__3D) // $=$
, TERMINAL (cfg_lexique::cfg_lexique_1_uint) // $uint$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 23 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, TERMINAL (cfg_lexique::cfg_lexique_1_task) // $task$
, TERMINAL (cfg_lexique::cfg_lexique_1__7B) // ${$
, NONTERMINAL (0) // <cfg_attrs>
, TERMINAL (cfg_lexique::cfg_lexique_1__7D) // $}$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 30 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, TERMINAL (cfg_lexique::cfg_lexique_1_isr) // $isr$
, TERMINAL (cfg_lexique::cfg_lexique_1__7B) // ${$
, NONTERMINAL (0) // <cfg_attrs>
, TERMINAL (cfg_lexique::cfg_lexique_1__7D) // $}$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 37 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, TERMINAL (cfg_lexique::cfg_lexique_1_isr_5Fcode) // $isr_code$
, TERMINAL (cfg_lexique::cfg_lexique_1__7B) // ${$
, NONTERMINAL (0) // <cfg_attrs>
, TERMINAL (cfg_lexique::cfg_lexique_1__7D) // $}$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 44 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, TERMINAL (cfg_lexique::cfg_lexique_1_counter_5Fcode) // $counter_code$
, TERMINAL (cfg_lexique::cfg_lexique_1__7B) // ${$
, NONTERMINAL (0) // <cfg_attrs>
, TERMINAL (cfg_lexique::cfg_lexique_1__7D) // $}$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 51 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
, NONTERMINAL (2) // <interrupts>
, NONTERMINAL (3) // <select_repeat_cfg_syntax_0>
, END_PRODUCTION
// At index 54 : <select_repeat_cfg_syntax_1>, in file 'cfg_syntax.ggs', line 113
, END_PRODUCTION
// At index 55 : <select_repeat_cfg_syntax_1>, in file 'cfg_syntax.ggs', line 113
, TERMINAL (cfg_lexique::cfg_lexique_1_idf) // $idf$
, TERMINAL (cfg_lexique::cfg_lexique_1__3D) // $=$
, TERMINAL (cfg_lexique::cfg_lexique_1_idf) // $idf$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (4) // <select_repeat_cfg_syntax_1>
, END_PRODUCTION
// At index 61 : <select_repeat_cfg_syntax_2>, in file 'cfg_syntax.ggs', line 128
, END_PRODUCTION
// At index 62 : <select_repeat_cfg_syntax_2>, in file 'cfg_syntax.ggs', line 128
, TERMINAL (cfg_lexique::cfg_lexique_1_idf) // $idf$
, TERMINAL (cfg_lexique::cfg_lexique_1__3D) // $=$
, TERMINAL (cfg_lexique::cfg_lexique_1_uint) // $uint$
, TERMINAL (cfg_lexique::cfg_lexique_1__3B) // $;$
, NONTERMINAL (5) // <select_repeat_cfg_syntax_2>
, END_PRODUCTION
// At index 68 : <>, in file '.ggs', line 0
, NONTERMINAL (1) // <cfg_start>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O D U C T I O N    N A M E S                      *
//                                                                           *
//---------------------------------------------------------------------------*

static const char * gProductionNames [16] = {
 "<cfg_attrs>, in file 'cfg_syntax.ggs', line 109", // at index 0
 "<cfg_start>, in file 'cfg_syntax.ggs', line 35", // at index 1
 "<interrupts>, in file 'cfg_syntax.ggs', line 121", // at index 2
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 3
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 4
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 5
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 6
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 7
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 8
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 9
 "<select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47", // at index 10
 "<select_repeat_cfg_syntax_1>, in file 'cfg_syntax.ggs', line 113", // at index 11
 "<select_repeat_cfg_syntax_1>, in file 'cfg_syntax.ggs', line 113", // at index 12
 "<select_repeat_cfg_syntax_2>, in file 'cfg_syntax.ggs', line 128", // at index 13
 "<select_repeat_cfg_syntax_2>, in file 'cfg_syntax.ggs', line 128", // at index 14
 "<>, in file '.ggs', line 0" // at index 15
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//            L L ( 1 )    P R O D U C T I O N    I N D E X E S              *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gProductionIndexes [16] = {
0, // index 0 : <cfg_attrs>, in file 'cfg_syntax.ggs', line 109
2, // index 1 : <cfg_start>, in file 'cfg_syntax.ggs', line 35
4, // index 2 : <interrupts>, in file 'cfg_syntax.ggs', line 121
10, // index 3 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
11, // index 4 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
17, // index 5 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
23, // index 6 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
30, // index 7 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
37, // index 8 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
44, // index 9 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
51, // index 10 : <select_repeat_cfg_syntax_0>, in file 'cfg_syntax.ggs', line 47
54, // index 11 : <select_repeat_cfg_syntax_1>, in file 'cfg_syntax.ggs', line 113
55, // index 12 : <select_repeat_cfg_syntax_1>, in file 'cfg_syntax.ggs', line 113
61, // index 13 : <select_repeat_cfg_syntax_2>, in file 'cfg_syntax.ggs', line 128
62, // index 14 : <select_repeat_cfg_syntax_2>, in file 'cfg_syntax.ggs', line 128
68 // index 15 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//      L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S       *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gFirstProductionIndexes [8] = {
0, // at 0 : <cfg_attrs>
1, // at 1 : <cfg_start>
2, // at 2 : <interrupts>
3, // at 3 : <select_repeat_cfg_syntax_0>
11, // at 4 : <select_repeat_cfg_syntax_1>
13, // at 5 : <select_repeat_cfg_syntax_2>
15, // at 6 : <>
0} ;

//---------------------------------------------------------------------------*
//                                                                           *
//               L L ( 1 )    D E C I S I O N    T A B L E S                 *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gDecision [] = {
// At index 0 : <cfg_attrs> only one production, no choice
  -1,
// At index 1 : <cfg_start> only one production, no choice
  -1,
// At index 2 : <interrupts> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 3 : <select_repeat_cfg_syntax_0>
cfg_lexique::cfg_lexique_1_, -1, // Choice 1
cfg_lexique::cfg_lexique_1_tp_5Fns_5Fper_5Fcounter_5Ftick, -1, // Choice 2
cfg_lexique::cfg_lexique_1_stack_5Falignment, -1, // Choice 3
cfg_lexique::cfg_lexique_1_task, -1, // Choice 4
cfg_lexique::cfg_lexique_1_isr, -1, // Choice 5
cfg_lexique::cfg_lexique_1_isr_5Fcode, -1, // Choice 6
cfg_lexique::cfg_lexique_1_counter_5Fcode, -1, // Choice 7
cfg_lexique::cfg_lexique_1_interrupts, -1, // Choice 8
  -1,
// At index 20 : <select_repeat_cfg_syntax_1>
cfg_lexique::cfg_lexique_1__7D, -1, // Choice 1
cfg_lexique::cfg_lexique_1_idf, -1, // Choice 2
  -1,
// At index 25 : <select_repeat_cfg_syntax_2>
cfg_lexique::cfg_lexique_1__7D, -1, // Choice 1
cfg_lexique::cfg_lexique_1_idf, -1, // Choice 2
  -1,
// At index 30 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------*
//                                                                           *
//       L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S        *
//                                                                           *
//---------------------------------------------------------------------------*

static const sint16 gDecisionIndexes [8] = {
0, // at 0 : <cfg_attrs>
1, // at 1 : <cfg_start>
2, // at 2 : <interrupts>
3, // at 3 : <select_repeat_cfg_syntax_0>
20, // at 4 : <select_repeat_cfg_syntax_1>
25, // at 5 : <select_repeat_cfg_syntax_2>
30, // at 6 : <>
0} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 'cfg_attrs' non terminal implementation                   *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_grammar::
nt_cfg_attrs_ (cfg_lexique & _inLexique,
                                GGS_cfg_attrs & parameter_1) {
pr_cfg_attrs_cfg_syntax_109_16_ (_inLexique, parameter_1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 'cfg_start' non terminal implementation                   *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_grammar::
nt_cfg_start_ (cfg_lexique & _inLexique,
                                GGS_config & parameter_1) {
pr_cfg_start_cfg_syntax_35_16_ (_inLexique, parameter_1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   Grammar start symbol implementation                     *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_grammar::_performSourceFileParsing_ (C_Compiler & _inCompiler,
                                const C_String & _inDependancyExtension,
                                const C_String & _inDependancyPath,
                                GGS_string * _inSentStringPtr,
                                const GGS_lstring _inFileName,
                                GGS_config & parameter_1
                                COMMA_LOCATION_ARGS) {
  const C_String sourceFileName = _inFileName.string ().isAbsolutePath ()
    ? _inFileName.string ()
    : _inCompiler.sourceFileName ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (_inFileName.string ()) ;
  if (sourceFileName.fileExists ()) {
    cfg_lexique * scanner_ = NULL ;
    macroMyNew (scanner_, cfg_lexique (& _inCompiler, _inDependancyExtension, _inDependancyPath, _inCompiler.ioParametersPtr (), sourceFileName COMMA_HERE)) ;
    if (scanner_->needsCompiling ()) {
      if (scanner_->sourceText () != NULL) {
        scanner_->mPerformGeneration = _inCompiler.mPerformGeneration ;
        const bool ok = scanner_->performTopDownParsing (gProductions, gProductionNames, gProductionIndexes,
                                                         gFirstProductionIndexes, gDecision, gDecisionIndexes, 68) ;
        if (ok && ! scanner_->mParseOnlyFlag) {
          cfg_grammar _grammar ;
          _grammar.nt_cfg_start_ (*scanner_, parameter_1) ;
          if (_inSentStringPtr != NULL) {
            _inSentStringPtr->_dotAssign_operation (scanner_->sentString ()) ;
          }
        }
      }else{
        C_String message ;
        message << "the '" << sourceFileName << "' file exits, but cannot be read" ;
        _inFileName.signalSemanticError (_inCompiler, message COMMA_THERE) ;
        parameter_1.drop () ;
      }
    }
    macroDetachPointer (scanner_, cfg_lexique) ;
  }else{
    C_String message ;
    message << "the '" << sourceFileName << "' file does not exist" ;
    _inFileName.signalSemanticError (_inCompiler, message COMMA_THERE) ;
    parameter_1.drop () ;
  }
}

//---------------------------------------------------------------------------*

void cfg_grammar::_performSourceStringParsing_ (C_Compiler & _inCompiler,
                                GGS_string * _inSentStringPtr,
                                const GGS_string _inSourceString,
                                GGS_config & parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  cfg_lexique * scanner_ = NULL ;
  macroMyNew (scanner_, cfg_lexique (& _inCompiler, _inCompiler.ioParametersPtr (), _inSourceString.string (), "Error when parsing dynamic string" COMMA_HERE)) ;
  scanner_->mPerformGeneration = _inCompiler.mPerformGeneration ;
  const bool ok = scanner_->performTopDownParsing (gProductions, gProductionNames, gProductionIndexes,
                                                   gFirstProductionIndexes, gDecision, gDecisionIndexes, 68) ;
  if (ok && ! scanner_->mParseOnlyFlag) {
    cfg_grammar _grammar ;
    _grammar.nt_cfg_start_ (*scanner_, parameter_1) ;
    if (_inSentStringPtr != NULL) {
      _inSentStringPtr->_dotAssign_operation (scanner_->sentString ()) ;
    }
  }
  macroDetachPointer (scanner_, cfg_lexique) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 'interrupts' non terminal implementation                  *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_grammar::
nt_interrupts_ (cfg_lexique & _inLexique,
                                GGS_basic_type & parameter_1) {
pr_interrupts_cfg_syntax_121_17_ (_inLexique, parameter_1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//      'select_repeat_cfg_syntax_0' added non terminal implementation       *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 cfg_grammar::select_repeat_cfg_syntax_0 (cfg_lexique & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//      'select_repeat_cfg_syntax_1' added non terminal implementation       *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 cfg_grammar::select_repeat_cfg_syntax_1 (cfg_lexique & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//      'select_repeat_cfg_syntax_2' added non terminal implementation       *
//                                                                           *
//---------------------------------------------------------------------------*


sint16 cfg_grammar::select_repeat_cfg_syntax_2 (cfg_lexique & _inLexique) {
  return _inLexique.nextProductionIndex () ;
}

//---------------------------------------------------------------------------*

