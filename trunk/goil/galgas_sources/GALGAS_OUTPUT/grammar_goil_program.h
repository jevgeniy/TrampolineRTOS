//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'grammar_goil_program.h'                        *
//                Generated by version 1.3.1 (LL(1) grammar)                 *
//                       june 6th, 2006, at 11h54'13"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

class goil_program : public C_defaultUserSemanticActions {
  protected : goil_lexique * mScannerPtr_ ;
  protected : C_galgas_terminal_io mTerminalIO ;
  protected : C_String mSourceFileExtension_ ;

//--- Command line options

//--- Constructor
  public : goil_program (const C_galgas_io_parameters & inIOparameters COMMA_LOCATION_ARGS) ;

  public : void doCompilation (const C_String & inSourceFileName_,
                               sint16 & returnCode) ;
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//--- Destructor
  public : virtual ~goil_program (void) ;
//--- Prologue and epilogue
  public : void _prologue (void) ;
  public : void _epilogue (void) ;
} ;

