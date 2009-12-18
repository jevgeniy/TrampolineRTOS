//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_appmode.h'                          *
//                        Generated by version 1.9.7                         *
//                     december 17th, 2009, at 9h53'38"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_appmode_DEFINED
#define goil_obj_appmode_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_options.h"
#include "goil_semantics.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                Parser class goil_obj_appmode declaration                  *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_appmode {
  public : virtual ~goil_obj_appmode (void) {}

  protected : virtual void nt_appmode_ (goil_lexique &) = 0 ;

  protected : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_free_field_ (goil_lexique &,
                                GGS_ident_map  &) = 0 ;

  protected : void pr_appmode_goil_obj_appmode_35_14_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_appmode_0 (goil_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
