//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_grammar.h'                            *
//                Generated by version 1.3.1 (LL(1) grammar)                 *
//                       june 7th, 2006, at 20h13'23"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_goil_grammar_DEFINED
#define GRAMMAR_goil_grammar_DEFINED

//---------------------------------------------------------------------------*

#include "goil_syntax.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

class goil_grammar : public goil_syntax {
  public : virtual void nt_file_ (goil_lexique &) ;
  public : void startParsing_ (goil_lexique &) ;
  public : virtual void nt_OIL_version_ (goil_lexique &,
                                GGS_lstring &,
                                GGS_lstring &) ;
  public : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring &) ;
  public : virtual void nt_implementation_definition_ (goil_lexique &,
                                GGS_implementation &) ;
  public : virtual void nt_implementation_spec_list_ (goil_lexique &,
                                GGS_implementation &) ;
  public : virtual void nt_implementation_spec_ (goil_lexique &,
                                GGS_implementation &) ;
  public : virtual void nt_implementation_list_ (goil_lexique &,
                                GGS_implementationSpec &) ;
  public : virtual void nt_impl_attr_def_ (goil_lexique &,
                                GGS_implementationSpec &) ;
  public : virtual void nt_auto_specifier_ (goil_lexique &,
                                GGS_bool &) ;
  public : virtual void nt_number_range_ (goil_lexique &,
                                GGS_number_set &) ;
  public : virtual sint16 select_goil_syntax_0 (goil_lexique &) ;
  public : virtual sint16 select_repeat_goil_syntax_1 (goil_lexique &) ;
  public : virtual sint16 select_goil_syntax_2 (goil_lexique &) ;
  public : virtual sint16 select_repeat_goil_syntax_3 (goil_lexique &) ;
  public : virtual sint16 select_goil_syntax_4 (goil_lexique &) ;
  public : virtual sint16 select_goil_syntax_5 (goil_lexique &) ;
  public : virtual sint16 select_goil_syntax_6 (goil_lexique &) ;
  public : virtual sint16 select_repeat_goil_syntax_7 (goil_lexique &) ;
} ;

//---------------------------------------------------------------------------*

#endif
