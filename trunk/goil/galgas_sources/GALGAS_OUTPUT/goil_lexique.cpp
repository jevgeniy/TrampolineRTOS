//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_lexique.cpp'                           *
//                Generated by version 1.3.1 (LL(1) grammar)                 *
//                     october 10th, 2006, at 11h3'17"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include <ctype.h>
#include <string.h>

#include "goil_lexique.h"

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE sourceText ()->sourceFileName ().cString (), currentLineNumber ()
  #define COMMA_LINE_AND_SOURCE_FILE , LINE_AND_SOURCE_FILE
#else
  #define LINE_AND_SOURCE_FILE
  #define COMMA_LINE_AND_SOURCE_FILE
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                               Constructor                                 *
//                                                                           *
//---------------------------------------------------------------------------*

goil_lexique::
goil_lexique (AC_galgas_io * inGalgasInputOutput COMMA_LOCATION_ARGS)
: C_Lexique (inGalgasInputOutput COMMA_THERE) {
  a_string.clear () ;
  att_token.clear () ;
  floatNumber = 0.0 ;
  integerNumber = 0 ;
  number.clear () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        Lexical error message list                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Message 0 (internalError) :
static const char * gErrorMessage_0 = "internal error" ;
//--- Message 1 (decimalNumberTooLarge) :
static const char * gErrorMessage_1 = "decimal number too large" ;
//--- Message 2 (unterminatedLitteralString) :
static const char * gErrorMessage_2 = "Unterminated litteral string" ;
//--- Message 3 (unableToConvertToDouble) :
static const char * gErrorMessage_3 = "Unable to convert the string to double" ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Syntax error messages                            *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Syntax error message for terminal '$OIL_VERSION$' :
static const char * gSyntaxErrorMessage_OIL_5FVERSION = "OIL version" ;
//--- Syntax error message for terminal '$IMPLEMENTATION$' :
static const char * gSyntaxErrorMessage_IMPLEMENTATION = "OIL implementation definition" ;
//--- Syntax error message for terminal '$OS$' :
static const char * gSyntaxErrorMessage_OS = "Object %K" ;
//--- Syntax error message for terminal '$TASK$' :
static const char * gSyntaxErrorMessage_TASK = "Object %K" ;
//--- Syntax error message for terminal '$COUNTER$' :
static const char * gSyntaxErrorMessage_COUNTER = "Object %K" ;
//--- Syntax error message for terminal '$ALARM$' :
static const char * gSyntaxErrorMessage_ALARM = "Object %K" ;
//--- Syntax error message for terminal '$RESOURCE$' :
static const char * gSyntaxErrorMessage_RESOURCE = "Object %K" ;
//--- Syntax error message for terminal '$EVENT$' :
static const char * gSyntaxErrorMessage_EVENT = "Object %K" ;
//--- Syntax error message for terminal '$ISR$' :
static const char * gSyntaxErrorMessage_ISR = "Object %K" ;
//--- Syntax error message for terminal '$MESSAGE$' :
static const char * gSyntaxErrorMessage_MESSAGE = "Object %K" ;
//--- Syntax error message for terminal '$COM$' :
static const char * gSyntaxErrorMessage_COM = "Object %K" ;
//--- Syntax error message for terminal '$NM$' :
static const char * gSyntaxErrorMessage_NM = "Object %K" ;
//--- Syntax error message for terminal '$APPMODE$' :
static const char * gSyntaxErrorMessage_APPMODE = "Object %K" ;
//--- Syntax error message for terminal '$IPDU$' :
static const char * gSyntaxErrorMessage_IPDU = "Object %K" ;
//--- Syntax error message for terminal '$CPU$' :
static const char * gSyntaxErrorMessage_CPU = "Object %K" ;
//--- Syntax error message for terminal '$UINT32$' :
static const char * gSyntaxErrorMessage_UINT32 = "type %K" ;
//--- Syntax error message for terminal '$INT32$' :
static const char * gSyntaxErrorMessage_INT32 = "type %K" ;
//--- Syntax error message for terminal '$UINT64$' :
static const char * gSyntaxErrorMessage_UINT64 = "type %K" ;
//--- Syntax error message for terminal '$INT64$' :
static const char * gSyntaxErrorMessage_INT64 = "type %K" ;
//--- Syntax error message for terminal '$FLOAT$' :
static const char * gSyntaxErrorMessage_FLOAT = "type %K" ;
//--- Syntax error message for terminal '$ENUM$' :
static const char * gSyntaxErrorMessage_ENUM = "type %K" ;
//--- Syntax error message for terminal '$STRING$' :
static const char * gSyntaxErrorMessage_STRING = "type %K" ;
//--- Syntax error message for terminal '$BOOLEAN$' :
static const char * gSyntaxErrorMessage_BOOLEAN = "type %K" ;
//--- Syntax error message for terminal '$WITH_AUTO$' :
static const char * gSyntaxErrorMessage_WITH_5FAUTO = "specifier %K" ;
//--- Syntax error message for terminal '$NO_DEFAULT$' :
static const char * gSyntaxErrorMessage_NO_5FDEFAULT = "specifier %K" ;
//--- Syntax error message for terminal '$AUTO$' :
static const char * gSyntaxErrorMessage_AUTO = "specifier %K" ;
//--- Syntax error message for terminal '$TRUE$' :
static const char * gSyntaxErrorMessage_TRUE = "specifier %K" ;
//--- Syntax error message for terminal '$FALSE$' :
static const char * gSyntaxErrorMessage_FALSE = "specifier %K" ;
//--- Syntax error message for terminal '$OS_TYPE$' :
static const char * gSyntaxErrorMessage_OS_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$TASK_TYPE$' :
static const char * gSyntaxErrorMessage_TASK_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$COUNTER_TYPE$' :
static const char * gSyntaxErrorMessage_COUNTER_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$ALARM_TYPE$' :
static const char * gSyntaxErrorMessage_ALARM_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$RESOURCE_TYPE$' :
static const char * gSyntaxErrorMessage_RESOURCE_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$EVENT_TYPE$' :
static const char * gSyntaxErrorMessage_EVENT_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$ISR_TYPE$' :
static const char * gSyntaxErrorMessage_ISR_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$MESSAGE_TYPE$' :
static const char * gSyntaxErrorMessage_MESSAGE_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$COM_TYPE$' :
static const char * gSyntaxErrorMessage_COM_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$NM_TYPE$' :
static const char * gSyntaxErrorMessage_NM_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$APPMODE_TYPE$' :
static const char * gSyntaxErrorMessage_APPMODE_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$IPDU_TYPE$' :
static const char * gSyntaxErrorMessage_IPDU_5FTYPE = "object reference type %K" ;
//--- Syntax error message for terminal '$idf$' :
static const char * gSyntaxErrorMessage_idf = "identifier" ;
//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage__3B = "';' delimiter" ;
//--- Syntax error message for terminal '$:$' :
static const char * gSyntaxErrorMessage__3A = "':' delimiter" ;
//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage__3D = "'=' delimiter" ;
//--- Syntax error message for terminal '${$' :
static const char * gSyntaxErrorMessage__7B = "'{' delimiter" ;
//--- Syntax error message for terminal '$}$' :
static const char * gSyntaxErrorMessage__7D = "'}' delimiter" ;
//--- Syntax error message for terminal '$..$' :
static const char * gSyntaxErrorMessage__2E_2E = "'..' delimiter" ;
//--- Syntax error message for terminal '$[$' :
static const char * gSyntaxErrorMessage__5B = "'[' delimiter" ;
//--- Syntax error message for terminal '$]$' :
static const char * gSyntaxErrorMessage__5D = "']' delimiter" ;
//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage__2C = "',' delimiter" ;
//--- Syntax error message for terminal '$.$' :
static const char * gSyntaxErrorMessage__2E = "'.' delimiter" ;
//--- Syntax error message for terminal '$string$' :
static const char * gSyntaxErrorMessage_string = "litteral string" ;
//--- Syntax error message for terminal '$uint_number$' :
static const char * gSyntaxErrorMessage_uint_5Fnumber = "litteral unsigned 32 bits integer" ;
//--- Syntax error message for terminal '$float_number$' :
static const char * gSyntaxErrorMessage_float_5Fnumber = "litteral float" ;
//---------------------------------------------------------------------------*

void goil_lexique::
appendTerminalMessageToSyntaxErrorMessage (const sint16 inTerminalIndex,
                                           C_String & outSyntaxErrorMessage) {
  static const char * syntaxErrorMessageArray [55] = {"end of source",
       gSyntaxErrorMessage_OIL_5FVERSION,
       gSyntaxErrorMessage_IMPLEMENTATION,
       gSyntaxErrorMessage_OS,
       gSyntaxErrorMessage_TASK,
       gSyntaxErrorMessage_COUNTER,
       gSyntaxErrorMessage_ALARM,
       gSyntaxErrorMessage_RESOURCE,
       gSyntaxErrorMessage_EVENT,
       gSyntaxErrorMessage_ISR,
       gSyntaxErrorMessage_MESSAGE,
       gSyntaxErrorMessage_COM,
       gSyntaxErrorMessage_NM,
       gSyntaxErrorMessage_APPMODE,
       gSyntaxErrorMessage_IPDU,
       gSyntaxErrorMessage_CPU,
       gSyntaxErrorMessage_UINT32,
       gSyntaxErrorMessage_INT32,
       gSyntaxErrorMessage_UINT64,
       gSyntaxErrorMessage_INT64,
       gSyntaxErrorMessage_FLOAT,
       gSyntaxErrorMessage_ENUM,
       gSyntaxErrorMessage_STRING,
       gSyntaxErrorMessage_BOOLEAN,
       gSyntaxErrorMessage_WITH_5FAUTO,
       gSyntaxErrorMessage_NO_5FDEFAULT,
       gSyntaxErrorMessage_AUTO,
       gSyntaxErrorMessage_TRUE,
       gSyntaxErrorMessage_FALSE,
       gSyntaxErrorMessage_OS_5FTYPE,
       gSyntaxErrorMessage_TASK_5FTYPE,
       gSyntaxErrorMessage_COUNTER_5FTYPE,
       gSyntaxErrorMessage_ALARM_5FTYPE,
       gSyntaxErrorMessage_RESOURCE_5FTYPE,
       gSyntaxErrorMessage_EVENT_5FTYPE,
       gSyntaxErrorMessage_ISR_5FTYPE,
       gSyntaxErrorMessage_MESSAGE_5FTYPE,
       gSyntaxErrorMessage_COM_5FTYPE,
       gSyntaxErrorMessage_NM_5FTYPE,
       gSyntaxErrorMessage_APPMODE_5FTYPE,
       gSyntaxErrorMessage_IPDU_5FTYPE,
       gSyntaxErrorMessage_idf,
       gSyntaxErrorMessage__3B,
       gSyntaxErrorMessage__3A,
       gSyntaxErrorMessage__3D,
       gSyntaxErrorMessage__7B,
       gSyntaxErrorMessage__7D,
       gSyntaxErrorMessage__2E_2E,
       gSyntaxErrorMessage__5B,
       gSyntaxErrorMessage__5D,
       gSyntaxErrorMessage__2C,
       gSyntaxErrorMessage__2E,
       gSyntaxErrorMessage_string,
       gSyntaxErrorMessage_uint_5Fnumber,
       gSyntaxErrorMessage_float_5Fnumber} ;
  outSyntaxErrorMessage << syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Key words table 'OILDelimiters'                       *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_OILDelimiters = 10 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_OILDelimiters [10] = {
  C_lexique_table_entry (",", 1, goil_lexique_1__2C),
  C_lexique_table_entry (".", 1, goil_lexique_1__2E),
  C_lexique_table_entry (":", 1, goil_lexique_1__3A),
  C_lexique_table_entry (";", 1, goil_lexique_1__3B),
  C_lexique_table_entry ("=", 1, goil_lexique_1__3D),
  C_lexique_table_entry ("[", 1, goil_lexique_1__5B),
  C_lexique_table_entry ("]", 1, goil_lexique_1__5D),
  C_lexique_table_entry ("{", 1, goil_lexique_1__7B),
  C_lexique_table_entry ("}", 1, goil_lexique_1__7D),
  C_lexique_table_entry ("..", 2, goil_lexique_1__2E_2E)
} ;

sint16 goil_lexique::search_into_OILDelimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_OILDelimiters, goil_lexique_table_size_OILDelimiters) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       Key words table 'dataTypes'                         *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_dataTypes = 8 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_dataTypes [8] = {
  C_lexique_table_entry ("ENUM", 4, goil_lexique_1_ENUM),
  C_lexique_table_entry ("FLOAT", 5, goil_lexique_1_FLOAT),
  C_lexique_table_entry ("INT32", 5, goil_lexique_1_INT32),
  C_lexique_table_entry ("INT64", 5, goil_lexique_1_INT64),
  C_lexique_table_entry ("STRING", 6, goil_lexique_1_STRING),
  C_lexique_table_entry ("UINT32", 6, goil_lexique_1_UINT32),
  C_lexique_table_entry ("UINT64", 6, goil_lexique_1_UINT64),
  C_lexique_table_entry ("BOOLEAN", 7, goil_lexique_1_BOOLEAN)
} ;

sint16 goil_lexique::search_into_dataTypes (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_dataTypes, goil_lexique_table_size_dataTypes) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Key words table 'miscSpecifiers'                      *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_miscSpecifiers = 5 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_miscSpecifiers [5] = {
  C_lexique_table_entry ("AUTO", 4, goil_lexique_1_AUTO),
  C_lexique_table_entry ("TRUE", 4, goil_lexique_1_TRUE),
  C_lexique_table_entry ("FALSE", 5, goil_lexique_1_FALSE),
  C_lexique_table_entry ("WITH_AUTO", 9, goil_lexique_1_WITH_5FAUTO),
  C_lexique_table_entry ("NO_DEFAULT", 10, goil_lexique_1_NO_5FDEFAULT)
} ;

sint16 goil_lexique::search_into_miscSpecifiers (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_miscSpecifiers, goil_lexique_table_size_miscSpecifiers) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        Key words table 'objList'                          *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_objList = 13 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_objList [13] = {
  C_lexique_table_entry ("NM", 2, goil_lexique_1_NM),
  C_lexique_table_entry ("OS", 2, goil_lexique_1_OS),
  C_lexique_table_entry ("COM", 3, goil_lexique_1_COM),
  C_lexique_table_entry ("CPU", 3, goil_lexique_1_CPU),
  C_lexique_table_entry ("ISR", 3, goil_lexique_1_ISR),
  C_lexique_table_entry ("IPDU", 4, goil_lexique_1_IPDU),
  C_lexique_table_entry ("TASK", 4, goil_lexique_1_TASK),
  C_lexique_table_entry ("ALARM", 5, goil_lexique_1_ALARM),
  C_lexique_table_entry ("EVENT", 5, goil_lexique_1_EVENT),
  C_lexique_table_entry ("APPMODE", 7, goil_lexique_1_APPMODE),
  C_lexique_table_entry ("COUNTER", 7, goil_lexique_1_COUNTER),
  C_lexique_table_entry ("MESSAGE", 7, goil_lexique_1_MESSAGE),
  C_lexique_table_entry ("RESOURCE", 8, goil_lexique_1_RESOURCE)
} ;

sint16 goil_lexique::search_into_objList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_objList, goil_lexique_table_size_objList) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Key words table 'objectRefType'                       *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_objectRefType = 12 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_objectRefType [12] = {
  C_lexique_table_entry ("NM_TYPE", 7, goil_lexique_1_NM_5FTYPE),
  C_lexique_table_entry ("OS_TYPE", 7, goil_lexique_1_OS_5FTYPE),
  C_lexique_table_entry ("COM_TYPE", 8, goil_lexique_1_COM_5FTYPE),
  C_lexique_table_entry ("ISR_TYPE", 8, goil_lexique_1_ISR_5FTYPE),
  C_lexique_table_entry ("IPDU_TYPE", 9, goil_lexique_1_IPDU_5FTYPE),
  C_lexique_table_entry ("TASK_TYPE", 9, goil_lexique_1_TASK_5FTYPE),
  C_lexique_table_entry ("ALARM_TYPE", 10, goil_lexique_1_ALARM_5FTYPE),
  C_lexique_table_entry ("EVENT_TYPE", 10, goil_lexique_1_EVENT_5FTYPE),
  C_lexique_table_entry ("APPMODE_TYPE", 12, goil_lexique_1_APPMODE_5FTYPE),
  C_lexique_table_entry ("COUNTER_TYPE", 12, goil_lexique_1_COUNTER_5FTYPE),
  C_lexique_table_entry ("MESSAGE_TYPE", 12, goil_lexique_1_MESSAGE_5FTYPE),
  C_lexique_table_entry ("RESOURCE_TYPE", 13, goil_lexique_1_RESOURCE_5FTYPE)
} ;

