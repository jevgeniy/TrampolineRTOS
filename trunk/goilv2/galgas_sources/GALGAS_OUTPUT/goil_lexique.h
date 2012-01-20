//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_lexique.h'                            *
//                    Generated by version version 2.2.7                     *
//                     december 7th, 2011, at 9h11'43"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


#ifndef goil_5F_lexique_CLASS_DEFINED
#define goil_5F_lexique_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/C_Lexique.h"
#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    R O U T I N E S                         *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    F U N C T I O N S                       *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                       T O K E N    C L A S S                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cTokenFor_goil_5F_lexique : public cToken {
  public : C_String mLexicalAttribute_a_5F_string ;
  public : C_String mLexicalAttribute_att_5F_token ;
  public : double mLexicalAttribute_floatNumber ;
  public : PMUInt64 mLexicalAttribute_integerNumber ;
  public : C_String mLexicalAttribute_number ;

  public : cTokenFor_goil_5F_lexique (void) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     S C A N N E R    C L A S S                            *
//                                                                           *
//---------------------------------------------------------------------------*

class C_Lexique_goil_5F_lexique : public C_Lexique {
//--- Constructors
  public : C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~ C_Lexique_goil_5F_lexique (void) {}
  #endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


//--- Terminal symbols enumeration
  public : enum {kToken_,
   kToken_comment,
   kToken_idf,
   kToken_string,
   kToken_g_5F_string,
   kToken_uint_5F_number,
   kToken_float_5F_number,
   kToken_set_5F_start_5F_uint_5F_number,
   kToken_command,
   kToken_OIL_5F_VERSION,
   kToken_IMPLEMENTATION,
   kToken_CPU,
   kToken_UINT_33__32_,
   kToken_INT_33__32_,
   kToken_UINT_36__34_,
   kToken_INT_36__34_,
   kToken_FLOAT,
   kToken_ENUM,
   kToken_STRING,
   kToken_BOOLEAN,
   kToken_IDENTIFIER,
   kToken_STRUCT,
   kToken_WITH_5F_AUTO,
   kToken_NO_5F_DEFAULT,
   kToken_AUTO,
   kToken_FALSE,
   kToken_TRUE,
   kToken__3B_,
   kToken__3A_,
   kToken__3D_,
   kToken__7B_,
   kToken__7D_,
   kToken__2E__2E_,
   kToken__5B_,
   kToken__5D_,
   kToken__2C_,
   kToken__2E_,
   kToken__2B_,
   kToken__2D_,
   kToken_include} ;

//--- Key words table 'oilVersion'
  public : static PMSInt16 search_into_oilVersion (const C_String & inSearchedString) ;

//--- Key words table 'oilDefinitions'
  public : static PMSInt16 search_into_oilDefinitions (const C_String & inSearchedString) ;

//--- Key words table 'dataTypes'
  public : static PMSInt16 search_into_dataTypes (const C_String & inSearchedString) ;

//--- Key words table 'miscSpecifiers'
  public : static PMSInt16 search_into_miscSpecifiers (const C_String & inSearchedString) ;

//--- Key words table 'boolean'
  public : static PMSInt16 search_into_boolean (const C_String & inSearchedString) ;

//--- Key words table 'OILDelimiters'
  public : static PMSInt16 search_into_OILDelimiters (const C_String & inSearchedString) ;

//--- Key words table 'commands'
  public : static PMSInt16 search_into_commands (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : GALGAS_lstring synthetizedAttribute_a_5F_string (void) const ;
  public : GALGAS_lstring synthetizedAttribute_att_5F_token (void) const ;
  public : GALGAS_ldouble synthetizedAttribute_floatNumber (void) const ;
  public : GALGAS_luint_36__34_ synthetizedAttribute_integerNumber (void) const ;
  public : GALGAS_lstring synthetizedAttribute_number (void) const ;


//--- Attribute access
  public : C_String attributeValue_a_5F_string (void) const ;
  public : C_String attributeValue_att_5F_token (void) const ;
  public : double attributeValue_floatNumber (void) const ;
  public : PMUInt64 attributeValue_integerNumber (void) const ;
  public : C_String attributeValue_number (void) const ;


//--- Indexing keys

//--- Indexing directory
  protected : virtual C_String indexingDirectory (void) const ;

//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Append terminal message
  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const PMSInt16 numeroTerminal,
                                                              C_String & messageErreur) ;

//--- Get terminal count
  public : virtual PMSInt16 terminalVocabularyCount (void) const { return 39 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (const cTokenFor_goil_5F_lexique & inToken) ;
} ;

//---------------------------------------------------------------------------*

#endif
