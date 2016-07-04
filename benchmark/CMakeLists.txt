include(ExternalProject)
find_package(Threads)

# Google Benchmark
ExternalProject_Add(google-benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.0.0
  BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark
  INSTALL_COMMAND "" # Disable install step
  TEST_BEFORE_INSTALL 1
  UPDATE_COMMAND "" # Don't need to update since using tagged release
  CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release
  BUILD_BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/google-benchmark/src/libbenchmark.a
  )

add_library(benchmark STATIC IMPORTED GLOBAL)
add_dependencies(benchmark google-benchmark)

ExternalProject_Get_Property(google-benchmark source_dir binary_dir)
set_property(TARGET benchmark PROPERTY IMPORTED_LOCATION
  ${binary_dir}/src/libbenchmark.a)
set_property(TARGET benchmark PROPERTY IMPORTED_LINK_INTERFACE
  ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET benchmark PROPERTY INTERFACE_INCLUDE_DIRECTORIES
  ${source_dir}/include)

# Workaround for INTERFACE_INCLUDE_DIRECTORIES. The problem is the include
# directory needs to exist at cmake configuration time even though it won't
# exist until the external project is checked out at build time.
file(MAKE_DIRECTORY ${source_dir}/include)

include_directories(SYSTEM ${source_dir}/include)
add_library(benchmarkmain
  main.cpp
  )
add_dependencies(benchmarkmain benchmark)

include_directories(${PROJECT_SOURCE_DIR}/include)


# Function to collect a libraries benchmarks together into a distinct
# executable per library
function(add_benchmark name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name}
    benchmark
    benchmarkmain
    ${CMAKE_THREAD_LIBS_INIT}
    ${BENCH_LINK_COMPONENTS}
    )
endfunction()

# google-benchmark triggers some warnings via macro includes, suppress them
if("${CMAKE_C_COMPILER}" MATCHES "clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-global-constructors")
endif()


#add_subdirectory(number)
add_subdirectory(project_euler)
#add_subdirectory(util)
