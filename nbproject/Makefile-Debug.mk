#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/VoiceControlWindow.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Laquila2.5/lib `pkg-config --libs gtkmm-3.0` alsa-cpp/dist/Debug/GNU-Linux-x86/libalsa-cpp.so aquila2.5/lib/libaquila.so  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol: alsa-cpp/dist/Debug/GNU-Linux-x86/libalsa-cpp.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol: aquila2.5/lib/libaquila.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/VoiceControlWindow.o: src/VoiceControlWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include `pkg-config --cflags gtkmm-3.0`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VoiceControlWindow.o src/VoiceControlWindow.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include `pkg-config --cflags gtkmm-3.0`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd alsa-cpp && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol

# Subprojects
.clean-subprojects:
	cd alsa-cpp && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
