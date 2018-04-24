# Install script for directory: /home/eduard/programming/PeakFinder/dep/eo/src/do

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo/do" TYPE FILE FILES
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_algo_easea.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_algo_scalar.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_checkpoint.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_checkpoint_FDC.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_checkpoint_assembled.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_continue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_general_replacement.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_pop.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/do/make_run.h"
    )
endif()

