# Googletest setup
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
