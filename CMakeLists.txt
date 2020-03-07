cmake_minimum_required(VERSION 3.16)
project(Challenge_Problems
  VERSION 0.1
  HOMEPAGE_URL https://github.com/wtmitchell/challenge_problems
  LANGUAGES CXX
  )

# Add path for custom modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )


# Compiler Flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(DefaultBuildType)
include(CompilerSetup)
colorize_output()

# Build options
option(USE_LIBCXX "Use libc++ when using Clang" OFF)
option(USE_VALGRIND_MEMCHECK "Add copies of unit tests with Valgrind's memcheck to run unit tests" ON)
option(USE_SANITIZER_ADDRESS "Uses AddressSanitizer" OFF)
option(USE_SANITIZER_LEAK "Uses LeakSanitizer" OFF)
option(USE_SANITIZER_MEMORY "Uses MemorySanitizer" OFF)
option(USE_SANITIZER_THREAD "Uses ThreadSanitizer" OFF)
option(USE_SANITIZER_UNDEFINED "Uses UndefinedBehaviorSanitizer" OFF)
option(USE_INCLUDE_WHAT_YOU_USE "Uses Include What You Use" ON)

# Valgrind setup
if (USE_VALGRIND_MEMCHECK)
  find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
  set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")
  if (CTEST_MEMORYCHECK_COMMAND-NOTFOUND)
    message(WARNING "Cannot find valgrind. Disabling USE_VALGRIND_MEMCHECK")
    set(USE_VALGRIND_MEMCHECK OFF)
  endif()
endif()

# Ensure at most one sanitizer is enabled
if ((USE_SANITIZER_ADDRESS AND USE_SANITIZER_MEMORY)
    OR (USE_SANITIZER_ADDRESS AND USE_SANITIZER_LEAK)
    OR (USE_SANITIZER_ADDRESS AND USE_SANITIZER_THREAD)
    OR (USE_SANITIZER_ADDRESS AND USE_SANITIZER_UNDEFINED)
    OR (USE_SANITIZER_LEAK AND USE_SANITIZER_MEMORY)
    OR (USE_SANITIZER_LEAK AND USE_SANITIZER_THREAD)
    OR (USE_SANITIZER_LEAK AND USE_SANITIZER_UNDEFINED)
    OR (USE_SANITIZER_MEMORY AND USE_SANITIZER_THREAD)
    OR (USE_SANITIZER_MEMORY AND USE_SANITIZER_UNDEFINED)
    OR (USE_SANITIZER_THREAD AND USE_SANITIZER_UNDEFINED))
  message(FATAL_ERROR "Can only use one sanitizer at a time")
endif()

# If using a Sanitizer, disable Valgrind tests since they will conflict
if (USE_SANITIZER_ADDRESS OR USE_SANITIZER_LEAK OR USE_SANITIZER_MEMORY
    OR USE_SANITIZER_THREAD OR USE_SANITIZER_UNDEFINED)
  set(USE_VALGRIND_MEMCHECK OFF)
endif()

# Can only use Include What You Use if using Make or Ninja
if (USE_INCLUDE_WHAT_YOU_USE AND NOT "${CMAKE_GENERATOR}" MATCHES "Make|Ninja")
  message(FATAL_ERROR "Can only use Include-What-You-Use with Make or Ninja")
endif()

# Set up the compiler flags used
if(CMAKE_COMPILER_IS_GNUCXX)
  # gcc
  if (USE_SANITIZER_ADDRESS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  endif ()

  if (USE_SANITIZER_LEAK)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
  endif ()

  if (USE_SANITIZER_THREAD)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
  endif ()

  if (USE_SANITIZER_UNDEFINED)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
  endif ()

else()
  if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # clang
    if (USE_LIBCXX)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif()

    if (USE_SANITIZER_ADDRESS)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    endif ()

    if (USE_SANITIZER_MEMORY)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")
    endif ()

    if (USE_SANITIZER_THREAD)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
    endif ()

    if (USE_SANITIZER_UNDEFINED)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
    endif ()
  endif()
endif()



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

enable_testing()

# We require the GNU Multi-Precision library
find_package(GMP REQUIRED)

add_subdirectory(apps)
add_subdirectory(benchmark)
add_subdirectory(lib)
add_subdirectory(test)

# Documentation must be explicitly requested
add_subdirectory(docs EXCLUDE_FROM_ALL)

# Have Ninja export the compile commands for various clang tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include-what-you-use
if(USE_INCLUDE_WHAT_YOU_USE)
  find_program(INCLUDE_WHAT_YOU_USE include-what-you-use)
  if(INCLUDE_WHAT_YOU_USE)
    message(STATUS "Enable Include What You Use")
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE include-what-you-use)
  else()
    message(WARNING "Could not find include-what-you-use")
  endif()
endif()

# clang-format stuff
file(GLOB_RECURSE format_files apps/*.cpp include/*.h lib/*.cpp test/*.h test/*.cpp)

set(format_list)
set(format_count 0)
foreach(i ${format_files})
  add_custom_target(__format${format_count}
    COMMAND clang-format -style=file ${i} | diff -u ${i} -
    )
  list(APPEND format_list __format${format_count})
  math(EXPR format_count "${format_count} + 1")
endforeach()
add_custom_target(clang-format DEPENDS ${format_list})

# clang-tidy stuff

file(GLOB_RECURSE tidy_files apps/*.cpp lib/*.cpp test/*.cpp)

set(tidy_list)
set(tidy_count 0)
foreach(i ${tidy_files})
  add_custom_target(__tidy${tidy_count}
    COMMAND clang-tidy -header-filter='.*' -p=${PROJECT_BINARY_DIR} ${i}
    )
  list(APPEND tidy_list __tidy${tidy_count})
  math(EXPR tidy_count "${tidy_count} + 1")
endforeach()
add_custom_target(clang-tidy DEPENDS ${tidy_list})
