//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'api_scanner-cocoa.m'                         *
//                        Generated by version 2.0.1                         *
//                    september 3rd, 2010, at 11h11'23"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


//---------------------------------------------------------------------------*

#import "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 837
  #error "This file has been compiled with a version of GALGAS that uses libpm version 837, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#import "api_scanner-cocoa.h"

//---------------------------------------------------------------------------*

@implementation OC_Lexique_api_scanner

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mLexicalAttribute_att_token = [[NSMutableString alloc] init] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) dealloc {
  [mLexicalAttribute_att_token release] ;
  [super dealloc] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Delimiters                             *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Replacments                            *
//                                                                           *
//---------------------------------------------------------------------------*



//---------------------------------------------------------------------------*
//                                                                           *
//            Terminal Symbols as end of script in template mark             *
//                                                                           *
//---------------------------------------------------------------------------*

static const BOOL kEndOfScriptInTemplateArray_api_5F_scanner [8] = {
  NO /* comment */,
  NO /* idf */,
  NO /* ; */,
  NO /* { */,
  NO /* } */,
  NO /* -> */,
  NO /* ( */,
  NO /* ) */
} ;



//---------------------------------------------------------------------------*
//                                                                           *
//               P A R S E    L E X I C A L    T O K E N                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) parseLexicalTokenForLexicalColoring {
  mLoop = YES ;
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    mTokenFirstLocation = mCurrentLocation ;
    [mLexicalAttribute_att_token setString:@""] ;
    mTokenFirstLocation = mCurrentLocation ;
    if (scanningOk && ([self testForInputString:@"//" advance:YES])) {
      do {
        if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = api_scanner_1_comment ;
    }else if (scanningOk && ([self testForInputString:@"/*" advance:YES])) {
      do {
        if (scanningOk && ([self notTestForInputString:@"*/" error:& scanningOk])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = api_scanner_1_comment ;
    }else if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_att_token, mPreviousChar) ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = api_scanner_1_idf ;
    }else if (scanningOk && [self testForInputString:@"->" advance:YES]) {
      mTokenCode = api_scanner_1__2D__3E_ ;
    }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
      mTokenCode = api_scanner_1__7D_ ;
    }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
      mTokenCode = api_scanner_1__7B_ ;
    }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
      mTokenCode = api_scanner_1__3B_ ;
    }else if (scanningOk && [self testForInputString:@")" advance:YES]) {
      mTokenCode = api_scanner_1__29_ ;
    }else if (scanningOk && [self testForInputString:@"(" advance:YES]) {
      mTokenCode = api_scanner_1__28_ ;
    }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
    }else if ([self testForInputChar:'\0']) { // End of source text ? 
      mTokenCode = api_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      scanningOk = NO ;
    }
  //--- Error ?
    if (! scanningOk) {
      mTokenCode = -1 ;
      [self advance] ;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   T E R M I N A L    C O U N T                            *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) terminalVocabularyCount {
  return 8 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     S T Y L E   C O U N T                                 *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) styleCount {
  return 4 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                I S    T E M P L A T E    L E X I Q U E                    *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) isTemplateLexique {
  return NO ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              S T Y L E   F O R    T E R M I N A L                         *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) styleIndexForTerminal: (SInt32) inTerminal {
  static const UInt32 kTerminalSymbolStyles [9] = {0,
    3 /* api_scanner_1_comment */,
    1 /* api_scanner_1_idf */,
    2 /* api_scanner_1__3B_ */,
    2 /* api_scanner_1__7B_ */,
    2 /* api_scanner_1__7D_ */,
    2 /* api_scanner_1__2D__3E_ */,
    2 /* api_scanner_1__28_ */,
    2 /* api_scanner_1__29_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             S T Y L E   N A M E    F O R    I N D E X                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) styleNameForStyleIndex: (SInt32) inIndex {
  NSString * kStyleArray [4] = {
    @"Default Style",
    @"Identifiers:",
    @"Delimiters:",
    @"Comments:"
  } ;
  return kStyleArray [inIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X             *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) styleIdentifierForStyleIndex: (SInt32) inIndex {
  NSString * kStyleArray [4] = {
    @"api_scanner",
    @"api_scanner-identifierStyle",
    @"api_scanner-delimitersStyle",
    @"api_scanner-commentStyle"
  } ;
  return kStyleArray [inIndex] ;
}

//---------------------------------------------------------------------------*

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



