//
//  OC_GGS_TextSyntaxColoring.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 24/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OC_GGS_TextDisplayDescriptor ;
@class OC_Lexique ;

@interface OC_GGS_TextSyntaxColoring : NSObject {
  @private NSURL * mSourceURL ;
  @private NSTextStorage * mSourceTextStorage ;
  @private NSMutableSet * mTextDisplayDescriptorSet ; // Set of OC_GGS_TextDisplayDescriptor
  @private OC_Lexique * mTokenizer ;
  @private BOOL mIsDirty ;
  @private NSArray * mIssueArray ;

  @private double mMaxAscender ; // Only mMaxAscender is observable
  @private double mMaxLeadingMinusDescender ; // leading - descender (because descender is < 0)

//--- Undo manager
  @private NSUndoManager * mUndoManager ;
  
//--- Attributes for syntax coloring
  @private NSMutableArray * mTokenArray ;
  @private NSMutableArray * mFontAttributesDictionaryArray ; // Array of OC_Token
  @private NSMutableDictionary * mTemplateTextAttributeDictionary ;
}

- (OC_GGS_TextSyntaxColoring *) initWithSourceString: (NSString *) inSource
                                tokenizer: (OC_Lexique *) inTokenizer
                                sourceURL: (NSURL *) inSourceURL
                                issueArray: (NSArray *) inIssueArray ;

- (NSTextStorage *) textStorage ;
- (NSUndoManager *) undoManager ;
- (OC_Lexique *) tokenizer ;
- (NSURL *) sourceURL ;
- (NSArray *) issueArray ;

- (NSArray *) tokenArray ;
- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex ;

- (BOOL) isDirty ;

- (NSString *) sourceString ;
- (void) replaceSourceStringWithString: (NSString *) inString ;

- (void) updateSyntaxColoringForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (NSMenu *) menuForEntryPopUpButton ;

- (void) breakUndoCoalescing ;

- (NSRange) uncommentRange: (NSRange) initialSelectedRange ;
- (NSRange) commentRange: (NSRange) initialSelectedRange ;

- (NSMenu *) indexMenuForRange: (NSRange) inRange ;

- (void) documentHasBeenSaved ;

- (void) setIssueArray: (NSArray *) inIssueArray ;
@end
