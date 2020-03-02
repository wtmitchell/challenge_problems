
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

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Threads)
# Function to collect a libraries benchmarks together into a distinct
# executable per library
function(add_benchmark name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name}
    benchmark::benchmark
    benchmark::benchmark_main
    ${CMAKE_THREAD_LIBS_INIT}
    ${BENCH_LINK_COMPONENTS}
    )
endfunction()

#add_subdirectory(number)
add_subdirectory(project_euler)
#add_subdirectory(util)
