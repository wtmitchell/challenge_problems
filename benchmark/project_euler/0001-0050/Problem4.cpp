#include <benchmark/benchmark.h>

#include "project_euler/0001-0050/Problem4.h"
using project_euler::Problem4;

void Problem4_BruteForce(benchmark::State& state) {
  Problem4 p;
  while(state.KeepRunning()) {
    p.brute_force();
  }
}
BENCHMARK(Problem4_BruteForce);

