set(BENCH_LINK_COMPONENTS
  project_euler
  )

set(project_euler_sources
  0001-0050/Problem1.cpp
  0001-0050/Problem2.cpp
  0001-0050/Problem3.cpp
  0001-0050/Problem4.cpp
  )

add_benchmark(project_euler_benchmarks
  ${project_euler_sources}
  )
