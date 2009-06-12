//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'cfg_syntax.cpp'                            *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h54'23"                        *
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
#include "cfg_syntax.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "cfg_syntax.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'cfg_start'                *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::
pr_cfg_start_cfg_syntax_35_16_ (cfg_lexique & inLexique,
                                GGS_config  &var_cas_cfg) {
  var_cas_cfg = GGS_config ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_task_attrs ;
  var_cas_task_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_isr_attrs ;
  var_cas_isr_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_isr_code_attrs ;
  var_cas_isr_code_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_counter_code_attrs ;
  var_cas_counter_code_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_basic_type  var_cas_its ;
  var_cas_its = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_cfg_syntax_0 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_tpn ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_tp_5Fns_5Fper_5Fcounter_5Ftick) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_integer (var_cas_tpn) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_uint) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          if ((var_cas_cfg.reader_hasKey (inLexique, GGS_string ("wd_ticks_per_ns") COMMA_SOURCE_FILE_AT_LINE (50))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinition of tp_ns_per_counter_tick") COMMA_SOURCE_FILE_AT_LINE (52)) ;
          }else{
            var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("wd_ticks_per_ns"), GGS_location (inLexique) COMMA_HERE), GGS_uint64_class ::constructor_new (inLexique, var_cas_tpn.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (55)), var_cas_tpn.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (55)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (53)) ;
          }
          } break ;
        case 3 : {
          GGS_luint64  var_cas_s_align ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_stack_5Falignment) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_integer (var_cas_s_align) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_uint) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          if ((var_cas_cfg.reader_hasKey (inLexique, GGS_string ("stack_align") COMMA_SOURCE_FILE_AT_LINE (61))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinition of stack_alignment") COMMA_SOURCE_FILE_AT_LINE (63)) ;
          }else{
            var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("stack_align"), GGS_location (inLexique) COMMA_HERE), GGS_uint64_class ::constructor_new (inLexique, var_cas_s_align.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (66)), var_cas_s_align.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (66)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (64)) ;
          }
          } break ;
        case 4 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_task) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (inLexique, var_cas_task_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_isr) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (inLexique, var_cas_isr_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 6 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_isr_5Fcode) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (inLexique, var_cas_isr_code_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 7 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_counter_5Fcode) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (inLexique, var_cas_counter_code_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 8 : {
          nt_interrupts_ (inLexique, var_cas_its) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("task_attrs"), GGS_location (inLexique) COMMA_HERE), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_task_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (89)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("isr_attrs"), GGS_location (inLexique) COMMA_HERE), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_isr_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (93)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("isr_code_attrs"), GGS_location (inLexique) COMMA_HERE), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_isr_code_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (97)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("counter_code_attrs"), GGS_location (inLexique) COMMA_HERE), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_counter_code_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (101)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("it_sources"), GGS_location (inLexique) COMMA_HERE), var_cas_its COMMA_SOURCE_FILE_AT_LINE (105)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'cfg_attrs'                *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::
pr_cfg_attrs_cfg_syntax_109_16_ (cfg_lexique & inLexique,
                                GGS_cfg_attrs  &var_cas_attrs) {
  { bool syntaxRepeat_1 = true ;
    while (syntaxRepeat_1) {
      switch (select_repeat_cfg_syntax_1 (inLexique)) {
        case 2 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          inLexique._assignFromAttribute_keyword (var_cas_oil_attr) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_keyword (var_cas_tpl_attr) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          var_cas_attrs.modifier_put (inLexique, var_cas_oil_attr, var_cas_tpl_attr COMMA_SOURCE_FILE_AT_LINE (117)) ;
          } break ;
        default :
          syntaxRepeat_1 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'interrupts'               *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::
pr_interrupts_cfg_syntax_121_17_ (cfg_lexique & inLexique,
                                GGS_basic_type  &var_cas_its) {
  GGS_ident_map  var_cas_it_src ;
  var_cas_it_src = GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_interrupts) COMMA_HERE) ;
  GGS_location  var_cas_it_loc ;
  var_cas_it_loc = GGS_location (inLexique) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
  { bool syntaxRepeat_2 = true ;
    while (syntaxRepeat_2) {
      switch (select_repeat_cfg_syntax_2 (inLexique)) {
        case 2 : {
          GGS_lstring  var_cas_src ;
          GGS_luint64  var_cas_id ;
          inLexique._assignFromAttribute_keyword (var_cas_src) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          inLexique._assignFromAttribute_integer (var_cas_id) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_uint) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          var_cas_it_src.modifier_put (inLexique, var_cas_src, GGS_uint64_class ::constructor_new (inLexique, var_cas_id.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (132)), var_cas_id.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (132)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (132)) ;
          } break ;
        default :
          syntaxRepeat_2 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
  var_cas_its = GGS_interrupts ::constructor_new (inLexique, var_cas_it_loc, var_cas_it_src COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

