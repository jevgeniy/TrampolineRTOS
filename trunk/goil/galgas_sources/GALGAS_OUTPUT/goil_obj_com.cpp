//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_obj_com.cpp'                           *
//                        Generated by version 1.8.2                         *
//                      april 27th, 2009, at 22h45'27"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 463
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_obj_com.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_com.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of production rule 'com'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_com_goil_obj_com_48_10_ (goil_lexique & _inLexique,
                                GGS_com  &var_cas_com) {
  GGS_bool var_cas_usecom ;
  var_cas_usecom = GGS_bool (true, true) ;
  GGS_basic_type  var_cas_tb ;
  var_cas_tb = var_cas_com.reader_timebase (_inLexique COMMA_SOURCE_FILE_AT_LINE (53)) ;
  GGS_basic_type  var_cas_eh ;
  var_cas_eh = var_cas_com.reader_errorhook (_inLexique COMMA_SOURCE_FILE_AT_LINE (54)) ;
  GGS_basic_type  var_cas_ugsid ;
  var_cas_ugsid = var_cas_com.reader_usegetserviceid (_inLexique COMMA_SOURCE_FILE_AT_LINE (55)) ;
  GGS_basic_type  var_cas_upa ;
  var_cas_upa = var_cas_com.reader_useparameteraccess (_inLexique COMMA_SOURCE_FILE_AT_LINE (56)) ;
  GGS_basic_type  var_cas_sce ;
  var_cas_sce = var_cas_com.reader_startcomextension (_inLexique COMMA_SOURCE_FILE_AT_LINE (57)) ;
  GGS_lstringlist  var_cas_am ;
  var_cas_am = var_cas_com.reader_appmodes (_inLexique COMMA_SOURCE_FILE_AT_LINE (58)) ;
  GGS_lstring  var_cas_s ;
  var_cas_s = var_cas_com.reader_status (_inLexique COMMA_SOURCE_FILE_AT_LINE (59)) ;
  GGS_lstringlist  var_cas_u ;
  var_cas_u = var_cas_com.reader_uses (_inLexique COMMA_SOURCE_FILE_AT_LINE (60)) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COM) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_obj_com_0 (_inLexique)) {
        case 2 : {
          nt_comtimebase_ (_inLexique, var_cas_tb) ;
          } break ;
        case 3 : {
          nt_comerrorhook_ (_inLexique, var_cas_eh) ;
          } break ;
        case 4 : {
          nt_comusegetserviceid_ (_inLexique, var_cas_ugsid) ;
          } break ;
        case 5 : {
          nt_comuseparameteraccess_ (_inLexique, var_cas_upa) ;
          } break ;
        case 6 : {
          nt_comstartcomextension_ (_inLexique, var_cas_sce) ;
          } break ;
        case 7 : {
          nt_comappmode_ (_inLexique, var_cas_am) ;
          } break ;
        case 8 : {
          nt_comstatus_ (_inLexique, var_cas_s) ;
          } break ;
        case 9 : {
          nt_use_ (_inLexique, var_cas_u) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
  GGS_lstring  automatic_var_0 ;
  nt_description_ (_inLexique, automatic_var_0) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
  var_cas_com = GGS_com ::constructor_new (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE), var_cas_usecom, var_cas_tb, var_cas_eh, var_cas_ugsid, var_cas_upa, var_cas_sce, var_cas_am, var_cas_s, var_cas_u COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'comtimebase'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comtimebase_goil_obj_com_92_18_ (goil_lexique & _inLexique,
                                GGS_basic_type  &var_cas_tb) {
  GGS_ldouble  var_cas_f ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMTIMEBASE) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  _inLexique._assignFromAttribute_floatNumber (var_cas_f) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_float_5Fnumber) COMMA_HERE) ;
  { const GGS_basic_type _var_2262 = var_cas_tb ; // CAST instruction
    if (_var_2262.getPtr () != NULL) {
      macroValidPointer (_var_2262.getPtr ()) ;
      if (typeid (cPtr_float_class) == typeid (* (_var_2262.getPtr ()))) {
        var_cas_f.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Redefinition of COMTIMEBASE") COMMA_SOURCE_FILE_AT_LINE (100)) ;
        var_cas_tb.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (100)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was defined here") COMMA_SOURCE_FILE_AT_LINE (101)) ;
      }else{
        var_cas_tb = GGS_float_class ::constructor_new (_inLexique, var_cas_f.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)), var_cas_f.reader_double (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)) COMMA_HERE) ;
      }
    }
  }
  GGS_lstring  automatic_var_1 ;
  nt_description_ (_inLexique, automatic_var_1) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'comerrorhook'              *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comerrorhook_goil_obj_com_107_19_ (goil_lexique & _inLexique,
                                GGS_basic_type  &var_cas_eh) {
  GGS_lbool  var_cas_b ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMERRORHOOK) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  nt_boolean_ (_inLexique, var_cas_b) ;
  ::routine_set_bool (_inLexique,  var_cas_eh,  var_cas_b,  GGS_string (true, "COMERRORHOOK") COMMA_SOURCE_FILE_AT_LINE (112)) ;
  GGS_lstring  automatic_var_2 ;
  nt_description_ (_inLexique, automatic_var_2) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'comusegetserviceid'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comusegetserviceid_goil_obj_com_116_25_ (goil_lexique & _inLexique,
                                GGS_basic_type  &var_cas_ugsid) {
  GGS_lbool  var_cas_b ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMUSEGETSERVICEID) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  nt_boolean_ (_inLexique, var_cas_b) ;
  ::routine_set_bool (_inLexique,  var_cas_ugsid,  var_cas_b,  GGS_string (true, "COMUSEGETSERVICEID") COMMA_SOURCE_FILE_AT_LINE (121)) ;
  GGS_lstring  automatic_var_3 ;
  nt_description_ (_inLexique, automatic_var_3) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of production rule 'comuseparameteraccess'          *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comuseparameteraccess_goil_obj_com_125_28_ (goil_lexique & _inLexique,
                                GGS_basic_type  &var_cas_upa) {
  GGS_lbool  var_cas_b ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMUSEPARAMETERACCESS) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  nt_boolean_ (_inLexique, var_cas_b) ;
  ::routine_set_bool (_inLexique,  var_cas_upa,  var_cas_b,  GGS_string (true, "COMUSEPARAMETERACCESS") COMMA_SOURCE_FILE_AT_LINE (130)) ;
  GGS_lstring  automatic_var_4 ;
  nt_description_ (_inLexique, automatic_var_4) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of production rule 'comstartcomextension'          *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comstartcomextension_goil_obj_com_134_27_ (goil_lexique & _inLexique,
                                GGS_basic_type  &var_cas_sce) {
  GGS_lbool  var_cas_b ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMSTARTCOMEXTENSION) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  nt_boolean_ (_inLexique, var_cas_b) ;
  ::routine_set_bool (_inLexique,  var_cas_sce,  var_cas_b,  GGS_string (true, "COMSTARTCOMEXTENSION") COMMA_SOURCE_FILE_AT_LINE (139)) ;
  GGS_lstring  automatic_var_5 ;
  nt_description_ (_inLexique, automatic_var_5) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'comappmode'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comappmode_goil_obj_com_143_17_ (goil_lexique & _inLexique,
                                GGS_lstringlist  &var_cas_am) {
  GGS_lstring  var_cas_s ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMAPPMODE) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  _inLexique._assignFromAttribute_a_string (var_cas_s) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
  ::routine_add_lstring_unique (_inLexique,  var_cas_am,  var_cas_s,  GGS_string (true, "COMAPPMODE") COMMA_SOURCE_FILE_AT_LINE (148)) ;
  GGS_lstring  automatic_var_6 ;
  nt_description_ (_inLexique, automatic_var_6) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'comstatus'                *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_comstatus_goil_obj_com_152_16_ (goil_lexique & _inLexique,
                                GGS_lstring  &var_cas_s) {
  GGS_lstring  var_cas_ss ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMSTATUS) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  switch (select_goil_obj_com_1 (_inLexique)) {
    case 1 : {
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMEXTENDED) COMMA_HERE) ;
      var_cas_ss = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "extended"), GGS_location (_inLexique) COMMA_HERE) ;
      } break ;
    case 2 : {
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COMSTANDARD) COMMA_HERE) ;
      var_cas_ss = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "standard"), GGS_location (_inLexique) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  ::routine_set_lstring_if_empty (_inLexique,  var_cas_s,  var_cas_ss,  GGS_string (true, "COMSTATUS") COMMA_SOURCE_FILE_AT_LINE (162)) ;
  GGS_lstring  automatic_var_7 ;
  nt_description_ (_inLexique, automatic_var_7) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of production rule 'use'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_com::
pr_use_goil_obj_com_166_10_ (goil_lexique & _inLexique,
                                GGS_lstringlist  &var_cas_u) {
  GGS_lstring  var_cas_use ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_USE) COMMA_HERE) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
  _inLexique._assignFromAttribute_a_string (var_cas_use) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
  ::routine_add_lstring_unique (_inLexique,  var_cas_u,  var_cas_use,  GGS_string (true, "USE") COMMA_SOURCE_FILE_AT_LINE (171)) ;
  GGS_lstring  automatic_var_8 ;
  nt_description_ (_inLexique, automatic_var_8) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

