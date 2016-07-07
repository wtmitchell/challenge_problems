#include <benchmark/benchmark_api.h>

#include "project_euler/0001-0050/Problem2.h"
using project_euler::Problem2;

void Problem2_BruteForce(benchmark::State& state) {
  Problem2 p;
  while(state.KeepRunning()) {
    benchmark::DoNotOptimize(p.brute_force(4000000));
  }
}
BENCHMARK(Problem2_BruteForce);

void Problem2_Evens_Only(benchmark::State& state) {
  Problem2 p;
  while(state.KeepRunning()) {
    benchmark::DoNotOptimize(p.evens_only(4000000));
  }
}
BENCHMARK(Problem2_Evens_Only);

