//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_obj_ipdu.h'                           *
//                        Generated by version 1.9.7                         *
//                     december 17th, 2009, at 9h55'16"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_ipdu_DEFINED
#define goil_obj_ipdu_DEFINED

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
//                  Parser class goil_obj_ipdu declaration                   *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_ipdu {
  public : virtual ~goil_obj_ipdu (void) {}

  protected : virtual void nt_ipdu_ (goil_lexique &) = 0 ;

  protected : virtual void nt_ipduproperty_ (goil_lexique &) = 0 ;

  protected : virtual void nt_transmissionmode_ (goil_lexique &) = 0 ;

  protected : virtual void nt_timeperiod_ (goil_lexique &) = 0 ;

  protected : virtual void nt_timeoffset_ (goil_lexique &) = 0 ;

  protected : virtual void nt_minimumdelaytime_ (goil_lexique &) = 0 ;

  protected : virtual void nt_timeout_ (goil_lexique &) = 0 ;

  protected : virtual void nt_firsttimeout_ (goil_lexique &) = 0 ;

  protected : virtual void nt_ipducallout_ (goil_lexique &) = 0 ;

  protected : virtual void nt_layerused_ (goil_lexique &) = 0 ;

  protected : virtual void nt_sent_attributes_ (goil_lexique &) = 0 ;

  protected : virtual void nt_received_attributes_ (goil_lexique &) = 0 ;

  protected : virtual void nt_direct_attributes_ (goil_lexique &) = 0 ;

  protected : virtual void nt_periodic_attributes_ (goil_lexique &) = 0 ;

  protected : virtual void nt_mixed_attributes_ (goil_lexique &) = 0 ;

  protected : virtual void nt_sizeinbits_ (goil_lexique &,
                                GGS_luint64  &) = 0 ;

  protected : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : void pr_ipdu_goil_obj_ipdu_48_11_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_0 (goil_lexique &) = 0 ;

  protected : void pr_ipduproperty_goil_obj_ipdu_62_19_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_1 (goil_lexique &) = 0 ;

  protected : void pr_ipducallout_goil_obj_ipdu_73_18_ (goil_lexique &) ;

  protected : void pr_layerused_goil_obj_ipdu_80_16_ (goil_lexique &) ;

  protected : void pr_sent_attributes_goil_obj_ipdu_87_22_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_2 (goil_lexique &) = 0 ;

  protected : void pr_received_attributes_goil_obj_ipdu_96_26_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_3 (goil_lexique &) = 0 ;

  protected : void pr_transmissionmode_goil_obj_ipdu_105_23_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_4 (goil_lexique &) = 0 ;

  protected : void pr_timeout_goil_obj_ipdu_118_14_ (goil_lexique &) ;

  protected : void pr_firsttimeout_goil_obj_ipdu_125_19_ (goil_lexique &) ;

  protected : void pr_direct_attributes_goil_obj_ipdu_132_24_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_5 (goil_lexique &) = 0 ;

  protected : void pr_periodic_attributes_goil_obj_ipdu_140_26_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_6 (goil_lexique &) = 0 ;

  protected : void pr_mixed_attributes_goil_obj_ipdu_149_23_ (goil_lexique &) ;

  protected : virtual PMSInt16 select_goil_obj_ipdu_7 (goil_lexique &) = 0 ;

  protected : void pr_minimumdelaytime_goil_obj_ipdu_159_23_ (goil_lexique &) ;

  protected : void pr_timeperiod_goil_obj_ipdu_166_17_ (goil_lexique &) ;

  protected : void pr_timeoffset_goil_obj_ipdu_173_17_ (goil_lexique &) ;

} ;

//---------------------------------------------------------------------------*

#endif
