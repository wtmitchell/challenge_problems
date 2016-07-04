#include <benchmark/benchmark_api.h>

#include "project_euler/0001-0050/Problem1.h"
using project_euler::Problem1;
#include "project_euler/Factory.h"
using project_euler::Factory::create;

void BM_empty(benchmark::State& state) {
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(state.iterations());
  }
}
BENCHMARK(BM_empty);

