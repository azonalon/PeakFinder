# Install script for directory: /home/eduard/programming/PeakFinder/dep/eo/src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/eduard/programming/PeakFinder/dep/eo/lib/libeo.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eo" TYPE FILE FILES
    "/home/eduard/programming/PeakFinder/dep/eo/src/EO.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/PO.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/apply.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoAlgo.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoBinaryFlight.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoBitParticle.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoBreed.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoCellularEasyEA.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoCloneOps.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoCombinedContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoCombinedInit.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoConstrictedVariableWeightVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoConstrictedVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoCounter.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoCtrlCContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoDetSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoDetTournamentSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoDistribUpdater.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoDistribution.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoDualFitness.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEDA.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEasyEA.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEasyPSO.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalCounterThrowException.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalFunc.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalFuncCounter.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalFuncCounterBounder.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalFuncPtr.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalTimeThrowException.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoEvalUserTimeThrowException.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoExceptions.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoExtendedVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFactory.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFitContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFitnessScalingSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFixedInertiaWeightedVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFlOrBinOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFlOrMonOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFlOrQuadOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFlight.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFunctor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoFunctorStore.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoG3Replacement.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoGaussRealWeightUp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoGenContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoGenOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoGeneralBreeder.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoInit.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoInitializer.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoInt.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoIntegerVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoInvalidateOps.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoLinearDecreasingWeightUp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoLinearFitScaling.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoLinearTopology.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoMGGReplacement.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoMerge.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoMergeReduce.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoNDSorting.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoNeighborhood.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoObject.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoOneToOneBreeder.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoOpContainer.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoOpSelMason.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoOrderXover.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPSO.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoParticleBestInit.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoParticleFullInitializer.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPerf2Worth.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPeriodicContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPersistent.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPop.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPopEvalFunc.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPopulator.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPrintable.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoPropGAGenOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoProportionalCombinedOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoProportionalSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRandomRealWeightUp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRandomSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRankMuSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRanking.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRankingSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRealBoundModifier.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRealParticle.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoReduce.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoReduceMerge.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoReduceMergeReduce.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoReduceSplit.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoReplacement.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoRingTopology.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSGA.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSGAGenOp.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSGATransform.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSIGContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSTLFunctor.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoScalarFitness.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoScalarFitnessAssembled.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSecondsElapsedContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelectFactory.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelectFromWorth.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelectMany.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelectNumber.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelectOne.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSelectPerc.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSequentialSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSharing.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSharingSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoShiftMutation.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSigBinaryFlight.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSimpleEDA.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSocialNeighborhood.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoStandardFlight.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoStandardVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoStarTopology.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSteadyFitContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoStochTournamentSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoStochasticUniversalSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSurviveAndDie.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSwapMutation.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoSyncEasyPSO.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTimeContinue.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTopology.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTransform.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTruncSelect.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTruncatedSelectMany.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTruncatedSelectOne.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoTwoOptMutation.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVariableInertiaWeightedVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVariableLengthCrossover.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVariableLengthMutation.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVector.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVectorParticle.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVelocity.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoVelocityInit.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eoWeightUpdater.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/es.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/ga.h"
    "/home/eduard/programming/PeakFinder/dep/eo/src/eo"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/eduard/programming/PeakFinder/dep/eo/src/do/cmake_install.cmake")
  include("/home/eduard/programming/PeakFinder/dep/eo/src/es/cmake_install.cmake")
  include("/home/eduard/programming/PeakFinder/dep/eo/src/ga/cmake_install.cmake")
  include("/home/eduard/programming/PeakFinder/dep/eo/src/gp/cmake_install.cmake")
  include("/home/eduard/programming/PeakFinder/dep/eo/src/other/cmake_install.cmake")
  include("/home/eduard/programming/PeakFinder/dep/eo/src/utils/cmake_install.cmake")
  include("/home/eduard/programming/PeakFinder/dep/eo/src/serial/cmake_install.cmake")

endif()

