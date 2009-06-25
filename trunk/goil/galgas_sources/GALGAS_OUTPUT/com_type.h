//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'com_type.h'                              *
//                        Generated by version 1.8.5                         *
//                      june 19th, 2009, at 17h46'22"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef com_type_DEFINED
#define com_type_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/GGS_binaryset.h"
#include "galgas/GGS_filewrapper.h"
#include "galgas/predefined_types.h"
#include "galgas/AC_galgas_class.h"
#include "galgas/AC_galgas_domain.h"
#include "galgas/AC_galgas_mapindex.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_listmap.h"
#include "galgas/AC_galgas_list.h"
#include "galgas/AC_galgas_sortedlist.h"

//---------------------------------------------------------------------------*

#include "galgas/C_Lexique.h"

// Include imported semantics
#include "goil_basic_types.h"
#include "goil_routines.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_com ;
class cPtr_com ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          GALGAS class 'GGS_com'                           *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_com : public GGS_oil_obj {
//--- Default constructor
  public : inline GGS_com (void) :
  GGS_oil_obj () {}

//--- Pointer assignment constructor
  public : GGS_com (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_com (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_com
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_com constructor_new (C_Compiler & inLexique,
                                const GGS_lstring & argument_0,
                                const GGS_bool& argument_1,
                                const GGS_basic_type & argument_2,
                                const GGS_basic_type & argument_3,
                                const GGS_basic_type & argument_4,
                                const GGS_basic_type & argument_5,
                                const GGS_basic_type & argument_6,
                                const GGS_lstringlist & argument_7,
                                const GGS_lstring & argument_8,
                                const GGS_lstringlist & argument_9
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_com * getPtr (void) const {
    return (cPtr_com *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_bool reader_usecom (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_timebase (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_errorhook (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_usegetserviceid (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_useparameteraccess (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_startcomextension (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_lstringlist  reader_appmodes (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_lstring  reader_status (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_lstringlist  reader_uses (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_com * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_com * operator () (LOCATION_ARGS) const {
      return (cPtr_com *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__com ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Function 'void_com_obj'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_com  function_void_com_obj (C_Compiler & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        abstract class 'cPtr_com'                          *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_com : public cPtr_oil_obj {
  private : typedef cPtr_oil_obj inherited ;
//--- Constructor
  public : cPtr_com (const GGS_lstring & ,
                                const GGS_bool& ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_lstringlist & ,
                                const GGS_lstring & ,
                                const GGS_lstringlist & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_com (void) {}
  #endif

//--- Attributes
  public : GGS_bool usecom ;
  public : GGS_basic_type  timebase ;
  public : GGS_basic_type  errorhook ;
  public : GGS_basic_type  usegetserviceid ;
  public : GGS_basic_type  useparameteraccess ;
  public : GGS_basic_type  startcomextension ;
  public : GGS_lstringlist  appmodes ;
  public : GGS_lstring  status ;
  public : GGS_lstringlist  uses ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_string& 
                                COMMA_LOCATION_ARGS) const ;

//--- Class message
  public : virtual const char * _message (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_Compiler & inLexique,
                        C_String & ioString,
                        const sint32 inIndentation
                        COMMA_LOCATION_ARGS) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformation * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*

#endif
