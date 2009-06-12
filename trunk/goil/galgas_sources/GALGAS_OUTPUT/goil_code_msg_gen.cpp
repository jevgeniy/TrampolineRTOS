//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_code_msg_gen.cpp'                        *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h47'17"                        *
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
#include "goil_code_msg_gen.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_code_msg_gen.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "generate_network_messages"            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_network_messages (C_Compiler & inLexique,
                                GGS_netmess_map   var_cas_net_messages,
                                GGS_message_map   var_cas_messages,
                                GGS_string & /* var_cas_header */,
                                GGS_string & /* var_cas_obj_header */,
                                GGS_string & var_cas_implementation COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_network_messages at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_i_res ;
  var_cas_i_res = GGS_string ("") ;
  {
    GGS_netmess_map::cEnumerator enumerator_693 (var_cas_net_messages, true) ;
    const GGS_netmess_map::cElement * operand_693 = NULL ;
    while (((operand_693 = enumerator_693.nextObject ()))) {
      macroValidPointer (operand_693) ;
      GGS_string var_cas_mess ;
      GGS_string var_cas_ctype ;
      var_cas_ctype = GGS_string ("") ;
      GGS_string var_cas_inval ;
      var_cas_inval = GGS_string ("") ;
      GGS_string var_cas_nm_name ;
      var_cas_nm_name = operand_693->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (25)) ;
      {
        GGS_message_map::cEnumerator enumerator_824 (var_cas_messages, true) ;
        const GGS_message_map::cElement * operand_824 = NULL ;
        while (((operand_824 = enumerator_824.nextObject ()))) {
          macroValidPointer (operand_824) ;
          { const GGS_mess_prop_obj _var_1080 = operand_824->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (27)) ; // CAST instruction
            if (_var_1080.getPtr () != NULL) {
              macroValidPointer (_var_1080.getPtr ()) ;
              if (typeid (cPtr_sse_mess_prop) == typeid (* (_var_1080.getPtr ()))) {
                const GGS_sse_mess_prop var_cas_sse (_var_1080.getPtr ()) ;
                if (((var_cas_sse.reader_networkmessage (inLexique COMMA_SOURCE_FILE_AT_LINE (29)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (29))).operator_isEqual (var_cas_nm_name)).isBuiltAndTrue ()) {
                  var_cas_ctype = var_cas_sse.reader_cdatatype (inLexique COMMA_SOURCE_FILE_AT_LINE (30)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (30)) ;
                  const GGS_basic_type  _temp_1038 = var_cas_sse.reader_initialvalue (inLexique COMMA_SOURCE_FILE_AT_LINE (31)) ;
                  if (_temp_1038.isBuilt ()) {
                    _temp_1038 (HERE)->method_string (inLexique, var_cas_inval COMMA_SOURCE_FILE_AT_LINE (31)) ;
                  }
                }
              }else{
              }
            }
          }
        }
      }
      const GGS_netmess_obj  _temp_1128 = operand_693->mInfo.netmess ;
      if (_temp_1128.isBuilt ()) {
        _temp_1128 (HERE)->method_generate (inLexique, operand_693->mKey, var_cas_ctype, var_cas_inval, var_cas_mess COMMA_SOURCE_FILE_AT_LINE (35)) ;
      }
      var_cas_i_res.dotAssign_operation (var_cas_mess) ;
    }
  }
  ::routine_doReplace (inLexique,  var_cas_implementation,  GGS_string ("$NETWORKMESSAGES$"),  var_cas_i_res COMMA_SOURCE_FILE_AT_LINE (39)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_network_messages\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "generate_messages"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_messages (C_Compiler & inLexique,
                                GGS_message_map   var_cas_messages,
                                GGS_prefix_map   /* var_cas_p */,
                                GGS_string & var_cas_header,
                                GGS_string & var_cas_obj_header,
                                GGS_string & var_cas_implementation COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_messages at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_h_res ;
  var_cas_h_res = GGS_string ("") ;
  GGS_string var_cas_i_res ;
  var_cas_i_res = GGS_string ("") ;
  GGS_message_map  var_cas_mm ;
  var_cas_mm = var_cas_messages ;
  GGS_ident_list_map  var_cas_dests ;
  var_cas_dests = GGS_ident_list_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
  {
    GGS_message_map::cEnumerator enumerator_1849 (var_cas_mm, true) ;
    const GGS_message_map::cElement * operand_1849 = NULL ;
    while (((operand_1849 = enumerator_1849.nextObject ()))) {
      macroValidPointer (operand_1849) ;
      GGS_mess_prop_obj  var_cas_mp ;
      var_cas_mp = operand_1849->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (64)) ;
      GGS_lstring  var_cas_src ;
      const GGS_mess_prop_obj  _temp_1982 = var_cas_mp ;
      if (_temp_1982.isBuilt ()) {
        _temp_1982 (HERE)->method_s_mess (inLexique, var_cas_src COMMA_SOURCE_FILE_AT_LINE (66)) ;
      }
      if ((((var_cas_src.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (68))).operator_isNotEqual (GGS_string (""))).operator_and ((var_cas_dests.reader_hasKey (inLexique, var_cas_src.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (68)) COMMA_SOURCE_FILE_AT_LINE (68))).operator_not ())).isBuiltAndTrue ()) {
        GGS_ident_list  var_cas_dest_list ;
        var_cas_dest_list = GGS_ident_list ::constructor_emptyList () ;
        {
          GGS_message_map::cEnumerator enumerator_2134 (var_cas_mm, true) ;
          const GGS_message_map::cElement * operand_2134 = NULL ;
          while (((operand_2134 = enumerator_2134.nextObject ()))) {
            macroValidPointer (operand_2134) ;
            GGS_mess_prop_obj  var_cas_same_mp ;
            var_cas_same_mp = operand_2134->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (71)) ;
            GGS_lstring  var_cas_same_src ;
            const GGS_mess_prop_obj  _temp_2321 = var_cas_same_mp ;
            if (_temp_2321.isBuilt ()) {
              _temp_2321 (HERE)->method_s_mess (inLexique, var_cas_same_src COMMA_SOURCE_FILE_AT_LINE (73)) ;
            }
            if (((var_cas_same_src.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (74))).operator_isEqual (var_cas_src.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (74)))).isBuiltAndTrue ()) {
              var_cas_dest_list._addAssign_operation (operand_2134->mKey) ;
            }
          }
        }
        var_cas_dests.modifier_add (inLexique, var_cas_src, var_cas_dest_list COMMA_SOURCE_FILE_AT_LINE (78)) ;
      }
    }
  }
  GGS_string var_cas_result ;
  var_cas_result = GGS_string ("") ;
  GGS_message_map  var_cas_extern_mess ;
  var_cas_extern_mess = var_cas_messages ;
  {
    GGS_ident_list_map::cEnumerator enumerator_2978 (var_cas_dests, true) ;
    const GGS_ident_list_map::cElement * operand_2978 = NULL ;
    while (((operand_2978 = enumerator_2978.nextObject ()))) {
      macroValidPointer (operand_2978) ;
      GGS_ident_list  var_cas_dm ;
      var_cas_dm = operand_2978->mInfo.objs ;
      GGS_uint _variant_3644 = var_cas_dm.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (105)) ;
      GGS_bool _condition_3644 (_variant_3644.isBuilt (), true) ;
      while (_condition_3644.isBuiltAndTrue ()) {
        _condition_3644 = (var_cas_dm.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (106))).operator_strictSup (GGS_uint (0U)) ;
        if (_condition_3644.isBuiltAndTrue ()) {
          if (_variant_3644.uintValue () == 0) {
            inLexique.onTheFlyRunTimeError ("loop variant error" COMMA_SOURCE_FILE_AT_LINE (116)) ;
            _condition_3644 = GGS_bool (false) ;
          }else{
            _variant_3644.decrement_operation (inLexique COMMA_HERE) ;
            GGS_lstring  var_cas_mname ;
            GGS_message_obj  var_cas_mess ;
            var_cas_dm.modifier_popLast (inLexique, var_cas_mname COMMA_SOURCE_FILE_AT_LINE (109)) ;
            const GGS_message_map  _temp_3363 = var_cas_messages ;
            if (_temp_3363.isBuilt ()) {
              _temp_3363 (HERE)->method_get (inLexique, var_cas_mname, var_cas_mess COMMA_SOURCE_FILE_AT_LINE (110)) ;
            }
            GGS_message_obj  automatic_var_0 ;
            var_cas_extern_mess.modifier_del (inLexique, var_cas_mname, automatic_var_0 COMMA_SOURCE_FILE_AT_LINE (112)) ;
            GGS_mess_prop_obj  var_cas_mp ;
            var_cas_mp = var_cas_mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (113)) ;
            const GGS_mess_prop_obj  _temp_3555 = var_cas_mp ;
            if (_temp_3555.isBuilt ()) {
              _temp_3555 (HERE)->method_generate (inLexique, var_cas_mname, var_cas_mess, var_cas_messages, var_cas_dests, var_cas_h_res, var_cas_i_res COMMA_SOURCE_FILE_AT_LINE (114)) ;
            }
            var_cas_result.dotAssign_operation (var_cas_i_res) ;
          }
        }
      }
      GGS_message_obj  automatic_var_1 ;
      var_cas_extern_mess.modifier_del (inLexique, operand_2978->mKey, automatic_var_1 COMMA_SOURCE_FILE_AT_LINE (119)) ;
      GGS_lstring  var_cas_mname ;
      GGS_message_obj  var_cas_mess ;
      const GGS_message_map  _temp_3811 = var_cas_messages ;
      if (_temp_3811.isBuilt ()) {
        _temp_3811 (HERE)->method_get (inLexique, operand_2978->mKey, var_cas_mess COMMA_SOURCE_FILE_AT_LINE (123)) ;
      }
      GGS_mess_prop_obj  var_cas_mp ;
      var_cas_mp = var_cas_mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (124)) ;
      const GGS_mess_prop_obj  _temp_3900 = var_cas_mp ;
      if (_temp_3900.isBuilt ()) {
        _temp_3900 (HERE)->method_generate (inLexique, operand_2978->mKey, var_cas_mess, var_cas_messages, var_cas_dests, var_cas_h_res, var_cas_i_res COMMA_SOURCE_FILE_AT_LINE (125)) ;
      }
      var_cas_result.dotAssign_operation (var_cas_i_res) ;
    }
  }
  {
    GGS_message_map::cEnumerator enumerator_4051 (var_cas_extern_mess, true) ;
    const GGS_message_map::cElement * operand_4051 = NULL ;
    while (((operand_4051 = enumerator_4051.nextObject ()))) {
      macroValidPointer (operand_4051) ;
      GGS_mess_prop_obj  var_cas_mp ;
      var_cas_mp = operand_4051->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (131)) ;
      const GGS_mess_prop_obj  _temp_4163 = var_cas_mp ;
      if (_temp_4163.isBuilt ()) {
        _temp_4163 (HERE)->method_generate (inLexique, operand_4051->mKey, operand_4051->mInfo.mess, var_cas_messages, var_cas_dests, var_cas_h_res, var_cas_i_res COMMA_SOURCE_FILE_AT_LINE (132)) ;
      }
      var_cas_result.dotAssign_operation (var_cas_i_res) ;
    }
  }
  GGS_stringset  var_cas_smo ;
  var_cas_smo = GGS_stringset ::constructor_emptySet () ;
  GGS_stringset  var_cas_rmo ;
  var_cas_rmo = GGS_stringset ::constructor_emptySet () ;
  GGS_stringset  var_cas_flags ;
  var_cas_flags = GGS_stringset ::constructor_emptySet () ;
  {
    GGS_message_map::cEnumerator enumerator_4799 (var_cas_messages, true) ;
    const GGS_message_map::cElement * operand_4799 = NULL ;
    while (((operand_4799 = enumerator_4799.nextObject ()))) {
      macroValidPointer (operand_4799) ;
      GGS_mess_prop_obj  var_cas_mp ;
      var_cas_mp = operand_4799->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (151)) ;
      { const GGS_mess_prop_obj _var_5748 = var_cas_mp ; // CAST instruction
        if (_var_5748.getPtr () != NULL) {
          macroValidPointer (_var_5748.getPtr ()) ;
          if (typeid (cPtr_ssi_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_smo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (153))) ;
          }else if (typeid (cPtr_sse_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_smo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (154))) ;
          }else if (typeid (cPtr_sde_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_smo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (155))) ;
          }else if (typeid (cPtr_szi_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_smo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (156))) ;
          }else if (typeid (cPtr_sze_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_smo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (157))) ;
          }else if (typeid (cPtr_rzi_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (158))) ;
          }else if (typeid (cPtr_rze_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (159))) ;
          }else if (typeid (cPtr_rui_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (160))) ;
          }else if (typeid (cPtr_rqi_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (161))) ;
          }else if (typeid (cPtr_rue_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (162))) ;
          }else if (typeid (cPtr_rqe_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (163))) ;
          }else if (typeid (cPtr_rde_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (164))) ;
          }else if (typeid (cPtr_rzs_mess_prop) == typeid (* (_var_5748.getPtr ()))) {
            var_cas_rmo._addAssign_operation (operand_4799->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (165))) ;
          }else{
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Internal error, illegal message object type") COMMA_SOURCE_FILE_AT_LINE (167)) ;
          }
        }
      }
      GGS_action_obj  var_cas_notif ;
      var_cas_notif = operand_4799->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (169)) ;
      const GGS_action_obj  _temp_5827 = var_cas_notif ;
      if (_temp_5827.isBuilt ()) {
        _temp_5827 (HERE)->method_flag (inLexique, var_cas_flags COMMA_SOURCE_FILE_AT_LINE (170)) ;
      }
      var_cas_notif = operand_4799->mInfo.mess.reader_notificationerror (inLexique COMMA_SOURCE_FILE_AT_LINE (171)) ;
      const GGS_action_obj  _temp_5902 = var_cas_notif ;
      if (_temp_5902.isBuilt ()) {
        _temp_5902 (HERE)->method_flag (inLexique, var_cas_flags COMMA_SOURCE_FILE_AT_LINE (172)) ;
      }
    }
  }
  GGS_string var_cas_h_tab ;
  var_cas_h_tab = GGS_string ("") ;
  GGS_string var_cas_i_tab ;
  var_cas_i_tab = GGS_string ("") ;
  {
    GGS_stringset::cEnumerator enumerator_6007 (var_cas_smo, true) ;
    if (enumerator_6007 .hc ()) {
      GGS_uint var_cas_n (true, 0) ;
      var_cas_i_tab = GGS_string ("CONSTP2VAR(tpl_base_sending_mo, AUTOMATIC, OS_APPL_DATA)\n") ;
      var_cas_i_tab.appendCString ("  tpl_send_message_table[SEND_MESSAGE_COUNT] = {\n") ;
      bool _foreach_loop_6007 ;
      do{
        var_cas_i_tab.appendCString ("  (tpl_base_sending_mo *)&") ;
        var_cas_i_tab.dotAssign_operation (enumerator_6007._key (HERE)) ;
        var_cas_i_tab.appendCString ("_message") ;
        var_cas_h_tab.appendCString ("#define ") ;
        var_cas_h_tab.dotAssign_operation (enumerator_6007._key (HERE)) ;
        var_cas_h_tab.appendCString ("_id ") ;
        var_cas_h_tab.dotAssign_operation (var_cas_n.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (187))) ;
        var_cas_h_tab.appendCString ("\n") ;
        var_cas_h_tab.appendCString ("CONST(MessageIdentifier, AUTOMATIC) ") ;
        var_cas_h_tab.dotAssign_operation (enumerator_6007._key (HERE)) ;
        var_cas_h_tab.appendCString (" = ") ;
        var_cas_h_tab.dotAssign_operation (enumerator_6007._key (HERE)) ;
        var_cas_h_tab.appendCString ("_id;\n") ;
        var_cas_n.mValue ++ ;
        enumerator_6007.next () ;
        _foreach_loop_6007 = (enumerator_6007 .hc ()) ;
        if (_foreach_loop_6007) {
          var_cas_i_tab.appendCString (",\n") ;
        }
      }while (_foreach_loop_6007) ;
      var_cas_i_tab.appendCString ("\n"
        "};\n") ;
    }
  }
  var_cas_h_res.appendCString ("\n") ;
  var_cas_h_res.dotAssign_operation (var_cas_h_tab) ;
  var_cas_result.appendCString ("\n") ;
  var_cas_result.dotAssign_operation (var_cas_i_tab) ;
  var_cas_h_tab = GGS_string ("") ;
  var_cas_i_tab = GGS_string ("") ;
  {
    GGS_stringset::cEnumerator enumerator_6610 (var_cas_rmo, true) ;
    if (enumerator_6610 .hc ()) {
      GGS_uint var_cas_n (true, 0) ;
      var_cas_i_tab = GGS_string ("CONSTP2VAR(tpl_base_receiving_mo, AUTOMATIC, OS_APPL_DATA)\n") ;
      var_cas_i_tab.appendCString ("  tpl_receive_message_table[RECEIVE_MESSAGE_COUNT] = {\n") ;
      var_cas_h_tab = GGS_string ("") ;
      bool _foreach_loop_6610 ;
      do{
        var_cas_i_tab.appendCString ("  (tpl_base_receiving_mo *)&") ;
        var_cas_i_tab.dotAssign_operation (enumerator_6610._key (HERE)) ;
        var_cas_i_tab.appendCString ("_message") ;
        var_cas_h_tab.appendCString ("#define ") ;
        var_cas_h_tab.dotAssign_operation (enumerator_6610._key (HERE)) ;
        var_cas_h_tab.appendCString ("_id ") ;
        var_cas_h_tab.dotAssign_operation (var_cas_n.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (207))) ;
        var_cas_h_tab.appendCString ("\n") ;
        var_cas_h_tab.appendCString ("CONST(MessageIdentifier, AUTOMATIC) ") ;
        var_cas_h_tab.dotAssign_operation (enumerator_6610._key (HERE)) ;
        var_cas_h_tab.appendCString (" = ") ;
        var_cas_h_tab.dotAssign_operation (enumerator_6610._key (HERE)) ;
        var_cas_h_tab.appendCString ("_id;\n") ;
        var_cas_n.mValue ++ ;
        enumerator_6610.next () ;
        _foreach_loop_6610 = (enumerator_6610 .hc ()) ;
        if (_foreach_loop_6610) {
          var_cas_i_tab.appendCString (",\n") ;
        }
      }while (_foreach_loop_6610) ;
      var_cas_i_tab.appendCString ("\n"
        "};\n") ;
    }
  }
  var_cas_h_res.appendCString ("\n") ;
  var_cas_h_res.dotAssign_operation (var_cas_h_tab) ;
  var_cas_result.appendCString ("\n") ;
  var_cas_result.dotAssign_operation (var_cas_i_tab) ;
  ::routine_doReplace (inLexique,  var_cas_implementation,  GGS_string ("$MESSAGES$"),  var_cas_result COMMA_SOURCE_FILE_AT_LINE (221)) ;
  ::routine_doReplace (inLexique,  var_cas_implementation,  GGS_string ("$MESSAGEIDS$"),  var_cas_h_res COMMA_SOURCE_FILE_AT_LINE (222)) ;
  ::routine_doReplace (inLexique,  var_cas_obj_header,  GGS_string ("$SEND_MESSAGE_COUNT$"),  var_cas_smo.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (223)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (223)) COMMA_SOURCE_FILE_AT_LINE (223)) ;
  ::routine_doReplace (inLexique,  var_cas_obj_header,  GGS_string ("$RECEIVE_MESSAGE_COUNT$"),  var_cas_rmo.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (224)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (224)) COMMA_SOURCE_FILE_AT_LINE (224)) ;
  GGS_uint  var_cas_flag_count ;
  var_cas_flag_count = var_cas_flags.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (229)).divide_operation (inLexique, GGS_uint (8U) COMMA_SOURCE_FILE_AT_LINE (229)) ;
  if (((var_cas_flags.reader_count (inLexique COMMA_SOURCE_FILE_AT_LINE (230)).modulo_operation (inLexique, GGS_uint (8U) COMMA_SOURCE_FILE_AT_LINE (230))).operator_isNotEqual (GGS_uint (0U))).isBuiltAndTrue ()) {
    var_cas_flag_count.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (231)) ;
  }
  var_cas_h_res = GGS_string ("") ;
  var_cas_result = GGS_string ("") ;
  if (((var_cas_flag_count).operator_strictSup (GGS_uint (0U))).isBuiltAndTrue ()) {
    var_cas_h_res = ((GGS_string ("extern u8 tpl_notification_flags[")).operator_concat (var_cas_flag_count.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (238)))).operator_concat (GGS_string ("];\n")) ;
    var_cas_result = ((GGS_string ("u8 tpl_notification_flags[")).operator_concat (var_cas_flag_count.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (240)))).operator_concat (GGS_string ("]\n"
      "    = { ")) ;
    GGS_uint  var_cas_i ;
    var_cas_i = GGS_uint (1U) ;
    GGS_uint _variant_8129 = var_cas_flag_count ;
    GGS_bool _condition_8129 (_variant_8129.isBuilt (), true) ;
    while (_condition_8129.isBuiltAndTrue ()) {
      _condition_8129 = (var_cas_i).operator_infOrEqual (var_cas_flag_count) ;
      if (_condition_8129.isBuiltAndTrue ()) {
        if (_variant_8129.uintValue () == 0) {
          inLexique.onTheFlyRunTimeError ("loop variant error" COMMA_SOURCE_FILE_AT_LINE (247)) ;
          _condition_8129 = GGS_bool (false) ;
        }else{
          _variant_8129.decrement_operation (inLexique COMMA_HERE) ;
          var_cas_result.appendCString ("0") ;
          if (((var_cas_i).operator_strictInf (var_cas_flag_count)).isBuiltAndTrue ()) {
            var_cas_result.appendCString (", ") ;
          }
          var_cas_i.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (246)) ;
        }
      }
    }
    var_cas_result.appendCString (" };\n") ;
    GGS_uint  var_cas_flag_order ;
    var_cas_flag_order = GGS_uint (0U) ;
    GGS_string var_cas_flag_macros ;
    GGS_string var_cas_flag_function ;
    ::routine_retrieveTemplateString (inLexique,  var_cas_flag_macros,  GGS_string ("flag_macros") COMMA_SOURCE_FILE_AT_LINE (253)) ;
    ::routine_retrieveTemplateString (inLexique,  var_cas_flag_function,  GGS_string ("flag_function") COMMA_SOURCE_FILE_AT_LINE (254)) ;
    {
      GGS_stringset::cEnumerator enumerator_8420 (var_cas_flags, true) ;
      while (enumerator_8420.hc ()) {
        GGS_string var_cas_fm ;
        var_cas_fm = var_cas_flag_macros ;
        ::routine_doReplace (inLexique,  var_cas_fm,  GGS_string ("$FLAGNAME$"),  enumerator_8420._key (HERE) COMMA_SOURCE_FILE_AT_LINE (258)) ;
        GGS_uint  var_cas_flag_elem ;
        var_cas_flag_elem = var_cas_flag_order.divide_operation (inLexique, GGS_uint (8U) COMMA_SOURCE_FILE_AT_LINE (259)) ;
        GGS_uint  var_cas_flag_bit ;
        var_cas_flag_bit = var_cas_flag_order.modulo_operation (inLexique, GGS_uint (8U) COMMA_SOURCE_FILE_AT_LINE (260)) ;
        GGS_uint  var_cas_flag_mask ;
        var_cas_flag_mask = GGS_uint (1U).left_shift_operation (inLexique, var_cas_flag_bit COMMA_SOURCE_FILE_AT_LINE (261)) ;
        GGS_uint  var_cas_invert_flag_mask ;
        var_cas_invert_flag_mask = (var_cas_flag_mask.left_shift_operation (inLexique, GGS_uint (24U) COMMA_SOURCE_FILE_AT_LINE (262))).operator_tilde ().right_shift_operation (inLexique, GGS_uint (24U) COMMA_SOURCE_FILE_AT_LINE (262)) ;
        GGS_string var_cas_flag_read ;
        GGS_string var_cas_flag_reset ;
        if (((var_cas_flag_bit).operator_isEqual (GGS_uint (0U))).isBuiltAndTrue ()) {
          var_cas_flag_read = ((GGS_string ("(tpl_notification_flags[")).operator_concat (var_cas_flag_elem.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (266)))).operator_concat (GGS_string ("] & 0x1)")) ;
        }else{
          var_cas_flag_read = ((((((GGS_string ("((tpl_notification_flags[")).operator_concat (var_cas_flag_elem.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (268)))).operator_concat (GGS_string ("] & "))).operator_concat (var_cas_flag_mask.reader_hexString (inLexique COMMA_SOURCE_FILE_AT_LINE (268)))).operator_concat (GGS_string (") >> "))).operator_concat (var_cas_flag_bit.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (268)))).operator_concat (GGS_string (")")) ;
        }
        var_cas_flag_reset = (((GGS_string ("tpl_notification_flags[")).operator_concat (var_cas_flag_elem.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (270)))).operator_concat (GGS_string ("] &= "))).operator_concat (var_cas_invert_flag_mask.reader_hexString (inLexique COMMA_SOURCE_FILE_AT_LINE (270))) ;
        ::routine_doReplace (inLexique,  var_cas_fm,  GGS_string ("$FLAG_READ_EXP$"),  var_cas_flag_read COMMA_SOURCE_FILE_AT_LINE (271)) ;
        ::routine_doReplace (inLexique,  var_cas_fm,  GGS_string ("$FLAG_RESET_EXP$"),  var_cas_flag_reset COMMA_SOURCE_FILE_AT_LINE (272)) ;
        GGS_string var_cas_ff ;
        var_cas_ff = var_cas_flag_function ;
        ::routine_doReplace (inLexique,  var_cas_ff,  GGS_string ("$FLAGNAME$"),  enumerator_8420._key (HERE) COMMA_SOURCE_FILE_AT_LINE (275)) ;
        GGS_string var_cas_flag_set ;
        var_cas_flag_set = (((GGS_string ("tpl_notification_flags[")).operator_concat (var_cas_flag_elem.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (278)))).operator_concat (GGS_string ("] |= "))).operator_concat (var_cas_flag_mask.reader_hexString (inLexique COMMA_SOURCE_FILE_AT_LINE (278))) ;
        ::routine_doReplace (inLexique,  var_cas_ff,  GGS_string ("$FLAG_SET_EXP$"),  var_cas_flag_set COMMA_SOURCE_FILE_AT_LINE (279)) ;
        var_cas_flag_order.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (281)) ;
        var_cas_h_res.dotAssign_operation (var_cas_fm) ;
        var_cas_result.dotAssign_operation (var_cas_ff) ;
        enumerator_8420.next () ;
      }
    }
  }
  ::routine_doReplace (inLexique,  var_cas_header,  GGS_string ("$FLAGSMACROS$"),  var_cas_h_res COMMA_SOURCE_FILE_AT_LINE (288)) ;
  ::routine_doReplace (inLexique,  var_cas_implementation,  GGS_string ("$FLAGSFUNCTIONS$"),  var_cas_result COMMA_SOURCE_FILE_AT_LINE (289)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_messages\n") ;
  #endif
}

//---------------------------------------------------------------------------*

