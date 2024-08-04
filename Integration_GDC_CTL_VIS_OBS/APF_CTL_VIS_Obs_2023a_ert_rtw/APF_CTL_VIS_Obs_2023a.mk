###########################################################################
## Makefile generated for component 'APF_CTL_VIS_Obs_2023a'. 
## 
## Makefile     : APF_CTL_VIS_Obs_2023a.mk
## Generated on : Mon Apr 01 10:20:45 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/APF_CTL_VIS_Obs_2023a.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = APF_CTL_VIS_Obs_2023a
MAKEFILE                  = APF_CTL_VIS_Obs_2023a.mk
MATLAB_ROOT               = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2023a
MATLAB_BIN                = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2023a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Projects/Integration_GDC_CTL_VIS_OBS
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU GCC for NVIDIA Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

CCOUTPUTFLAG  = --output_file=
LDOUTPUTFLAG  = --output_file=
XCOMPILERFLAG =  

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm -lstdc++

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU GCC for NVIDIA Embedded Processors Assembler
AS = as

# C Compiler: GNU GCC for NVIDIA Embedded Processors C Compiler
CC = gcc

# Linker: GNU GCC for NVIDIA Embedded Processors Linker
LD = gcc

# C++ Compiler: GNU GCC for NVIDIA Embedded Processors C++ Compiler
CPP = g++

# C++ Linker: GNU GCC for NVIDIA Embedded Processors C++ Linker
CPP_LD = g++

# Archiver: GNU GCC for NVIDIA Embedded Processors Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
ASFLAGS              = -c \
                         \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                         \
                       -O0
CPPFLAGS             = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -fpermissive  \
                         \
                       -O2
CPP_LDFLAGS          = -lrt -pthread -ldl \
                        
CPP_SHAREDLIB_LDFLAGS  = -shared  \
                         -lrt -pthread -ldl \
                          
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -lrt -pthread -ldl \
                        
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE) -j4
SHAREDLIB_LDFLAGS    = -shared  \
                       -lrt -pthread -ldl \
                        



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/APF_CTL_VIS_Obs_2023a.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/include -I$(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Resources/CustomDataLogger/include -I$(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/NVIDIA_Jetson/include -I$(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/include -I$(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Resources/IdentifyPlatform/include -I$(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/dsp/include -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include/src -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include -I$(MATLAB_ROOT)/toolbox/shared/dsp/vision/matlab/include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2023a/toolbox/target/supportpackages/nvidia/include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2023a/toolbox/target/supportpackages/nvidia/sources/utils -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_CAN_BITRATE=500000 -DMW_CAN_ALLOWALLMSGS=1 -DMW_SCHED_OTHER=1
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=APF_CTL_VIS_Obs_2023a -DNUMST=2 -DNCSTATES=6 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_Network.c $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_rtw.c $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Resources/CustomDataLogger/src/custom_data_logger.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/NVIDIA_Jetson/src/gpio_control.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/protocol2_packet_handler.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/protocol1_packet_handler.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_windows.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_mac.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_linux.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_arduino.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/packet_handler.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_sync_write.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_sync_read.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_bulk_write.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_bulk_read.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/dynamixel_functions.cpp $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Resources/IdentifyPlatform/src/resource_functions.cpp $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/APF_CTL_VIS_Obs_2023a.cpp $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/APF_CTL_VIS_Obs_2023a_data.cpp $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/rtGetInf.cpp $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/rtGetNaN.cpp $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/rt_nonfinite.cpp $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2023a/toolbox/target/supportpackages/nvidia/sources/utils/MW_nvidia_init.c $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.cpp $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2023a/toolbox/target/supportpackages/shared_nvidia_blocks/src/linuxUDP.c

MAIN_SRC = $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/ert_main.cpp

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = DAHostLib_Network.c.o DAHostLib_rtw.c.o custom_data_logger.cpp.o gpio_control.cpp.o protocol2_packet_handler.cpp.o protocol1_packet_handler.cpp.o port_handler_windows.cpp.o port_handler_mac.cpp.o port_handler_linux.cpp.o port_handler_arduino.cpp.o port_handler.cpp.o packet_handler.cpp.o group_sync_write.cpp.o group_sync_read.cpp.o group_bulk_write.cpp.o group_bulk_read.cpp.o dynamixel_functions.cpp.o resource_functions.cpp.o APF_CTL_VIS_Obs_2023a.cpp.o APF_CTL_VIS_Obs_2023a_data.cpp.o rtGetInf.cpp.o rtGetNaN.cpp.o rt_nonfinite.cpp.o MW_nvidia_init.c.o linuxinitialize.cpp.o linuxUDP.c.o

MAIN_OBJ = ert_main.cpp.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(LINUX_TARGET_LIBS_MACRO)

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = $(LDFLAGS_CUSTOMLIBFLAGS) -lm -ldl

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL =  -fpermissive
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL =  -fpermissive
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


DAHostLib_Network.c.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_Network.c
	$(CC) $(CFLAGS) -o "$@" "$<"


DAHostLib_rtw.c.o : $(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/src/DAHostLib_rtw.c
	$(CC) $(CFLAGS) -o "$@" "$<"


custom_data_logger.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Resources/CustomDataLogger/src/custom_data_logger.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gpio_control.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/NVIDIA_Jetson/src/gpio_control.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


protocol2_packet_handler.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/protocol2_packet_handler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


protocol1_packet_handler.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/protocol1_packet_handler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


port_handler_windows.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_windows.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


port_handler_mac.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_mac.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


port_handler_linux.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_linux.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


port_handler_arduino.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler_arduino.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


port_handler.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/port_handler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


packet_handler.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/packet_handler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


group_sync_write.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_sync_write.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


group_sync_read.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_sync_read.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


group_bulk_write.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_bulk_write.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


group_bulk_read.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/group_bulk_read.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


dynamixel_functions.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Dynamixel_Actuators/src/dynamixel_functions.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


resource_functions.cpp.o : $(MATLAB_WORKSPACE)/C/Users/SPOT/Documents/SPOT-4.0.0-RC.4_-_APF/Custom_Library/Resources/IdentifyPlatform/src/resource_functions.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ert_main.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/ert_main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


APF_CTL_VIS_Obs_2023a.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/APF_CTL_VIS_Obs_2023a.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


APF_CTL_VIS_Obs_2023a_data.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/APF_CTL_VIS_Obs_2023a_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.cpp.o : $(START_DIR)/APF_CTL_VIS_Obs_2023a_ert_rtw/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_nvidia_init.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2023a/toolbox/target/supportpackages/nvidia/sources/utils/MW_nvidia_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


linuxinitialize.cpp.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linuxUDP.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2023a/toolbox/target/supportpackages/shared_nvidia_blocks/src/linuxUDP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(ECHO) "### Deleted all derived files."


