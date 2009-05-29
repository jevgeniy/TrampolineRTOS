//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'cfg_lexique.h'                            *
//                        Generated by version 1.8.3                         *
//                       may 29th, 2009, at 11h56'23"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef cfg_lexique_0_DEFINED
#define cfg_lexique_0_DEFINED

//---------------------------------------------------------------------------*

#include "galgas/GGS_lstring.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_lbool.h"

//---------------------------------------------------------------------------*

#include "galgas/C_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                          Lexical scanner class                            *
//                                                                           *
//---------------------------------------------------------------------------*

class cTokenFor_cfg_lexique : public cToken {
  public : C_String keyword ; // user defined attribute
  public : C_String string ; // user defined attribute
  public : uint64 integer ; // user defined attribute
  public : C_String number ; // user defined attribute

  public : cTokenFor_cfg_lexique (void) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Lexical scanner class                            *
//                                                                           *
//---------------------------------------------------------------------------*

class cfg_lexique : public C_Lexique {
//--- Constructors
  public : cfg_lexique (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : cfg_lexique (C_Compiler * inCallerCompiler,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cfg_lexique (void) {}
  #endif

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//--- Terminal symbols enumeration
  public : enum {cfg_lexique_1_,
  cfg_lexique_1_tp_5Fns_5Fper_5Fcounter_5Ftick,
  cfg_lexique_1_stack_5Falignment,
  cfg_lexique_1_task,
  cfg_lexique_1_isr,
  cfg_lexique_1_isr_5Fcode,
  cfg_lexique_1_counter_5Fcode,
  cfg_lexique_1_interrupts,
  cfg_lexique_1_uint8,
  cfg_lexique_1_sint8,
  cfg_lexique_1_uint16,
  cfg_lexique_1_sint16,
  cfg_lexique_1_uint32,
  cfg_lexique_1_sint32,
  cfg_lexique_1_uint64,
  cfg_lexique_1_sint64,
  cfg_lexique_1_idf,
  cfg_lexique_1_string,
  cfg_lexique_1_uint,
  cfg_lexique_1__3B,
  cfg_lexique_1__3D,
  cfg_lexique_1__7B,
  cfg_lexique_1__7D} ;

//--- Key words table 'cfg_keywords'
  public : static sint16 search_into_cfg_keywords (const C_String & inSearchedString) ;

//--- Key words table 'cfg_type'
  public : static sint16 search_into_cfg_type (const C_String & inSearchedString) ;

//--- Key words table 'cfg_delimiters'
  public : static sint16 search_into_cfg_delimiters (const C_String & inSearchedString) ;

  protected : virtual bool parseLexicalToken (void) ;
  protected : virtual sint16 parseLexicalTokenForLexicalColoring (void) ;
  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const sint16 numeroTerminal,
                                                              C_String & messageErreur) ;

//--- Get attribute values
  public : void _assignFromAttribute_keyword (GGS_lstring & outValue) const ;
  public : C_String _attributeValue_keyword (void) const ;
  public : void _assignFromAttribute_string (GGS_lstring & outValue) const ;
  public : C_String _attributeValue_string (void) const ;
  public : void _assignFromAttribute_integer (GGS_luint64 & outValue) const ;
  public : uint64 _attributeValue_integer (void) const ;
  public : void _assignFromAttribute_number (GGS_lstring & outValue) const ;
  public : C_String _attributeValue_number (void) const ;
//--- Get terminal count
  public : virtual sint16 terminalVocabularyCount (void) const { return 22 ; }
//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;
//--- Enter Token
  protected : void enterToken (const cTokenFor_cfg_lexique & inToken) ;
//--- Style Definition
  public : static sint32 getStylesCount (void) ;
  public : static const char * getStyleName (const sint32 inIndex) ;
  public : static const char * getStyleIdentifier (const sint32 inIndex) ;
//--- Virtual method called getting terminal style index
  public : virtual uint8 terminalStyleIndex (const sint32 inTerminal) ;
} ;

//---------------------------------------------------------------------------*

#endif
