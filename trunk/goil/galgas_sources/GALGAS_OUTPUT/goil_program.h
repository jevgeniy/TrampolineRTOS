//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_program.h'                            *
//                        Generated by version 1.8.3                         *
//                       may 29th, 2009, at 11h56'23"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef INTERFACE_goil_program_DEFINED
#define INTERFACE_goil_program_DEFINED

//---------------------------------------------------------------------------*

#include "goil_options.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "galgas/C_Lexique.h"
#include "command_line_interface/C_CLI_OptionGroup.h"
#include "command_line_interface/C_builtin_CLI_Options.h"

//---------------------------------------------------------------------------*

class C_options_for_goil_program : public C_CLI_OptionGroup {
//--- Constructor
  public : C_options_for_goil_program (const bool inAcceptsDebugOption) ;

//--- Included options
  private : C_builtin_CLI_Options mBuiltinOptions ;
  private : C_galgas_CLI_Options mGalgasOptions ;
  private : goil_options mOptions_goil_options; 
} ;

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

#endif
