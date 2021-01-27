#include <benchmark/benchmark.h>

void mergeSort(int arr[], int left, int right);

void BM_mergeSort(benchmark::State& state) {
  while (state.KeepRunning()){
    state.PauseTiming();

    int arr[] = {};

    state.ResumeTiming();

    mergeSort(arr, 0, 0);
  }
}
BENCHMARK(BM_mergeSort);
BENCHMARK_MAIN();
