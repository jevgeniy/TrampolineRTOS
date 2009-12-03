# Makefile automatically generated by goil
# Do not modify directly this file, it can be overwritten by goil
# Instead, you can update 'Make-rules' that is included by the Makefile.
#

# make          : build trampoline
# make doc      : extract both dev and user docs from trmpoline sources 
#                 (doxygen and dot required).
# make clean    : remove everything except the Makefile.
# 
# NOTE: dependancies are set by default. To turn off dependancies generation, 
#       use the NODEP symbol, i.e. : make clean NODEP=1
#

#############################################################################
# USER APPLICATION CONFIGURATION
#############################################################################

# name of the generated executable
# it should be declared as APP_NAME in the OS section of the .oil file.
EXEC    =  $APP_NAME$

OIL_FILE = $OIL_FILE$

#sources of the application.
# it should be declared as APP_SRC in the OS section of the .oil file (many times allowed).
SOURCES  = $APP_SRC$

# Trampoline generation flags
$FLAGS$

#CFLAGS: flags used for the compilation process
# it should be declared as CFLAGS in the OS section of the .oil file (many times allowed).
CFLAGS   = $CFLAGS$
#LDLAGS: flags used for the link process
# it should be declared as LDFLAGS in the OS section of the .oil file (many times allowed).
LDFLAGS  = $LDFLAGS$
ifeq ($(strip $(WITH_LINKSCRIPT)),true)
LDFLAGS += -T $(basename $(OIL_FILE))/$SCRIPT_FILE$ -Wl,-Map,$(basename $(OIL_FILE)).map
endif
#ASFLAGS: flags used for the assembly process (if required)
# it should be declared as AS_FLAGS in the OS section of the .oil file (many times allowed).
ASFLAGS  = $ASFLAGS$

#default build directory
BUILD_DIR = build

# Autosar extension
# If 'true', Autosar extension are compiled in (schedule tables, ...)
AUTOSAR = $AUTOSAR_ON$

# Interrupt vector generation
GENITVEC = $GENITVEC$

#############################################################################
# COMPILER CONFIGURATION
#############################################################################

#program used to compile files.
# it should be declared as COMPILER in the OS section of the .oil file.
# default is 'gcc'
CC=$COMPILER$

#program used to link files during compilation process.
# it should be declared as LINKER in the OS section of the .oil file.
# default is 'gcc'
LD=gcc

#program used to link files during compilation process.
# it should be declared as ASSEMBER in the OS section of the .oil file.
# default is 'as'
AS=$ASSEMBLER$

#############################################################################
# TRAMPOLINE CONFIGURATION
#############################################################################

# Trampoline root path to source code.
# it should be declared as TRAMPOLINE_BASE_PATH in the OS section of the .oil file.
TPL_BASE_PATH = $TRAMPOLINE_BASE_PATH$

#Target is given in goil command line when generating the Makefile. 
#If you update the target here, it will be taken into account, and 
#a new Makefile will be generated with the new target.
TARGET=$TRAMPOLINE_TARGET$
$ARCH_CHIP_BOARD$

# WITH_SYSTEM_CALL is true when compiling trampoline
# with system call support. It is false otherwise
WITH_SYSTEM_CALL=$WSC$

#############################################################################
# OIL COMPILER CONFIGURATION
#############################################################################
# Goil OIL compiler tool configuration.
# If the GOIL_TEMPLATE_PATH is commented, the default template path is used
# (it can be saved in the .profile file).
GOIL_COMPILER = goil
$GOIL_TEMPLATE_PATH$

# if there is an interrupt generation, the oil file depends on target.cfg
OIL_FILE_DEP = $OIL_FILE_DEP$

#############################################################################
# DOCUMENTATION GENERATION
#############################################################################
# The doxygen tool is used to extract both user and developpment 
# documentation from the source code. 
# See http://www.stack.nl/~dimitri/doxygen/
# You should also install Graphviz dot tool to build dependancy graph in
# the documentation:
# see http://www.graphviz.org/
DOXYGEN = doxygen

#############################################################################
# TARGET SPECIFIC STUFF
#############################################################################

$MAKEFILE_SPEC$

#############################################################################
# call Trampoline makefile rules.
#############################################################################

#call main Trampoline Makefile
OS_MAKE_PATH = $(TPL_BASE_PATH)/make
include $(OS_MAKE_PATH)/Makefile

# vim:ft=make
