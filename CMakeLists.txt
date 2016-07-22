cmake_minimum_required(VERSION 3.3)
project(PROJECT_EULER)

set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 1)

# Settings
set(GCC_WARNINGS "-Wall -Wextra -Wpedantic -Wunused -Wformat=2 -Wswitch-enum -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wcast-align -Wcast-qual -Wconversion -Wsign-conversion -Wzero-as-null-pointer-constant -Wlogical-op -Wmissing-declarations -Wctor-dtor-privacy -Wnoexcept -Wnon-virtual-dtor -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wredundant-decls -Wshadow -Wwrite-strings -Wno-long-long")
set(CLANG_WARNINGS "-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-documentation-unknown-command")
set(CXX_VERSION "-std=c++14")

option(USE_LIBCXX "Use libc++ when using Clang" OFF)
option(USE_VALGRIND_MEMCHECK "Add copies of unit tests with Valgrind's memcheck to run unit tests" ON)

# Valgrind setup
find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

# Set up the compiler flags used
if(CMAKE_COMPILER_IS_GNUCXX)
  # gcc flags
  set(CMAKE_CXX_FLAGS "${CXX_VERSION} ${GCC_WARNINGS}")

  if (CMAKE_GENERATOR STREQUAL "Ninja")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
  endif (CMAKE_GENERATOR STREQUAL "Ninja")

  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3")
else()
  if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # clang flags
    set(CMAKE_CXX_FLAGS "${CXX_VERSION} ${CLANG_WARNINGS}")

    if (CMAKE_GENERATOR STREQUAL "Ninja")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")
    endif (CMAKE_GENERATOR STREQUAL "Ninja")

    if (USE_LIBCXX)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif()

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
add_subdirectory(benchmark)
add_subdirectory(lib)
add_subdirectory(test)

# Documentation must be explicitly requested
add_subdirectory(docs EXCLUDE_FROM_ALL)

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
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
