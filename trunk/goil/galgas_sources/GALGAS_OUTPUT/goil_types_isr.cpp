//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_types_isr.cpp'                          *
//                       Generated by version 1.9.10                         *
//                      april 9th, 2010, at 10h17'48"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 688
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_types_isr.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_types_isr.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                           class 'cPtr_isr_obj'                            *
//                                                                           *
//---------------------------------------------------------------------------*

cPtr_isr_obj::
cPtr_isr_obj (const GGS_lstring & argument_0,
                                const GGS_basic_type & argument_1,
                                const GGS_basic_type & argument_2,
                                const GGS_lstringlist & argument_3,
                                const GGS_lstringlist & argument_4,
                                const GGS_lstringlist & argument_5,
                                const GGS_timing_prot & argument_6,
                                const GGS_ident_map & argument_7
                                COMMA_LOCATION_ARGS)
:cPtr_oil_obj (argument_0 COMMA_THERE),
category (argument_1),
priority (argument_2),
resources (argument_3),
messages (argument_4),
acc_apps (argument_5),
timing_prot (argument_6),
other_fields (argument_7) {
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  cPtr_isr_obj * GGS_isr_obj::
  operator () (LOCATION_ARGS) const {
    macroValidObjectThere (mPointer, cPtr_isr_obj) ;
    return (cPtr_isr_obj *) mPointer ;
  }
#endif

//---------------------------------------------------------------------------*

bool cPtr_isr_obj::
isEqualToObject (const cPtr__AC_galgas_class * inOperand) const {
  bool equal = typeid (this) == typeid (inOperand) ;
  if (equal) {
    const cPtr_isr_obj * ptr = dynamic_cast <const cPtr_isr_obj *> (inOperand) ;
    macroValidPointer (ptr) ;
    equal = desc.operator_isEqual (ptr->desc).boolValue ()
         && category.operator_isEqual (ptr->category).boolValue ()
         && priority.operator_isEqual (ptr->priority).boolValue ()
         && resources.operator_isEqual (ptr->resources).boolValue ()
         && messages.operator_isEqual (ptr->messages).boolValue ()
         && acc_apps.operator_isEqual (ptr->acc_apps).boolValue ()
         && timing_prot.operator_isEqual (ptr->timing_prot).boolValue ()
         && other_fields.operator_isEqual (ptr->other_fields).boolValue () ;
  }
  return equal ;
}

//---------------------------------------------------------------------------*

void cPtr_isr_obj::
appendForDescription (C_String & ioString,
                      const PMSInt32 inIndentation) const {
  ioString << "->@isr_obj:"
           << desc.reader_description (inIndentation + 1)
           << category.reader_description (inIndentation + 1)
           << priority.reader_description (inIndentation + 1)
           << resources.reader_description (inIndentation + 1)
           << messages.reader_description (inIndentation + 1)
           << acc_apps.reader_description (inIndentation + 1)
           << timing_prot.reader_description (inIndentation + 1)
           << other_fields.reader_description (inIndentation + 1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                              Class message                                *
//                                                                           *
//---------------------------------------------------------------------------*

const char * cPtr_isr_obj::
instanceMessage (void) const {
  return "" ;
}

//---------------------------------------------------------------------------*

const char * cPtr_isr_obj::
_static_message (void) {
  return "" ;
}

//---------------------------------------------------------------------------*

C_galgas_class_inspector _gInspectorFor_isr_obj (& typeid (cPtr_isr_obj), & typeid (cPtr_oil_obj), "") ;

//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformationEX * cPtr_isr_obj::galgasRTTI (void) const {
  return & gClassInfoFor__isr_obj ;
}

//---------------------------------------------------------------------------*

cPtr__AC_galgas_class * cPtr_isr_obj::makeClone (void) const {
  cPtr__AC_galgas_class * result = NULL ;
  macroMyNew (result, cPtr_isr_obj (desc, category, priority, resources, messages, acc_apps, timing_prot, other_fields COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        GALGAS class 'GGS_isr_obj'                         *
//                                                                           *
//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX kTypeDescriptor_GGS_isr_obj ("isr_obj", true, & kTypeDescriptor_GGS_oil_obj) ;

//---------------------------------------------------------------------------*

GGS_isr_obj::
GGS_isr_obj (const cPtr__AC_galgas_class * inPointer) {
  macroAssignObject (mPointer, (cPtr__AC_galgas_class *) inPointer) ;
}

//---------------------------------------------------------------------------*

GGS_isr_obj::
GGS_isr_obj (cPtr__AC_galgas_class & inObject) {
  macroAssignObject (mPointer, & inObject) ;
}

//---------------------------------------------------------------------------*

//--- castFrom class method (implements cast expression)
GGS_isr_obj GGS_isr_obj::
castFrom (C_Compiler & inLexique,
           cPtr__AC_galgas_class * inPointer,
           const bool inUseKindOfClass,
           const GGS_location & inErrorLocation
           COMMA_LOCATION_ARGS) {
  GGS_isr_obj result ;
  if (inPointer != NULL) {
    macroValidPointer (inPointer) ;
    const bool ok = inUseKindOfClass
      ? (dynamic_cast <cPtr_isr_obj *> (inPointer) != NULL)
      : (typeid (cPtr_isr_obj) == typeid (*inPointer)) ;
    if (ok) {
      result = GGS_isr_obj (inPointer) ;
    }else{
      inErrorLocation.signalCastError (inLexique,
                                       & typeid (cPtr_isr_obj),
                                       inUseKindOfClass,
                                       inPointer->instanceMessage ()
                                       COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_obj GGS_isr_obj::
constructor_new (C_Compiler & /* inLexique */,
                 const GGS_lstring & argument_0,
                 const GGS_basic_type & argument_1,
                 const GGS_basic_type & argument_2,
                 const GGS_lstringlist & argument_3,
                 const GGS_lstringlist & argument_4,
                 const GGS_lstringlist & argument_5,
                 const GGS_timing_prot & argument_6,
                 const GGS_ident_map & argument_7
                                COMMA_LOCATION_ARGS) {
  GGS_isr_obj result ;
  macroMyNew (result.mPointer, cPtr_isr_obj (argument_0,
                                argument_1,
                                argument_2,
                                argument_3,
                                argument_4,
                                argument_5,
                                argument_6,
                                argument_7 COMMA_THERE)) ;
  macroRetainObject (result.mPointer) ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_basic_type  GGS_isr_obj::
reader_category (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_basic_type   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->category ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_basic_type  GGS_isr_obj::
reader_priority (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_basic_type   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->priority ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_lstringlist  GGS_isr_obj::
reader_resources (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_lstringlist   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->resources ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_lstringlist  GGS_isr_obj::
reader_messages (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_lstringlist   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->messages ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_lstringlist  GGS_isr_obj::
reader_acc_apps (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_lstringlist   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->acc_apps ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_timing_prot  GGS_isr_obj::
reader_timing_prot (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_timing_prot   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->timing_prot ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_ident_map  GGS_isr_obj::
reader_other_fields (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_ident_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_isr_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_isr_obj *) mPointer)->other_fields ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

const char * GGS_isr_obj::actualTypeName (void) const {
  return "isr_obj" ;
}

//---------------------------------------------------------------------------*

C_galgasClassRunTimeInformationEX gClassInfoFor__isr_obj ("isr_obj", gClassInfoFor__oil_obj, & kTypeDescriptor_GGS_isr_obj) ;

//---------------------------------------------------------------------------*

GGS_object GGS_isr_obj::reader_object (void) const {
  GGS_object result ;
  if (isBuilt ()) {
    GGS_isr_obj * p = NULL ;
    macroMyNew (p, GGS_isr_obj (*this)) ;
    result = GGS_object (p) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_obj GGS_isr_obj::castFromObject (C_Compiler & inLexique,
                                   const GGS_object & inObject,
                                   const GGS_location & inErrorLocation
                                   COMMA_LOCATION_ARGS) {
  GGS_isr_obj result ;
  const GGS__root * embeddedObject = inObject.embeddedObject () ;
  if (NULL != embeddedObject) {
    const GGS_isr_obj * p = dynamic_cast <const GGS_isr_obj *> (embeddedObject) ;
    if (NULL != p) {
      result = * p ;
    }else{
      castFromObjectErrorSignaling (inLexique, inErrorLocation, & kTypeDescriptor_GGS_isr_obj, embeddedObject COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX * GGS_isr_obj::typeDescriptor (void) const {
  return & kTypeDescriptor_GGS_isr_obj ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                            class 'e_isr_map'                              *
//                                                                           *
//---------------------------------------------------------------------------*

e_isr_map::e_isr_map (void) :
isr () {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           class map '@isr_map'                            *
//                                                                           *
//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX kTypeDescriptor_GGS_isr_map ("isr_map", false, NULL) ;

//---------------------------------------------------------------------------*

elementOf_GGS_isr_map::
elementOf_GGS_isr_map (const GGS_lstring & inKey,
              const PMSInt32 inIndex,
              const e_isr_map & inInfo) :
AC_galgas_map_element (inKey, inIndex),
mInfo (inInfo) {
}

//---------------------------------------------------------------------------*

void elementOf_GGS_isr_map::
appendForMapDescription (const PMSInt32 inElementIndex,
                         C_String & ioString,
                         const PMSInt32 inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-key " ;
  ioString.appendSigned (inElementIndex) ;
  ioString << ":" << mKey.reader_description (inIndentation + 1) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-value " ;
  ioString.appendSigned (inElementIndex) ;
  ioString << ":" << mInfo.isr.reader_description (inIndentation + 1) ;
}

//---------------------------------------------------------------------------*

bool elementOf_GGS_isr_map::
isEqualToMapElement (const AC_galgas_map_element * inOperand) const {
  const elementOf_GGS_isr_map * ptr = dynamic_cast <const elementOf_GGS_isr_map *> (inOperand) ;
  macroValidPointer (ptr) ;
  return (mInfo.isr.operator_isEqual (ptr->mInfo.isr)).boolValue () ;
}

//---------------------------------------------------------------------------*

AC_galgas_map_element * GGS_isr_map::
new_element (const GGS_lstring & inKey, void * inInfo) {
  MF_Assert (reinterpret_cast <e_isr_map *> (inInfo) != NULL, "Dynamic cast error", 0, 0) ;
  AC_galgas_map_element * p = NULL ;
  e_isr_map * info = (e_isr_map *) inInfo ;
  macroMyNew (p, cElement (inKey, nextIndex (), * info)) ;
  return p ;
}

//---------------------------------------------------------------------------*

void GGS_isr_map::
assignInfo (AC_galgas_map_element * inPtr, void * inInfo) {
  MF_Assert (reinterpret_cast <cElement *> (inPtr) != NULL, "Dynamic cast error", 0, 0) ;
  MF_Assert (reinterpret_cast <e_isr_map *> (inInfo) != NULL, "Dynamic cast error", 0, 0) ;
  cElement * p = (cElement *) inPtr ;
  e_isr_map * info = (e_isr_map *) inInfo ;
  p->mInfo = * info ;
}

//---------------------------------------------------------------------------*

GGS_isr_map GGS_isr_map::
constructor_emptyMap (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) {
  GGS_isr_map result ;
  macroMyNew (result.mSharedMapRoot, cMapRoot) ;
  return result ;
}

//---------------------------------------------------------------------------*

void GGS_isr_map::
enterIndex (const GGS_lstring & inKey,
            AC_galgas_index_core & outIndex) {
  e_isr_map info  ;
  internalEnterIndex (inKey,
                      (void *) & info,
                      outIndex) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_isr_map::
operator_isEqual (const GGS_isr_map & inOperand) const {
  return GGS_bool (isBuilt () && inOperand.isBuilt (), isEqualToMap (inOperand)) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_isr_map::
operator_isNotEqual (const GGS_isr_map & inOperand) const {
  return GGS_bool (isBuilt () && inOperand.isBuilt (), ! isEqualToMap (inOperand)) ;
}

//---------------------------------------------------------------------------*

void GGS_isr_map::
internalInsertForDuplication (AC_galgas_map_element * inPtr) {
  MF_Assert (reinterpret_cast <cElement *> (inPtr) != NULL, "Dynamic cast error", 0, 0) ;
  cElement * p = (cElement *) inPtr ;
  PMSInt32 attributeIndex = -1 ; // Unused here
  GGS_location existingKeyLocation ; // Unused here
  internalInsert (p->mKey, (void *) & p->mInfo, attributeIndex, existingKeyLocation) ;
}

//---------------------------------------------------------------------------*

void GGS_isr_map::
removeElement (C_Compiler & inLexique,
                const utf32 * inErrorMessage,
                const GGS_lstring & inKey,
                GGS_isr_obj & outParameter0,
                GGS_luint * outIndex
                COMMA_LOCATION_ARGS) {
  AC_galgas_map_element * removedElement = NULL ;
  PMSInt32 elementID = - 1 ;
  if (isBuilt () && inKey.isBuilt ()) {
    removedElement = internalRemove (inKey) ;
    if (removedElement == NULL) {
      emitMapSemanticErrorMessage (inLexique, inKey, inErrorMessage COMMA_THERE) ;
      outParameter0.drop () ;
    }else{
      cElement * ptr = (cElement *) removedElement ;
      elementID = ptr->mID ;
      outParameter0 = ptr->mInfo.isr ;
    }
  }
  if (outIndex != NULL) {
    * outIndex = GGS_luint (GGS_uint (elementID >= 0, (PMUInt32) elementID), inKey) ;
  }
  macroMyDelete (removedElement) ;
}

//---------------------------------------------------------------------------*

void GGS_isr_map::
insertElement (C_Compiler & inLexique,
                const utf32 * inErrorMessage,
                const GGS_lstring & inKey,
                const GGS_isr_obj & inParameter0,
                GGS_luint * outIndex
                COMMA_LOCATION_ARGS) {
  PMSInt32 elementID = - 1 ;
  if (isBuilt ()
   && inParameter0.isBuilt ()
   && inKey.isBuilt ()) {
    insulateMap () ;
    e_isr_map info  ;
    info.isr = inParameter0 ;
    GGS_location existingKeyLocation ;
    internalInsert (inKey, (void *) & info, elementID, existingKeyLocation) ;
    if (elementID < 0) {
      emitInsertMapSemanticErrorMessage (inLexique, inKey, inErrorMessage, existingKeyLocation COMMA_THERE) ;
    }
  }
  if (outIndex != NULL) {
    * outIndex = GGS_luint (GGS_uint (elementID >= 0, (PMUInt32) elementID), inKey) ;
  }
}

//---------------------------------------------------------------------------*

void GGS_isr_map::
searchElement (C_Compiler & inLexique,
               const utf32 * inErrorMessage,
               const GGS_lstring & inKey,
               GGS_isr_obj   & outParameter0,
               GGS_luint * outIndex
               COMMA_LOCATION_ARGS) const {
  cElement * node = NULL  ;
  if (isBuilt () && inKey.isBuilt ()) {
    AC_galgas_map_element * p = internal_search (inKey.string ()) ;
    MF_Assert ((p == NULL) || (reinterpret_cast <cElement *> (p) != NULL), "Dynamic cast error", 0, 0) ;
    node = (cElement *) p ;
    if (node == NULL) {
      emitMapSemanticErrorMessage (inLexique, inKey, inErrorMessage COMMA_THERE) ;
    }
  }
  if (node == NULL) {
    outParameter0.drop () ;
    if (outIndex != NULL) {
      outIndex->drop () ;
     }
  }else{
    outParameter0 = node->mInfo.isr ;
    if (outIndex != NULL) {
      * outIndex = GGS_luint (GGS_uint (true, (PMUInt32) node->mID), inKey) ;
    }
  }
}

//---------------------------------------------------------------------------*

const utf32 GGS_isr_map::kSearchMessage_get [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('R'),
  TO_UNICODE ('S'),
  TO_UNICODE (' '),
  TO_UNICODE ('%'),
  TO_UNICODE ('K'),
  TO_UNICODE (' '),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE (' '),
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------*

void GGS_isr_map::
method_get (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                GGS_isr_obj   & outParameter0 COMMA_LOCATION_ARGS) const {
  searchElement (inLexique,
                  kSearchMessage_get,
                  inKey,
                  outParameter0,
                  NULL
                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

const utf32 GGS_isr_map::kRemoveMessage_del [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('S'),
  TO_UNICODE ('R'),
  TO_UNICODE (' '),
  TO_UNICODE ('%'),
  TO_UNICODE ('K'),
  TO_UNICODE (' '),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE (' '),
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------*

void GGS_isr_map::
modifier_del (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                GGS_isr_obj & outParameter0 COMMA_LOCATION_ARGS) {
  removeElement (inLexique,
                  kRemoveMessage_del,
                  inKey,
                  outParameter0,
                  NULL
                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

const utf32 GGS_isr_map::kInsertMessage_put [] = {
  TO_UNICODE ('I'),
  TO_UNICODE ('S'),
  TO_UNICODE ('R'),
  TO_UNICODE (' '),
  TO_UNICODE ('%'),
  TO_UNICODE ('K'),
  TO_UNICODE (' '),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (' '),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE (' '),
  TO_UNICODE ('%'),
  TO_UNICODE ('L'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------*

void GGS_isr_map::
modifier_put (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_isr_obj & inParameter0 COMMA_LOCATION_ARGS) {
  insertElement (inLexique,
                 kInsertMessage_put,
                 inKey,
                 inParameter0,
                 NULL
                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

GGS_isr_map GGS_isr_map::
constructor_mapWithMapToOverride (C_Compiler & /* inLexique */,
                                  const GGS_isr_map & inMapToOverride
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GGS_isr_map result ; // Not Built
  if (inMapToOverride.mSharedMapRoot != NULL) {
    macroValidPointer (inMapToOverride.mSharedMapRoot) ;
    macroMyNew (result.mSharedMapRoot, cMapRoot) ;
    result.mSharedMapRoot->mNextMap = inMapToOverride.mSharedMapRoot ;
    inMapToOverride.mSharedMapRoot->mReferenceCount ++ ;
    result.mSharedMapRoot->mSequenceNumber = inMapToOverride.mSharedMapRoot->mSequenceNumber ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_map GGS_isr_map::
reader_overriddenMap (C_Compiler & /* inLexique */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_isr_map result ; // Not Built
  if (mSharedMapRoot != NULL) {
    macroValidPointer (mSharedMapRoot) ;
    result.mSharedMapRoot = mSharedMapRoot->mNextMap ;
    if (result.mSharedMapRoot != NULL) {
      macroValidPointer (result.mSharedMapRoot) ;
      result.mSharedMapRoot->mReferenceCount ++ ;
    }else{
      macroMyNew (result.mSharedMapRoot, cMapRoot) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_string GGS_isr_map::
reader_description (const PMSInt32 inIndentation) const {
  C_String s ;
  s << "<map @isr_map " ;
  if (isBuilt ()) {
    s.appendSigned (count ()) ;
    s << " object" << ((count () > 1) ? "s " : " ") ;
    cMapRoot * mapRoot = mSharedMapRoot ;
    PMSInt32 level = 0 ;
    while (mapRoot != NULL) {
      if (level > 0) {
        s << "\n" ;
        s.writeStringMultiple ("| ", inIndentation) ;
        s << "------- level " << cStringWithSigned (level) ;
      }
      macroValidPointer (mapRoot) ;
      cElement * p = (cElement *) mapRoot->mFirstItem ;
      PMSInt32 elementID = 0 ;
      while (p != NULL) {
        macroValidPointer (p) ;
        p->appendForMapDescription (elementID, s, inIndentation) ;
        p = p->nextObject () ;
        elementID ++ ;
      }
      mapRoot = mapRoot->mNextMap ;
      level ++ ;
    }
  }else{
    s << "not built" ;
  }
  s << "\n" ;
  s.writeStringMultiple ("| ", inIndentation) ;
  s << ">" ;
  return GGS_string (true, s) ;
}

//---------------------------------------------------------------------------*

/* const */ GGS_isr_obj  & GGS_isr_map::cEnumerator::_isr (LOCATION_ARGS) const {
  return ((cElement *) mObjectArray (mCurrentIndex COMMA_THERE))->mInfo.isr ;
}

//---------------------------------------------------------------------------*

GGS_object GGS_isr_map::reader_object (void) const {
  GGS_object result ;
  if (isBuilt ()) {
    GGS_isr_map * p = NULL ;
    macroMyNew (p, GGS_isr_map (*this)) ;
    result = GGS_object (p) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_map GGS_isr_map::castFromObject (C_Compiler & inLexique,
                                   const GGS_object & inObject,
                                   const GGS_location & inErrorLocation
                                   COMMA_LOCATION_ARGS) {
  GGS_isr_map result ;
  const GGS__root * embeddedObject = inObject.embeddedObject () ;
  if (NULL != embeddedObject) {
    const GGS_isr_map * p = dynamic_cast <const GGS_isr_map *> (embeddedObject) ;
    if (NULL != p) {
      result = * p ;
    }else{
      castFromObjectErrorSignaling (inLexique, inErrorLocation, & kTypeDescriptor_GGS_isr_map, embeddedObject COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX * GGS_isr_map::typeDescriptor (void) const {
  return & kTypeDescriptor_GGS_isr_map ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       Element of list '@isr_list'                         *
//                                                                           *
//---------------------------------------------------------------------------*

elementOf_GGS_isr_list::
elementOf_GGS_isr_list (const GGS_lstring & argument_0,
                                const GGS_string& argument_1):
key (argument_0),
sort (argument_1) {
}

//---------------------------------------------------------------------------*

bool elementOf_GGS_isr_list::
isEqualToObject (const cSortedListElement * inOperand) const {
  bool equal = inOperand == this ;
  if (! equal) {
    const elementOf_GGS_isr_list * ptr = dynamic_cast <const elementOf_GGS_isr_list *> (inOperand) ;
    macroValidPointer (ptr) ;
    equal = key.operator_isEqual (ptr->key).boolValue ()
         && sort.operator_isEqual (ptr->sort).boolValue () ;
  }
  return equal ;
}

//---------------------------------------------------------------------------*

PMSInt32 elementOf_GGS_isr_list::
compareForSorting (const cSortedListElement * inOperand) const {
  const elementOf_GGS_isr_list * operand = (const elementOf_GGS_isr_list *) inOperand ;
  PMSInt32 result = sort.compareForSortedList (operand->sort) ;
  return result ;
}

//---------------------------------------------------------------------------*

void elementOf_GGS_isr_list::
appendForDescription (C_String & ioString,
                      const PMSInt32 inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-" ;
  ioString << key.reader_description (inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-" ;
  ioString << sort.reader_description (inIndentation) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                         Sorted list '@isr_list'                           *
//                                                                           *
//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX kTypeDescriptor_GGS_isr_list ("isr_list", false, NULL) ;

//---------------------------------------------------------------------------*

GGS_isr_list::GGS_isr_list (void): AC_galgas_sortedlist () { // Default Constructor
}

//---------------------------------------------------------------------------*

GGS_isr_list::
GGS_isr_list (const GGS_isr_list & inSource): AC_galgas_sortedlist (inSource) {
}

//---------------------------------------------------------------------------*

GGS_bool GGS_isr_list::
operator_isEqual (const GGS_isr_list & inOperand) const {
  return GGS_bool (isBuilt () && inOperand.isBuilt (), isEqualToList (inOperand)) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_isr_list::
operator_isNotEqual (const GGS_isr_list & inOperand) const {
  return GGS_bool (isBuilt () && inOperand.isBuilt (), ! isEqualToList (inOperand)) ;
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
internalAppendValues (const GGS_lstring & argument_0,
                    const GGS_string& argument_1) {
  cElement * newElement = (cElement *) NULL ;
  macroMyNew (newElement, cElement (argument_0,
                                argument_1)) ;
  internalAppendItem (newElement) ;
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
addAssign_operation (const GGS_lstring & argument_0,
                                const GGS_string& argument_1) {
  if (isBuilt ()) {
    insulateList () ;
    internalAppendValues (argument_0,
                                argument_1) ;
  }
}

//---------------------------------------------------------------------------*

GGS_isr_list GGS_isr_list::
operator_concat (const GGS_isr_list & inOperand) const {
  GGS_isr_list result = * this ;
  result.dotAssign_operation (inOperand) ;
  return result ;
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
dotAssign_operation (const GGS_isr_list inOperand) {
  if (isBuilt () && inOperand.isBuilt ()) {
    if (count () == 0) {
      *this = inOperand ;
    }else{
      if (inOperand.count () > 0) {
        insulateList () ;
        elementOf_GGS_isr_list * p = inOperand.firstObject () ;
        while (p != NULL) {
          macroValidPointer (p) ;
          GGS_lstring  p_0 = p->key ;
          GGS_string p_1 = p->sort ;
          internalAppendValues (p_0, p_1) ;
          p = p->nextObject () ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
insulateList (void) {
  if (isShared ()) {
    cElement * ptr = firstObject () ;
    alloc () ;
    while (ptr != NULL) {
      macroValidPointer (ptr) ;
      internalAppendValues (ptr->key,
                                ptr->sort) ;
      ptr = ptr->nextObject () ;
    }
  }
}

//---------------------------------------------------------------------------*

GGS_isr_list  GGS_isr_list::
constructor_emptySortedList (void) {
  GGS_isr_list result ;
  result.alloc () ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_list  GGS_isr_list::
constructor_sortedListWithValue (const GGS_lstring & argument_0,
                           const GGS_string& argument_1) {
  GGS_isr_list result ;
  result.alloc () ;
  result.addAssign_operation (argument_0, argument_1) ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_string GGS_isr_list::
reader_description (const PMSInt32 inIndentation) const {
  return performDescription ("@isr_list", inIndentation) ;
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
method_smallest (C_Compiler & inLexique,
                 GGS_lstring & _out_0,
                 GGS_string& _out_1
                 COMMA_LOCATION_ARGS) const {
  cElement * ptr = NULL ;
  if (isBuilt ()) {
    ptr = firstObject () ;
    if (ptr == NULL) {
      inLexique.onTheFlyRunTimeError ("'first' method invoked on an empty list" COMMA_THERE) ;
    }
  }
  if (ptr != NULL) {
    _out_0 = ptr->key ;
    _out_1 = ptr->sort ;
  }else{
    _out_0.drop () ;
    _out_1.drop () ;
  }
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
method_greatest (C_Compiler & inLexique,
             GGS_lstring & _out_0,
             GGS_string& _out_1
             COMMA_LOCATION_ARGS) const {
  cElement * ptr = NULL ;
  if (isBuilt ()) {
    ptr = lastObject () ;
    if (ptr == NULL) {
      inLexique.onTheFlyRunTimeError ("'greatest' method invoked on an empty list" COMMA_THERE) ;
    }
  }
  if (ptr != NULL) {
    _out_0 = ptr->key ;
    _out_1 = ptr->sort ;
  }else{
    _out_0.drop () ;
    _out_1.drop () ;
  }
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
modifier_popSmallest (C_Compiler & inLexique,
                 GGS_lstring & _out_0,
                 GGS_string& _out_1
                 COMMA_LOCATION_ARGS) {
  cElement * ptr = NULL ;
  if (isBuilt ()) {
    ptr = firstObject () ;
    if (ptr == NULL) {
      inLexique.onTheFlyRunTimeError ("'popSmallest' modifier invoked on an empty list" COMMA_THERE) ;
    }
  }
  if (ptr != NULL) {
    _out_0 = ptr->key ;
    _out_1 = ptr->sort ;
    insulateList () ;
    _internalRemoveSmallest () ;
  }else{
    _out_0.drop () ;
    _out_1.drop () ;
  }
}

//---------------------------------------------------------------------------*

void GGS_isr_list::
modifier_popGreatest (C_Compiler & inLexique,
                GGS_lstring & _out_0,
                GGS_string& _out_1
                COMMA_LOCATION_ARGS) {
  cElement * ptr = NULL ;
  if (isBuilt ()) {
    ptr = lastObject () ;
    if (ptr == NULL) {
      inLexique.onTheFlyRunTimeError ("'popGreatest' modifier invoked on an empty list" COMMA_THERE) ;
    }
  }
  if (ptr != NULL) {
    _out_0 = ptr->key ;
    _out_1 = ptr->sort ;
    insulateList () ;
    _internalRemoveGreatest () ;
  }else{
    _out_0.drop () ;
    _out_1.drop () ;
  }
}

//---------------------------------------------------------------------------*

/* const */ GGS_lstring  & GGS_isr_list::cEnumerator::_key (LOCATION_ARGS) const {
  macroValidPointerThere (mCurrentEnumeratedObject) ;
  return ((/* const */ cElement *) mCurrentEnumeratedObject)->key ;
}

//---------------------------------------------------------------------------*

/* const */ GGS_string & GGS_isr_list::cEnumerator::_sort (LOCATION_ARGS) const {
  macroValidPointerThere (mCurrentEnumeratedObject) ;
  return ((/* const */ cElement *) mCurrentEnumeratedObject)->sort ;
}

//---------------------------------------------------------------------------*

GGS_object GGS_isr_list::reader_object (void) const {
  GGS_object result ;
  if (isBuilt ()) {
    GGS_isr_list * p = NULL ;
    macroMyNew (p, GGS_isr_list (*this)) ;
    result = GGS_object (p) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_list GGS_isr_list::castFromObject (C_Compiler & inLexique,
                                   const GGS_object & inObject,
                                   const GGS_location & inErrorLocation
                                   COMMA_LOCATION_ARGS) {
  GGS_isr_list result ;
  const GGS__root * embeddedObject = inObject.embeddedObject () ;
  if (NULL != embeddedObject) {
    const GGS_isr_list * p = dynamic_cast <const GGS_isr_list *> (embeddedObject) ;
    if (NULL != p) {
      result = * p ;
    }else{
      castFromObjectErrorSignaling (inLexique, inErrorLocation, & kTypeDescriptor_GGS_isr_list, embeddedObject COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX * GGS_isr_list::typeDescriptor (void) const {
  return & kTypeDescriptor_GGS_isr_list ;
}

//---------------------------------------------------------------------------*

