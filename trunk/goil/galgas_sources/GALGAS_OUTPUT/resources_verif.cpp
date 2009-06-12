//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'resources_verif.cpp'                         *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h44'54"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 502
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "resources_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "resources_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "resources_well_formed"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_resources_well_formed (C_Compiler & inLexique,
                                const GGS_resource_map   var_cas_resources COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_resources_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_resource_map::cEnumerator enumerator_864 (var_cas_resources, true) ;
    const GGS_resource_map::cElement * operand_864 = NULL ;
    while (((operand_864 = enumerator_864.nextObject ()))) {
      macroValidPointer (operand_864) ;
      { const GGS_resource_property_obj _var_1116 = operand_864->mInfo.resource.reader_property (inLexique COMMA_SOURCE_FILE_AT_LINE (45)) ; // CAST instruction
        if (_var_1116.getPtr () != NULL) {
          macroValidPointer (_var_1116.getPtr ()) ;
          if (typeid (cPtr_resource_property_void_obj) == typeid (* (_var_1116.getPtr ()))) {
            operand_864->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("RESOURCEPROPERTY attribute undefined for RESOURCE ")).operator_concat (operand_864->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (47))) COMMA_SOURCE_FILE_AT_LINE (48)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_resources_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of routine "resolve_linked_resources"            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_resolve_linked_resources (C_Compiler & inLexique,
                                GGS_resource_map  & var_cas_resources COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_resolve_linked_resources at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_resource_map  var_cas_resolved ;
  var_cas_resolved = GGS_resource_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_resource_map  var_cas_unresolved ;
  var_cas_unresolved = var_cas_resources ;
  GGS_resource_map  var_cas_unresolved_next ;
  var_cas_unresolved_next = GGS_resource_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_bool var_cas_first_loop ;
  var_cas_first_loop = GGS_bool (true) ;
  GGS_uint _variant_4169 = var_cas_unresolved.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (72)).substract_operation (inLexique, var_cas_unresolved_next.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (72)) COMMA_SOURCE_FILE_AT_LINE (72)).add_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (72)) ;
  GGS_bool _condition_4169 (_variant_4169.isBuilt (), true) ;
  while (_condition_4169.isBuiltAndTrue ()) {
    if ((var_cas_first_loop).isBuiltAndTrue ()) {
      var_cas_first_loop = GGS_bool (false) ;
    }else{
      var_cas_unresolved = var_cas_unresolved_next ;
      var_cas_unresolved_next = GGS_resource_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
    }
    _condition_4169 = (var_cas_unresolved.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (78))).operator_strictSup (GGS_uint (0U)) ;
    if (_condition_4169.isBuiltAndTrue ()) {
      if (_variant_4169.uintValue () == 0) {
        inLexique.onTheFlyRunTimeError ("loop variant error" COMMA_SOURCE_FILE_AT_LINE (131)) ;
        _condition_4169 = GGS_bool (false) ;
      }else{
        _variant_4169.decrement_operation (inLexique COMMA_HERE) ;
        {
          GGS_resource_map::cEnumerator enumerator_1929 (var_cas_unresolved, true) ;
          const GGS_resource_map::cElement * operand_1929 = NULL ;
          while (((operand_1929 = enumerator_1929.nextObject ()))) {
            macroValidPointer (operand_1929) ;
            GGS_resource_property_obj  var_cas_res_prop ;
            var_cas_res_prop = operand_1929->mInfo.resource.reader_property (inLexique COMMA_SOURCE_FILE_AT_LINE (82)) ;
            { const GGS_resource_property_obj _var_3876 = var_cas_res_prop ; // CAST instruction
              if (_var_3876.getPtr () != NULL) {
                macroValidPointer (_var_3876.getPtr ()) ;
                if (typeid (cPtr_resource_property_linked_obj) == typeid (* (_var_3876.getPtr ()))) {
                  const GGS_resource_property_linked_obj var_cas_rplo (_var_3876.getPtr ()) ;
                  if ((var_cas_resolved.reader_hasKey (inLexique, var_cas_rplo.reader_linked_resource (inLexique COMMA_SOURCE_FILE_AT_LINE (90)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (90)) COMMA_SOURCE_FILE_AT_LINE (90))).isBuiltAndTrue ()) {
                    GGS_resource_obj  var_cas_target_resource ;
                    GGS_resource_property_obj  var_cas_target_property ;
                    const GGS_resource_map  _temp_2439 = var_cas_resolved ;
                    if (_temp_2439.isBuilt ()) {
                      _temp_2439 (HERE)->method_get (inLexique, var_cas_rplo.reader_linked_resource (inLexique COMMA_SOURCE_FILE_AT_LINE (93)), var_cas_target_resource COMMA_SOURCE_FILE_AT_LINE (93)) ;
                    }
                    var_cas_target_property = var_cas_target_resource.reader_property (inLexique COMMA_SOURCE_FILE_AT_LINE (94)) ;
                    { const GGS_resource_property_obj _var_3605 = var_cas_target_property ; // CAST instruction
                      if (_var_3605.getPtr () != NULL) {
                        macroValidPointer (_var_3605.getPtr ()) ;
                        if (typeid (cPtr_resource_property_standard_obj) == typeid (* (_var_3605.getPtr ()))) {
                          var_cas_resolved.modifier_put (inLexique, operand_1929->mKey, operand_1929->mInfo.resource COMMA_SOURCE_FILE_AT_LINE (99)) ;
                        }else if (typeid (cPtr_resource_property_internal_obj) == typeid (* (_var_3605.getPtr ()))) {
                          var_cas_target_property.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (103)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (((GGS_string ("RESOURCE ")).operator_concat (operand_1929->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (103)))).operator_concat (GGS_string (" is linked to INTERNAL RESOURCE "))).operator_concat (var_cas_rplo.reader_linked_resource (inLexique COMMA_SOURCE_FILE_AT_LINE (103)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (103))) COMMA_SOURCE_FILE_AT_LINE (106)) ;
                        }else if (typeid (cPtr_resource_property_linked_obj) == typeid (* (_var_3605.getPtr ()))) {
                          const GGS_resource_property_linked_obj var_cas_nrplo (_var_3605.getPtr ()) ;
                          GGS_resource_property_linked_obj  var_cas_resolved_prop ;
                          var_cas_resolved_prop = GGS_resource_property_linked_obj ::constructor_new (inLexique, var_cas_nrplo.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (108)), var_cas_nrplo.reader_linked_resource (inLexique COMMA_SOURCE_FILE_AT_LINE (108)) COMMA_HERE) ;
                          GGS_lstring  var_cas_resolved_desc ;
                          var_cas_resolved_desc = operand_1929->mInfo.resource.reader_desc (inLexique COMMA_SOURCE_FILE_AT_LINE (109)) ;
                          GGS_resource_obj  var_cas_resolved_res ;
                          var_cas_resolved_res = GGS_resource_obj ::constructor_new (inLexique, var_cas_resolved_desc, var_cas_resolved_prop, operand_1929->mInfo.resource.reader_acc_apps (inLexique COMMA_SOURCE_FILE_AT_LINE (110)) COMMA_HERE) ;
                          var_cas_resolved.modifier_put (inLexique, operand_1929->mKey, var_cas_resolved_res COMMA_SOURCE_FILE_AT_LINE (111)) ;
                        }else{
                        }
                      }
                    }
                  }else{
                    var_cas_unresolved_next.modifier_put (inLexique, operand_1929->mKey, operand_1929->mInfo.resource COMMA_SOURCE_FILE_AT_LINE (117)) ;
                  }
                }else{
                  var_cas_resolved.modifier_put (inLexique, operand_1929->mKey, operand_1929->mInfo.resource COMMA_SOURCE_FILE_AT_LINE (121)) ;
                }
              }
            }
          }
        }
        if (((var_cas_unresolved.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (124))).operator_isEqual (var_cas_unresolved_next.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (124)))).isBuiltAndTrue ()) {
          GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Cycle detected in linked resource") COMMA_SOURCE_FILE_AT_LINE (127)) ;
          {
            GGS_resource_map::cEnumerator enumerator_4049 (var_cas_unresolved_next, true) ;
            const GGS_resource_map::cElement * operand_4049 = NULL ;
            while (((operand_4049 = enumerator_4049.nextObject ()))) {
              macroValidPointer (operand_4049) ;
              operand_4049->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Involved in cycle") COMMA_SOURCE_FILE_AT_LINE (129)) ;
            }
          }
        }
      }
    }
  }
  var_cas_resources = var_cas_resolved ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_resolve_linked_resources\n") ;
  #endif
}

//---------------------------------------------------------------------------*

