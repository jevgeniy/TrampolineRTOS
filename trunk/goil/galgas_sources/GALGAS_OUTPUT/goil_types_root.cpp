//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_types_root.cpp'                         *
//                       Generated by version 1.9.10                         *
//                      april 9th, 2010, at 10h17'47"                        *
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
#include "goil_types_root.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_types_root.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          class 'cPtr_root_obj'                            *
//                                                                           *
//---------------------------------------------------------------------------*

cPtr_root_obj::
cPtr_root_obj (const GGS_lstring & argument_0,
                                const GGS_os_obj & argument_1,
                                const GGS_com & argument_2,
                                const GGS_task_map & argument_3,
                                const GGS_counter_map & argument_4,
                                const GGS_alarm_map & argument_5,
                                const GGS_resource_map & argument_6,
                                const GGS_event_map & argument_7,
                                const GGS_isr_map & argument_8,
                                const GGS_message_map & argument_9,
                                const GGS_netmess_map & argument_10,
                                const GGS_scheduletable_map & argument_11,
                                const GGS_app_map & argument_12
                                COMMA_LOCATION_ARGS)
:cPtr__AC_galgas_class (THERE),
name (argument_0),
os (argument_1),
com (argument_2),
tasks (argument_3),
counters (argument_4),
alarms (argument_5),
resources (argument_6),
events (argument_7),
isrs (argument_8),
messages (argument_9),
net_messages (argument_10),
scheduletables (argument_11),
applis (argument_12) {
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  cPtr_root_obj * GGS_root_obj::
  operator () (LOCATION_ARGS) const {
    macroValidObjectThere (mPointer, cPtr_root_obj) ;
    return (cPtr_root_obj *) mPointer ;
  }
#endif

//---------------------------------------------------------------------------*

bool cPtr_root_obj::
isEqualToObject (const cPtr__AC_galgas_class * inOperand) const {
  bool equal = typeid (this) == typeid (inOperand) ;
  if (equal) {
    const cPtr_root_obj * ptr = dynamic_cast <const cPtr_root_obj *> (inOperand) ;
    macroValidPointer (ptr) ;
    equal = name.operator_isEqual (ptr->name).boolValue ()
         && os.operator_isEqual (ptr->os).boolValue ()
         && com.operator_isEqual (ptr->com).boolValue ()
         && tasks.operator_isEqual (ptr->tasks).boolValue ()
         && counters.operator_isEqual (ptr->counters).boolValue ()
         && alarms.operator_isEqual (ptr->alarms).boolValue ()
         && resources.operator_isEqual (ptr->resources).boolValue ()
         && events.operator_isEqual (ptr->events).boolValue ()
         && isrs.operator_isEqual (ptr->isrs).boolValue ()
         && messages.operator_isEqual (ptr->messages).boolValue ()
         && net_messages.operator_isEqual (ptr->net_messages).boolValue ()
         && scheduletables.operator_isEqual (ptr->scheduletables).boolValue ()
         && applis.operator_isEqual (ptr->applis).boolValue () ;
  }
  return equal ;
}

//---------------------------------------------------------------------------*

void cPtr_root_obj::
appendForDescription (C_String & ioString,
                      const PMSInt32 inIndentation) const {
  ioString << "->@root_obj:"
           << name.reader_description (inIndentation + 1)
           << os.reader_description (inIndentation + 1)
           << com.reader_description (inIndentation + 1)
           << tasks.reader_description (inIndentation + 1)
           << counters.reader_description (inIndentation + 1)
           << alarms.reader_description (inIndentation + 1)
           << resources.reader_description (inIndentation + 1)
           << events.reader_description (inIndentation + 1)
           << isrs.reader_description (inIndentation + 1)
           << messages.reader_description (inIndentation + 1)
           << net_messages.reader_description (inIndentation + 1)
           << scheduletables.reader_description (inIndentation + 1)
           << applis.reader_description (inIndentation + 1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                              Class message                                *
//                                                                           *
//---------------------------------------------------------------------------*

const char * cPtr_root_obj::
instanceMessage (void) const {
  return "" ;
}

//---------------------------------------------------------------------------*

const char * cPtr_root_obj::
_static_message (void) {
  return "" ;
}

//---------------------------------------------------------------------------*

C_galgas_class_inspector _gInspectorFor_root_obj (& typeid (cPtr_root_obj), NULL, "") ;

//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformationEX * cPtr_root_obj::galgasRTTI (void) const {
  return & gClassInfoFor__root_obj ;
}

//---------------------------------------------------------------------------*

cPtr__AC_galgas_class * cPtr_root_obj::makeClone (void) const {
  cPtr__AC_galgas_class * result = NULL ;
  macroMyNew (result, cPtr_root_obj (name, os, com, tasks, counters, alarms, resources, events, isrs, messages, net_messages, scheduletables, applis COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       GALGAS class 'GGS_root_obj'                         *
//                                                                           *
//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX kTypeDescriptor_GGS_root_obj ("root_obj", true, NULL) ;

//---------------------------------------------------------------------------*

GGS_root_obj::
GGS_root_obj (const cPtr__AC_galgas_class * inPointer) {
  macroAssignObject (mPointer, (cPtr__AC_galgas_class *) inPointer) ;
}

//---------------------------------------------------------------------------*

GGS_root_obj::
GGS_root_obj (cPtr__AC_galgas_class & inObject) {
  macroAssignObject (mPointer, & inObject) ;
}

//---------------------------------------------------------------------------*

//--- castFrom class method (implements cast expression)
GGS_root_obj GGS_root_obj::
castFrom (C_Compiler & inLexique,
           cPtr__AC_galgas_class * inPointer,
           const bool inUseKindOfClass,
           const GGS_location & inErrorLocation
           COMMA_LOCATION_ARGS) {
  GGS_root_obj result ;
  if (inPointer != NULL) {
    macroValidPointer (inPointer) ;
    const bool ok = inUseKindOfClass
      ? (dynamic_cast <cPtr_root_obj *> (inPointer) != NULL)
      : (typeid (cPtr_root_obj) == typeid (*inPointer)) ;
    if (ok) {
      result = GGS_root_obj (inPointer) ;
    }else{
      inErrorLocation.signalCastError (inLexique,
                                       & typeid (cPtr_root_obj),
                                       inUseKindOfClass,
                                       inPointer->instanceMessage ()
                                       COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_root_obj GGS_root_obj::
constructor_new (C_Compiler & /* inLexique */,
                 const GGS_lstring & argument_0,
                 const GGS_os_obj & argument_1,
                 const GGS_com & argument_2,
                 const GGS_task_map & argument_3,
                 const GGS_counter_map & argument_4,
                 const GGS_alarm_map & argument_5,
                 const GGS_resource_map & argument_6,
                 const GGS_event_map & argument_7,
                 const GGS_isr_map & argument_8,
                 const GGS_message_map & argument_9,
                 const GGS_netmess_map & argument_10,
                 const GGS_scheduletable_map & argument_11,
                 const GGS_app_map & argument_12
                                COMMA_LOCATION_ARGS) {
  GGS_root_obj result ;
  macroMyNew (result.mPointer, cPtr_root_obj (argument_0,
                                argument_1,
                                argument_2,
                                argument_3,
                                argument_4,
                                argument_5,
                                argument_6,
                                argument_7,
                                argument_8,
                                argument_9,
                                argument_10,
                                argument_11,
                                argument_12 COMMA_THERE)) ;
  macroRetainObject (result.mPointer) ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_lstring  GGS_root_obj::
reader_name (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_lstring   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->name ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_os_obj  GGS_root_obj::
reader_os (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_os_obj   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->os ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_com  GGS_root_obj::
reader_com (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_com   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->com ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_task_map  GGS_root_obj::
reader_tasks (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_task_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->tasks ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_counter_map  GGS_root_obj::
reader_counters (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_counter_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->counters ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_alarm_map  GGS_root_obj::
reader_alarms (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_alarm_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->alarms ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_resource_map  GGS_root_obj::
reader_resources (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_resource_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->resources ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_event_map  GGS_root_obj::
reader_events (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_event_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->events ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_isr_map  GGS_root_obj::
reader_isrs (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_isr_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->isrs ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_message_map  GGS_root_obj::
reader_messages (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_message_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->messages ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_netmess_map  GGS_root_obj::
reader_net_messages (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_netmess_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->net_messages ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_scheduletable_map  GGS_root_obj::
reader_scheduletables (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_scheduletable_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->scheduletables ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_app_map  GGS_root_obj::
reader_applis (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_app_map   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_root_obj *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_root_obj *) mPointer)->applis ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GGS_root_obj::
modifier_setOs (C_Compiler & /* inLexique */, const GGS_os_obj & inValue COMMA_UNUSED_LOCATION_ARGS) {
  if ((mPointer != NULL) && inValue.isBuilt ()) {
    macroValidPointer (mPointer) ;
    if (mPointer->retainCount () > 1) {
      cPtr_root_obj * clone = dynamic_cast <cPtr_root_obj *> (mPointer->makeClone ()) ;
      macroValidPointer (clone) ;
      macroAssignObject (mPointer, clone) ;
    }
    ((cPtr_root_obj *) mPointer)->os = inValue ;
  }
}

//---------------------------------------------------------------------------*

void GGS_root_obj::
modifier_setTasks (C_Compiler & /* inLexique */, const GGS_task_map & inValue COMMA_UNUSED_LOCATION_ARGS) {
  if ((mPointer != NULL) && inValue.isBuilt ()) {
    macroValidPointer (mPointer) ;
    if (mPointer->retainCount () > 1) {
      cPtr_root_obj * clone = dynamic_cast <cPtr_root_obj *> (mPointer->makeClone ()) ;
      macroValidPointer (clone) ;
      macroAssignObject (mPointer, clone) ;
    }
    ((cPtr_root_obj *) mPointer)->tasks = inValue ;
  }
}

//---------------------------------------------------------------------------*

void GGS_root_obj::
modifier_setCounters (C_Compiler & /* inLexique */, const GGS_counter_map & inValue COMMA_UNUSED_LOCATION_ARGS) {
  if ((mPointer != NULL) && inValue.isBuilt ()) {
    macroValidPointer (mPointer) ;
    if (mPointer->retainCount () > 1) {
      cPtr_root_obj * clone = dynamic_cast <cPtr_root_obj *> (mPointer->makeClone ()) ;
      macroValidPointer (clone) ;
      macroAssignObject (mPointer, clone) ;
    }
    ((cPtr_root_obj *) mPointer)->counters = inValue ;
  }
}

//---------------------------------------------------------------------------*

void GGS_root_obj::
modifier_setResources (C_Compiler & /* inLexique */, const GGS_resource_map & inValue COMMA_UNUSED_LOCATION_ARGS) {
  if ((mPointer != NULL) && inValue.isBuilt ()) {
    macroValidPointer (mPointer) ;
    if (mPointer->retainCount () > 1) {
      cPtr_root_obj * clone = dynamic_cast <cPtr_root_obj *> (mPointer->makeClone ()) ;
      macroValidPointer (clone) ;
      macroAssignObject (mPointer, clone) ;
    }
    ((cPtr_root_obj *) mPointer)->resources = inValue ;
  }
}

//---------------------------------------------------------------------------*

void GGS_root_obj::
modifier_setIsrs (C_Compiler & /* inLexique */, const GGS_isr_map & inValue COMMA_UNUSED_LOCATION_ARGS) {
  if ((mPointer != NULL) && inValue.isBuilt ()) {
    macroValidPointer (mPointer) ;
    if (mPointer->retainCount () > 1) {
      cPtr_root_obj * clone = dynamic_cast <cPtr_root_obj *> (mPointer->makeClone ()) ;
      macroValidPointer (clone) ;
      macroAssignObject (mPointer, clone) ;
    }
    ((cPtr_root_obj *) mPointer)->isrs = inValue ;
  }
}

//---------------------------------------------------------------------------*

void GGS_root_obj::
modifier_setScheduletables (C_Compiler & /* inLexique */, const GGS_scheduletable_map & inValue COMMA_UNUSED_LOCATION_ARGS) {
  if ((mPointer != NULL) && inValue.isBuilt ()) {
    macroValidPointer (mPointer) ;
    if (mPointer->retainCount () > 1) {
      cPtr_root_obj * clone = dynamic_cast <cPtr_root_obj *> (mPointer->makeClone ()) ;
      macroValidPointer (clone) ;
      macroAssignObject (mPointer, clone) ;
    }
    ((cPtr_root_obj *) mPointer)->scheduletables = inValue ;
  }
}

//---------------------------------------------------------------------------*

const char * GGS_root_obj::actualTypeName (void) const {
  return "root_obj" ;
}

//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformationEX * GGS_root_obj::galgasObjectRunTimeInfo (void) const {
  AC_galgasClassRunTimeInformationEX * result = NULL ;
  if (mPointer != NULL) {
    result = mPointer->galgasRTTI () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_galgasRootClassRunTimeInformationEX gClassInfoFor__root_obj ("root_obj", & kTypeDescriptor_GGS_root_obj) ;

//---------------------------------------------------------------------------*

GGS_object GGS_root_obj::reader_object (void) const {
  GGS_object result ;
  if (isBuilt ()) {
    GGS_root_obj * p = NULL ;
    macroMyNew (p, GGS_root_obj (*this)) ;
    result = GGS_object (p) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_root_obj GGS_root_obj::castFromObject (C_Compiler & inLexique,
                                   const GGS_object & inObject,
                                   const GGS_location & inErrorLocation
                                   COMMA_LOCATION_ARGS) {
  GGS_root_obj result ;
  const GGS__root * embeddedObject = inObject.embeddedObject () ;
  if (NULL != embeddedObject) {
    const GGS_root_obj * p = dynamic_cast <const GGS_root_obj *> (embeddedObject) ;
    if (NULL != p) {
      result = * p ;
    }else{
      castFromObjectErrorSignaling (inLexique, inErrorLocation, & kTypeDescriptor_GGS_root_obj, embeddedObject COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX * GGS_root_obj::typeDescriptor (void) const {
  return & kTypeDescriptor_GGS_root_obj ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of function "void_root_obj"                 *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_root_obj  function_void_root_obj (C_Compiler & inLexique COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER function_void_root_obj at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_root_obj  var_cas_cpu ;
  var_cas_cpu = GGS_root_obj ::constructor_new (inLexique, function_empty_lstring (inLexique COMMA_SOURCE_FILE_AT_LINE (33)), function_void_os_obj (inLexique COMMA_SOURCE_FILE_AT_LINE (34)), function_void_com_obj (inLexique COMMA_SOURCE_FILE_AT_LINE (35)), GGS_task_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_counter_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_alarm_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_resource_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_event_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_isr_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_message_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_netmess_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_scheduletable_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_app_map ::constructor_emptyMap (inLexique COMMA_HERE) COMMA_HERE) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_void_root_obj\n") ;
  #endif
  return var_cas_cpu ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_void_root_obj (C_Compiler & inLexique,
                           const GGS_objectlist & /* inEffectiveParameterArray */,
                           const GGS_location & /* inErrorLocation */
                           COMMA_LOCATION_ARGS) {
  const GGS_root_obj  result = function_void_root_obj (inLexique
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

const C_galgas_function_descriptorEX kFunction_descriptor_void_root_obj ("void_root_obj",
                              functionForGenericCall_void_root_obj,
                              & kTypeDescriptor_GGS_root_obj ,
                              0,
                              NULL) ;

//---------------------------------------------------------------------------*

