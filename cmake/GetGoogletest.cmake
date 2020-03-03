# -*- cmake -*-

#[=======================================================================[.rst:
GetGoogletest
-------

Downloads and configures Googletest library using the FetchContent CMake module

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``gtest``
  The Googletest library
``gtest_main``
  The main entry point for running tests

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``googletest_POPULATED``
  True if Googletest has been downloaded and configured

#]=======================================================================]


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)

FetchContent_GetProperties(googletest)
string(TOLOWER "googletest" lcName)
if(NOT ${lcName}_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR})
endif()
