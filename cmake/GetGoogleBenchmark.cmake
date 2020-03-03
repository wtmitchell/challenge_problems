# -*- cmake -*-

#[=======================================================================[.rst:
GetGoogleBenchmark
-------

Downloads and configures Google Benchmark library using the FetchContent CMake module

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``benchmark::benchmark``
  The Benchmark library
``benchmark::benchmark_main``
  The main entry point for running benchmarks

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``benchmark_POPULATED``
  True if Googletest has been downloaded and configured

#]=======================================================================]

include(GetGoogletest)

# Google benchmark setup
include(FetchContent)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG master
  )

FetchContent_GetProperties(benchmark)
string(TOLOWER "benchmark" lcName)
if(NOT ${lcName}_POPULATED)
   set(BENCHMARK_ENABLE_TESTING OFF
      CACHE BOOL "Enable testing of the benchmark library."
      FORCE)
  set(BENCHMARK_ENABLE_GTEST_TESTS OFF
      CACHE BOOL "Enable building the unit tests which depend on gtest"
      FORCE)
  FetchContent_Populate(benchmark)
  add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR})
endif()
