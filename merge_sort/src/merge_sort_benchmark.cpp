#include "merge_sort.h"
#include <benchmark/benchmark.h>

static void BM_MergeSort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
	int num = state.range(0);
	int arr[num];
	for (int i = 0; i < num; ++i) {
        	arr[i] = rand() % 100;
    	}
        state.ResumeTiming();
        MergeSort(arr, 0, state.range(0));
    }
}

BENCHMARK(BM_MergeSort)->RangeMultiplier(10)->Range(10, 10000);
BENCHMARK_MAIN();
