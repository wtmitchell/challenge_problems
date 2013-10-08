cmake_minimum_required(VERSION 2.8)
project(PROJECT_EULER)

set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 1)

# Set up the compiler flags used
if(CMAKE_COMPILER_IS_GNUCXX)
  # gcc flags
  set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wconversion -Wfloat-equal -Wredundant-decls -Wshadow -Wwrite-strings -Wno-long-long")

  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3")
else()
  if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # clang flags
    set(CMAKE_CXX_FLAGS "-std=c++11 -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded")

    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
  else()
    # Generic flags
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
  endif()
endif()

# Add path for custom modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

enable_testing()

# We require the GNU Multi-Precision library
find_package(GMP)

if (!GMP_FOUND)
  message(FATAL_ERROR "GMP not found.")
endif()

add_subdirectory(apps)
add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(util)

# Documentation must be explicitly requested
add_subdirectory(docs EXCLUDE_FROM_ALL)

# Target for checking format via clang-format
file(GLOB_RECURSE files apps/*/*.cpp include/*/*.h lib/*/*.cpp test/*.h test/*/*.cpp test/*/*.h)
add_custom_command(OUTPUT formatcheck COMMAND
  ${CMAKE_CURRENT_SOURCE_DIR}/tools/check_format.sh ${files})
add_custom_target(check-format DEPENDS formatcheck)