sint16 goil_lexique::search_into_objectRefType (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_objectRefType, goil_lexique_table_size_objectRefType) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Key words table 'oilDefinitions'                      *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_oilDefinitions = 1 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_oilDefinitions [1] = {
  C_lexique_table_entry ("IMPLEMENTATION", 14, goil_lexique_1_IMPLEMENTATION)
} ;

sint16 goil_lexique::search_into_oilDefinitions (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_oilDefinitions, goil_lexique_table_size_oilDefinitions) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       Key words table 'oilVersion'                        *
//                                                                           *
//---------------------------------------------------------------------------*

const sint16 goil_lexique::goil_lexique_table_size_oilVersion = 1 ;

const C_lexique_table_entry goil_lexique::goil_lexique_table_for_oilVersion [1] = {
  C_lexique_table_entry ("OIL_VERSION", 11, goil_lexique_1_OIL_5FVERSION)
} ;

sint16 goil_lexique::search_into_oilVersion (const C_String & inSearchedString) {
  return searchInList (inSearchedString, goil_lexique_table_for_oilVersion, goil_lexique_table_size_oilVersion) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Get next token : method 'parseLexicalToken'                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_String goil_lexique::
getCurrentTokenString (void) const {
  C_String s ;
  switch (mCurrentTokenCode) {
  case  goil_lexique_1_:
    s << "$$" ;
    break ;
  case  goil_lexique_1_OIL_5FVERSION:
    s << '$'
      << "OIL_VERSION"
      << '$' ;
    break;
  case  goil_lexique_1_IMPLEMENTATION:
    s << '$'
      << "IMPLEMENTATION"
      << '$' ;
    break;
  case  goil_lexique_1_OS:
    s << '$'
      << "OS"
      << '$' ;
    break;
  case  goil_lexique_1_TASK:
    s << '$'
      << "TASK"
      << '$' ;
    break;
  case  goil_lexique_1_COUNTER:
    s << '$'
      << "COUNTER"
      << '$' ;
    break;
  case  goil_lexique_1_ALARM:
    s << '$'
      << "ALARM"
      << '$' ;
    break;
  case  goil_lexique_1_RESOURCE:
    s << '$'
      << "RESOURCE"
      << '$' ;
    break;
  case  goil_lexique_1_EVENT:
    s << '$'
      << "EVENT"
      << '$' ;
    break;
  case  goil_lexique_1_ISR:
    s << '$'
      << "ISR"
      << '$' ;
    break;
  case  goil_lexique_1_MESSAGE:
    s << '$'
      << "MESSAGE"
      << '$' ;
    break;
  case  goil_lexique_1_COM:
    s << '$'
      << "COM"
      << '$' ;
    break;
  case  goil_lexique_1_NM:
    s << '$'
      << "NM"
      << '$' ;
    break;
  case  goil_lexique_1_APPMODE:
    s << '$'
      << "APPMODE"
      << '$' ;
    break;
  case  goil_lexique_1_IPDU:
    s << '$'
      << "IPDU"
      << '$' ;
    break;
  case  goil_lexique_1_CPU:
    s << '$'
      << "CPU"
      << '$' ;
    break;
  case  goil_lexique_1_UINT32:
    s << '$'
      << "UINT32"
      << '$' ;
    break;
  case  goil_lexique_1_INT32:
    s << '$'
      << "INT32"
      << '$' ;
    break;
  case  goil_lexique_1_UINT64:
    s << '$'
      << "UINT64"
      << '$' ;
    break;
  case  goil_lexique_1_INT64:
    s << '$'
      << "INT64"
      << '$' ;
    break;
  case  goil_lexique_1_FLOAT:
    s << '$'
      << "FLOAT"
      << '$' ;
    break;
  case  goil_lexique_1_ENUM:
    s << '$'
      << "ENUM"
      << '$' ;
    break;
  case  goil_lexique_1_STRING:
    s << '$'
      << "STRING"
      << '$' ;
    break;
  case  goil_lexique_1_BOOLEAN:
    s << '$'
      << "BOOLEAN"
      << '$' ;
    break;
  case  goil_lexique_1_WITH_5FAUTO:
    s << '$'
      << "WITH_AUTO"
      << '$' ;
    break;
  case  goil_lexique_1_NO_5FDEFAULT:
    s << '$'
      << "NO_DEFAULT"
      << '$' ;
    break;
  case  goil_lexique_1_AUTO:
    s << '$'
      << "AUTO"
      << '$' ;
    break;
  case  goil_lexique_1_TRUE:
    s << '$'
      << "TRUE"
      << '$' ;
    break;
  case  goil_lexique_1_FALSE:
    s << '$'
      << "FALSE"
      << '$' ;
    break;
  case  goil_lexique_1_OS_5FTYPE:
    s << '$'
      << "OS_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_TASK_5FTYPE:
    s << '$'
      << "TASK_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_COUNTER_5FTYPE:
    s << '$'
      << "COUNTER_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_ALARM_5FTYPE:
    s << '$'
      << "ALARM_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_RESOURCE_5FTYPE:
    s << '$'
      << "RESOURCE_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_EVENT_5FTYPE:
    s << '$'
      << "EVENT_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_ISR_5FTYPE:
    s << '$'
      << "ISR_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_MESSAGE_5FTYPE:
    s << '$'
      << "MESSAGE_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_COM_5FTYPE:
    s << '$'
      << "COM_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_NM_5FTYPE:
    s << '$'
      << "NM_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_APPMODE_5FTYPE:
    s << '$'
      << "APPMODE_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_IPDU_5FTYPE:
    s << '$'
      << "IPDU_TYPE"
      << '$' ;
    break;
  case  goil_lexique_1_idf:
    s << '$'
      << "idf"
      << '$' ;
    s << ' ' ;
    s.writeCstringConstant (att_token) ;
    break;
  case  goil_lexique_1__3B:
    s << '$'
      << ";"
      << '$' ;
    break;
  case  goil_lexique_1__3A:
    s << '$'
      << ":"
      << '$' ;
    break;
  case  goil_lexique_1__3D:
    s << '$'
      << "="
      << '$' ;
    break;
  case  goil_lexique_1__7B:
    s << '$'
      << "{"
      << '$' ;
    break;
  case  goil_lexique_1__7D:
    s << '$'
      << "}"
      << '$' ;
    break;
  case  goil_lexique_1__2E_2E:
    s << '$'
      << ".."
      << '$' ;
    break;
  case  goil_lexique_1__5B:
    s << '$'
      << "["
      << '$' ;
    break;
  case  goil_lexique_1__5D:
    s << '$'
      << "]"
      << '$' ;
    break;
  case  goil_lexique_1__2C:
    s << '$'
      << ","
      << '$' ;
    break;
  case  goil_lexique_1__2E:
    s << '$'
      << "."
      << '$' ;
    break;
  case  goil_lexique_1_string:
    s << '$'
      << "string"
      << '$' ;
    s << ' ' ;
    s.writeCstringConstant (a_string) ;
    break;
  case  goil_lexique_1_uint_5Fnumber:
    s << '$'
      << "uint_number"
      << '$' ;
    s << ' ' << integerNumber ;
    break;
  case  goil_lexique_1_float_5Fnumber:
    s << '$'
      << "float_number"
      << '$' ;
    s << ' ' << floatNumber ;
    break;
  default:
    break ;
  }
  return s ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Get next token : method 'parseLexicalToken'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_lexique::
parseLexicalToken (const bool inPropagateLexicalErrorException) {
  bool loop_ = true ;
  mCurrentTokenCode = -1 ;
  a_string.clear () ;
  att_token.clear () ;
  floatNumber = 0.0 ;
  integerNumber = 0 ;
  number.clear () ;
  while (mCurrentTokenCode < 0) {
    mCurrentTokenStartLocation = currentLocation () ;
    try{
      if (testForInputChar ('a', 'z') ||
          testForInputChar ('A', 'Z')) {
        do {
          scanner_action_enterCharacterIntoString (att_token, previousChar ()) ;
          if (testForInputChar ('a', 'z') ||
              testForInputChar ('A', 'Z') ||
              testForInputChar ('_') ||
              testForInputChar ('0', '9')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        mCurrentTokenCode = search_into_oilVersion (att_token) ;
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = search_into_oilDefinitions (att_token) ;
        }
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = search_into_objList (att_token) ;
        }
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = search_into_dataTypes (att_token) ;
        }
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = search_into_miscSpecifiers (att_token) ;
        }
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = search_into_objectRefType (att_token) ;
        }
        if (mCurrentTokenCode == -1) {
          mCurrentTokenCode = goil_lexique_1_idf ;
        }
      }else if (testForInputString ("..", 2)) {
        mCurrentTokenCode = goil_lexique_1__2E_2E ;
      }else if (testForInputString (";", 1)) {
        mCurrentTokenCode = goil_lexique_1__3B ;
      }else if (testForInputString (":", 1)) {
        mCurrentTokenCode = goil_lexique_1__3A ;
      }else if (testForInputString ("=", 1)) {
        mCurrentTokenCode = goil_lexique_1__3D ;
      }else if (testForInputString ("{", 1)) {
        mCurrentTokenCode = goil_lexique_1__7B ;
      }else if (testForInputString ("}", 1)) {
        mCurrentTokenCode = goil_lexique_1__7D ;
      }else if (testForInputString ("[", 1)) {
        mCurrentTokenCode = goil_lexique_1__5B ;
      }else if (testForInputString ("]", 1)) {
        mCurrentTokenCode = goil_lexique_1__5D ;
      }else if (testForInputString (",", 1)) {
        mCurrentTokenCode = goil_lexique_1__2C ;
      }else if (testForInputString (".", 1)) {
        mCurrentTokenCode = goil_lexique_1__2E ;
      }else if (testForInputChar ('\x1', ' ')) {
      }else if (testForInputChar ('\"')) {
        do {
          if (testForInputChar (' ', '!') ||
              testForInputChar ('#', '\xFF')) {
            scanner_action_enterCharacterIntoString (a_string, previousChar ()) ;
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        if (testForInputChar ('\"')) {
          mCurrentTokenCode = goil_lexique_1_string ;
        }else{
          lexicalError (gErrorMessage_2 COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputChar ('0', '9')) {
        do {
          scanner_action_enterCharacterIntoString (number, previousChar ()) ;
          scanner_action_enterDigitIntoUlong (integerNumber, previousChar (), gErrorMessage_1, gErrorMessage_0) ;
          if (testForInputChar ('0', '9')) {
          }else{
            loop_ = false ;
          }
        }while (loop_) ;
        loop_ = true ;
        if (testForInputChar ('.')) {
          do {
            scanner_action_enterCharacterIntoString (number, previousChar ()) ;
            if (testForInputChar ('0', '9')) {
            }else{
              loop_ = false ;
            }
          }while (loop_) ;
          loop_ = true ;
          scanner_action_convertStringToDouble (number, floatNumber, gErrorMessage_3) ;
          mCurrentTokenCode = goil_lexique_1_float_5Fnumber ;
        }else{
          mCurrentTokenCode = goil_lexique_1_uint_5Fnumber ;
        }
      }else if (testForInputChar ('\0')) { // End of source text ? 
        mCurrentTokenCode = goil_lexique_1_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      }
    }catch (const C_lexicalErrorException &) {
      mCurrentTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
      if (inPropagateLexicalErrorException) {
        throw ;
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                            Styles definition                              *
//                                                                           *
//---------------------------------------------------------------------------*

sint32 goil_lexique::getStylesCount (void) {
  return 1 ;
}

//---------------------------------------------------------------------------*

const char * goil_lexique::getStyleName (const sint32 inIndex) {
  const char * kStylesArray [2] = {"Default style", NULL} ;
  return (inIndex < 1) ? kStylesArray [inIndex] : NULL ;
} ;

//---------------------------------------------------------------------------*

uint8 goil_lexique::
terminalStyleIndex (const sint32 inTerminal) {
  static const uint8 kTerminalSymbolStyles [55] = {0,
    0 /* goil_lexique_1_OIL_5FVERSION */,
    0 /* goil_lexique_1_IMPLEMENTATION */,
    0 /* goil_lexique_1_OS */,
    0 /* goil_lexique_1_TASK */,
    0 /* goil_lexique_1_COUNTER */,
    0 /* goil_lexique_1_ALARM */,
    0 /* goil_lexique_1_RESOURCE */,
    0 /* goil_lexique_1_EVENT */,
    0 /* goil_lexique_1_ISR */,
    0 /* goil_lexique_1_MESSAGE */,
    0 /* goil_lexique_1_COM */,
    0 /* goil_lexique_1_NM */,
    0 /* goil_lexique_1_APPMODE */,
    0 /* goil_lexique_1_IPDU */,
    0 /* goil_lexique_1_CPU */,
    0 /* goil_lexique_1_UINT32 */,
    0 /* goil_lexique_1_INT32 */,
    0 /* goil_lexique_1_UINT64 */,
    0 /* goil_lexique_1_INT64 */,
    0 /* goil_lexique_1_FLOAT */,
    0 /* goil_lexique_1_ENUM */,
    0 /* goil_lexique_1_STRING */,
    0 /* goil_lexique_1_BOOLEAN */,
    0 /* goil_lexique_1_WITH_5FAUTO */,
    0 /* goil_lexique_1_NO_5FDEFAULT */,
    0 /* goil_lexique_1_AUTO */,
    0 /* goil_lexique_1_TRUE */,
    0 /* goil_lexique_1_FALSE */,
    0 /* goil_lexique_1_OS_5FTYPE */,
    0 /* goil_lexique_1_TASK_5FTYPE */,
    0 /* goil_lexique_1_COUNTER_5FTYPE */,
    0 /* goil_lexique_1_ALARM_5FTYPE */,
    0 /* goil_lexique_1_RESOURCE_5FTYPE */,
    0 /* goil_lexique_1_EVENT_5FTYPE */,
    0 /* goil_lexique_1_ISR_5FTYPE */,
    0 /* goil_lexique_1_MESSAGE_5FTYPE */,
    0 /* goil_lexique_1_COM_5FTYPE */,
    0 /* goil_lexique_1_NM_5FTYPE */,
    0 /* goil_lexique_1_APPMODE_5FTYPE */,
    0 /* goil_lexique_1_IPDU_5FTYPE */,
    0 /* goil_lexique_1_idf */,
    0 /* goil_lexique_1__3B */,
    0 /* goil_lexique_1__3A */,
    0 /* goil_lexique_1__3D */,
    0 /* goil_lexique_1__7B */,
    0 /* goil_lexique_1__7D */,
    0 /* goil_lexique_1__2E_2E */,
    0 /* goil_lexique_1__5B */,
    0 /* goil_lexique_1__5D */,
    0 /* goil_lexique_1__2C */,
    0 /* goil_lexique_1__2E */,
    0 /* goil_lexique_1_string */,
    0 /* goil_lexique_1_uint_5Fnumber */,
    0 /* goil_lexique_1_float_5Fnumber */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

