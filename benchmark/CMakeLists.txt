
include(GetGoogleBenchmark)

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
  enable_warnings_for(${name})

  # Google Benchmark's headers trigger some warnings we don't care about
  if("${CMAKE_CXX_COMPILER_ID}}" MATCHES "Clang")
    target_compile_options(${name} PRIVATE -Wno-global-constructors)
    target_compile_options(${name} PRIVATE -Wno-missing-prototypes)
    target_compile_options(${name} PRIVATE -Wno-used-but-marked-unused)
    target_compile_options(${name} PRIVATE -Wno-weak-vtables)
  endif()
endfunction()

#add_subdirectory(number)
add_subdirectory(project_euler)
#add_subdirectory(util)
