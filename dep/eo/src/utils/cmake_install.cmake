# Install script for directory: /home/eduard/programming/PeakFinder/dep/eo/src/utils

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/eduard/programming/PeakFinder/dep/eo/lib/libeoutils.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo/utils" TYPE FILE FILES
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/compatibility.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoAssembledFitnessStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoCheckPoint.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoData.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoDistance.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoFDCStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoFeasibleRatioStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoFileMonitor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoFileSnapshot.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoFuncPtrStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoGenCounter.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoGnuplot.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoGnuplot1DMonitor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoGnuplot1DSnapshot.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoHowMany.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoIntBounds.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoLogger.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoMOFitnessStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoMonitor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoOStreamMonitor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoParallel.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoParam.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoParser.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoPopStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoRNG.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoRealBounds.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoRealVectorBounds.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoRndGenerators.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoScalarFitnessStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoSignal.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoStat.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoState.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoStdoutMonitor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoTimeCounter.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoTimedMonitor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoTimer.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoUniformInit.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoUpdatable.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/eoUpdater.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/pipecom.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/rnd_generators.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/selectors.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/utils/checkpointing"
    )
endif()

