#include <benchmark/benchmark_api.h>

#include "project_euler/0001-0050/Problem1.h"
using project_euler::Problem1;

void Problem1_BruteForce(benchmark::State& state) {
  Problem1 p1;
  while(state.KeepRunning()) {
    benchmark::DoNotOptimize(p1.brute_force(1000));
  }
}
BENCHMARK(Problem1_BruteForce);

void Problem1_Analytic(benchmark::State& state) {
  Problem1 p1;
  while(state.KeepRunning()) {
    benchmark::DoNotOptimize(p1.analytic(1000));
  }
}
BENCHMARK(Problem1_Analytic);

