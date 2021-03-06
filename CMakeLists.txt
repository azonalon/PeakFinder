CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(PeakFinder)
set(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS "-Wall -Werror -Wno-unused-variable -Wno-overloaded-virtual -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

option(BUILD_EO "Enable building eo dependency" OFF)
if(BUILD_EO)
    add_subdirectory(dep/eo)
endif()

# enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
include_directories(dep/eo/src dep/eigen)
link_directories(dep/eo/lib)
# add_executable(first test/first.cpp test/first)
# target_link_libraries(first cma eoutils eo)
# add_executable(randomSpectra test/randomSpectra.cpp)
# add_executable(localOptimization test/localOptimization.cpp)
# add_executable(randomInitialValues test/randomInitialValues.cpp)
# add_executable(simpleEA test/simpleEA.cpp)
# add_executable(dumpRandomSpectrum test/dumpRandomSpectrum.cpp)
add_executable(Main src/Main.cpp)
# target_link_libraries(simpleEA eoutils eo)
# target_link_libraries(dumpRandomSpectrum eoutils eo)
target_link_libraries(Main eoutils eo)
