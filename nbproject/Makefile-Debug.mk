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
	${OBJECTDIR}/src/Letter.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/Pattern.o \
	${OBJECTDIR}/src/Recognizer.o \
	${OBJECTDIR}/src/Phoneme.o \
	${OBJECTDIR}/src/Phonemes.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=gnu++0x -fopenmp -mtune=native -D_GLIBCXX_PARALLEL
CXXFLAGS=-std=gnu++0x -fopenmp -mtune=native -D_GLIBCXX_PARALLEL

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-LSSN/LibHelper/dist/Debug/GNU-Linux-x86 `pkg-config --libs gtkmm-3.0` alsa-cpp/dist/Debug/GNU-Linux-x86/libalsa-cpp.so SSN/LibHelper/dist/Debug/GNU-Linux-x86/libHelper.so `pkg-config --libs fftw3`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol: alsa-cpp/dist/Debug/GNU-Linux-x86/libalsa-cpp.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol: SSN/LibHelper/dist/Debug/GNU-Linux-x86/libHelper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/VoiceControlWindow.o: src/VoiceControlWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/VoiceControlWindow.o src/VoiceControlWindow.cpp

${OBJECTDIR}/src/Letter.o: src/Letter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Letter.o src/Letter.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Pattern.o: src/Pattern.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Pattern.o src/Pattern.cpp

${OBJECTDIR}/src/Recognizer.o: src/Recognizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Recognizer.o src/Recognizer.cpp

${OBJECTDIR}/src/Phoneme.o: src/Phoneme.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Phoneme.o src/Phoneme.cpp

${OBJECTDIR}/src/Phonemes.o: src/Phonemes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Ialsa-cpp/include -Iaquila2.5/include -ISSN/NeuralNetwork -ISSN/Neuron -ISSN/LibHelper `pkg-config --cflags gtkmm-3.0` `pkg-config --cflags fftw3`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Phonemes.o src/Phonemes.cpp

# Subprojects
.build-subprojects:
	cd alsa-cpp && ${MAKE}  -f Makefile CONF=Debug
	cd SSN/NeuralNetwork && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voicecontrol

# Subprojects
.clean-subprojects:
	cd alsa-cpp && ${MAKE}  -f Makefile CONF=Debug clean
	cd SSN/NeuralNetwork && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
