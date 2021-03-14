#include <vector>

#include "benchmark/benchmark.h"
#include "vector.h"

static void BM_VectorInt(benchmark::State& state) {
  yylib::vector<int> v(5);
  for (auto _ : state) {
    for (int i = 0; i < 1000; i++) {
      v.push_back(i);
    }
    v.emplace_back(100);
  }
}
BENCHMARK(BM_VectorInt);

static void BM_StdVectorInt(benchmark::State& state) {
  std::vector<int> v(5);
  for (auto _ : state) {
    for (int i = 0; i < 1000; i++) {
      v.push_back(i);
    }
    v.emplace_back(100);
  }
}
BENCHMARK(BM_StdVectorInt);

BENCHMARK_MAIN();
