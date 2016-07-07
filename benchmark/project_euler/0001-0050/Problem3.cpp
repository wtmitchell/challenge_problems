#include <benchmark/benchmark_api.h>

#include "project_euler/0001-0050/Problem3.h"
using project_euler::Problem3;

void Problem3_Divisor_List(benchmark::State& state) {
  Problem3 p;
  while(state.KeepRunning()) {
    benchmark::DoNotOptimize(p.divisor_list(600851475143ull));
  }
}
BENCHMARK(Problem3_Divisor_List);

