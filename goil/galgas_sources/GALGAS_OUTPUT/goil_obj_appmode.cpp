//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_obj_appmode.cpp'                         *
//                        Generated by version 2.0.1                         *
//                    september 3rd, 2010, at 11h11'58"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 837
  #error "This file has been compiled with a version of GALGAS that uses libpm version 837, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_appmode.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_appmode.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of production rule 'appmode'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_appmode::rule_goil_5F_obj_5F_appmode_appmode_i0_ (C_Lexique_goil_5F_lexique & inLexique) {
  GGS_ident_map  var_cas_others = GGS_ident_map ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (45)) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_APPMODE) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_appmode_0 (inLexique)) {
        case 2 : {
          nt_free_5F_field_ (inLexique, var_cas_others) ;
          GGS_lstring  automatic_var_1002_0 ;
          nt_description_ (inLexique, automatic_var_1002_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  GGS_lstring  automatic_var_1058_0 ;
  nt_description_ (inLexique, automatic_var_1058_0) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

void goil_obj_appmode::rule_goil_5F_obj_5F_appmode_appmode_i0_parse (C_Lexique_goil_5F_lexique & inLexique) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_APPMODE) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_appmode_0 (inLexique)) {
        case 2 : {
          nt_free_5F_field_parse (inLexique) ;
          nt_description_parse (inLexique) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  nt_description_parse (inLexique) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
  GGS_lstring::constructor_retrieveAndResetTemplateString (inLexique COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

