//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_types_action.h'                         *
//                        Generated by version 1.8.5                         *
//                      june 19th, 2009, at 17h46'21"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_types_action_DEFINED
#define goil_types_action_DEFINED

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

class GGS_action_obj ;
class cPtr_action_obj ;
class GGS_void_action ;
class cPtr_void_action ;
class GGS_setevent_action ;
class cPtr_setevent_action ;
class GGS_activatetask_action ;
class cPtr_activatetask_action ;
class GGS_callback_action ;
class cPtr_callback_action ;
class GGS_flag_action ;
class cPtr_flag_action ;
class GGS_incrementcounter_action ;
class cPtr_incrementcounter_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      GALGAS class 'GGS_action_obj'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_action_obj : public AC_galgas_class {
//--- Default constructor
  public : inline GGS_action_obj (void) :
  AC_galgas_class () {}

//--- Pointer assignment constructor
  public : GGS_action_obj (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_action_obj (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_action_obj
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_action_obj * getPtr (void) const {
    return (cPtr_action_obj *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_location  reader_location (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_action_obj * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_action_obj * operator () (LOCATION_ARGS) const {
      return (cPtr_action_obj *) mPointer ;
    }
  #endif

//--- Galgas RTTI
AC_galgasClassRunTimeInformation * galgasObjectRunTimeInfo (void) const ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasRootClassRunTimeInformation gClassInfoFor__action_obj ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      GALGAS class 'GGS_void_action'                       *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_void_action : public GGS_action_obj {
//--- Default constructor
  public : inline GGS_void_action (void) :
  GGS_action_obj () {}

//--- Pointer assignment constructor
  public : GGS_void_action (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_void_action (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_void_action
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_void_action constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_void_action * getPtr (void) const {
    return (cPtr_void_action *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_void_action * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_void_action * operator () (LOCATION_ARGS) const {
      return (cPtr_void_action *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__void_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    GALGAS class 'GGS_setevent_action'                     *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_setevent_action : public GGS_action_obj {
//--- Default constructor
  public : inline GGS_setevent_action (void) :
  GGS_action_obj () {}

//--- Pointer assignment constructor
  public : GGS_setevent_action (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_setevent_action (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_setevent_action
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_setevent_action constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0,
                                const GGS_lstring & argument_1,
                                const GGS_lstring & argument_2
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_setevent_action * getPtr (void) const {
    return (cPtr_setevent_action *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_lstring  reader_task_name (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_lstring  reader_event_name (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_setevent_action * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_setevent_action * operator () (LOCATION_ARGS) const {
      return (cPtr_setevent_action *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__setevent_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  GALGAS class 'GGS_activatetask_action'                   *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_activatetask_action : public GGS_action_obj {
//--- Default constructor
  public : inline GGS_activatetask_action (void) :
  GGS_action_obj () {}

//--- Pointer assignment constructor
  public : GGS_activatetask_action (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_activatetask_action (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_activatetask_action
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_activatetask_action constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0,
                                const GGS_lstring & argument_1
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_activatetask_action * getPtr (void) const {
    return (cPtr_activatetask_action *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_lstring  reader_task_name (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_activatetask_action * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_activatetask_action * operator () (LOCATION_ARGS) const {
      return (cPtr_activatetask_action *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__activatetask_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    GALGAS class 'GGS_callback_action'                     *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_callback_action : public GGS_action_obj {
//--- Default constructor
  public : inline GGS_callback_action (void) :
  GGS_action_obj () {}

//--- Pointer assignment constructor
  public : GGS_callback_action (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_callback_action (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_callback_action
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_callback_action constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0,
                                const GGS_lstring & argument_1
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_callback_action * getPtr (void) const {
    return (cPtr_callback_action *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_lstring  reader_function_name (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_callback_action * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_callback_action * operator () (LOCATION_ARGS) const {
      return (cPtr_callback_action *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__callback_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      GALGAS class 'GGS_flag_action'                       *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_flag_action : public GGS_action_obj {
//--- Default constructor
  public : inline GGS_flag_action (void) :
  GGS_action_obj () {}

//--- Pointer assignment constructor
  public : GGS_flag_action (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_flag_action (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_flag_action
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_flag_action constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0,
                                const GGS_lstring & argument_1
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_flag_action * getPtr (void) const {
    return (cPtr_flag_action *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_lstring  reader_flag_name (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_flag_action * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_flag_action * operator () (LOCATION_ARGS) const {
      return (cPtr_flag_action *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__flag_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                GALGAS class 'GGS_incrementcounter_action'                 *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_incrementcounter_action : public GGS_action_obj {
//--- Default constructor
  public : inline GGS_incrementcounter_action (void) :
  GGS_action_obj () {}

//--- Pointer assignment constructor
  public : GGS_incrementcounter_action (cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_incrementcounter_action (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_incrementcounter_action
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_incrementcounter_action constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0,
                                const GGS_lstring & argument_1
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_incrementcounter_action * getPtr (void) const {
    return (cPtr_incrementcounter_action *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_lstring  reader_counter_name (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_incrementcounter_action * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_incrementcounter_action * operator () (LOCATION_ARGS) const {
      return (cPtr_incrementcounter_action *) mPointer ;
    }
  #endif

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformation gClassInfoFor__incrementcounter_action ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     abstract class 'cPtr_action_obj'                      *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_action_obj : public cPtr__AC_galgas_class {
//--- Constructor
  public : cPtr_action_obj (const GGS_location & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_action_obj (void) {}
  #endif

//--- Attributes
  public : GGS_location  location ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
                                GGS_string& 
                                COMMA_LOCATION_ARGS) const = 0 ;

//--- Method 'flag'
  public : virtual void method_flag (C_Compiler &,
                                GGS_stringset & 
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

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformation * galgasRTTI (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    abstract class 'cPtr_void_action'                      *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_void_action : public cPtr_action_obj {
  private : typedef cPtr_action_obj inherited ;
//--- Constructor
  public : cPtr_void_action (const GGS_location & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_void_action (void) {}
  #endif

//--- Attributes
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
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
//                                                                           *
//                  abstract class 'cPtr_setevent_action'                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_setevent_action : public cPtr_action_obj {
  private : typedef cPtr_action_obj inherited ;
//--- Constructor
  public : cPtr_setevent_action (const GGS_location & ,
                                const GGS_lstring & ,
                                const GGS_lstring & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_setevent_action (void) {}
  #endif

//--- Attributes
  public : GGS_lstring  task_name ;
  public : GGS_lstring  event_name ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
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
//                                                                           *
//                abstract class 'cPtr_activatetask_action'                  *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_activatetask_action : public cPtr_action_obj {
  private : typedef cPtr_action_obj inherited ;
//--- Constructor
  public : cPtr_activatetask_action (const GGS_location & ,
                                const GGS_lstring & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_activatetask_action (void) {}
  #endif

//--- Attributes
  public : GGS_lstring  task_name ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
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
//                                                                           *
//                  abstract class 'cPtr_callback_action'                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_callback_action : public cPtr_action_obj {
  private : typedef cPtr_action_obj inherited ;
//--- Constructor
  public : cPtr_callback_action (const GGS_location & ,
                                const GGS_lstring & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_callback_action (void) {}
  #endif

//--- Attributes
  public : GGS_lstring  function_name ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
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
//                                                                           *
//                    abstract class 'cPtr_flag_action'                      *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_flag_action : public cPtr_action_obj {
  private : typedef cPtr_action_obj inherited ;
//--- Constructor
  public : cPtr_flag_action (const GGS_location & ,
                                const GGS_lstring & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_flag_action (void) {}
  #endif

//--- Attributes
  public : GGS_lstring  flag_name ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
                                GGS_string& 
                                COMMA_LOCATION_ARGS) const ;

//--- Method 'flag'
  public : virtual void method_flag (C_Compiler &,
                                GGS_stringset & 
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
//                                                                           *
//              abstract class 'cPtr_incrementcounter_action'                *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_incrementcounter_action : public cPtr_action_obj {
  private : typedef cPtr_action_obj inherited ;
//--- Constructor
  public : cPtr_incrementcounter_action (const GGS_location & ,
                                const GGS_lstring & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_incrementcounter_action (void) {}
  #endif

//--- Attributes
  public : GGS_lstring  counter_name ;
//--- Method 'generate'
  public : virtual void method_generate (C_Compiler &,
                                GGS_lstring  ,
                                GGS_string ,
                                GGS_string ,
                                GGS_string& ,
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
