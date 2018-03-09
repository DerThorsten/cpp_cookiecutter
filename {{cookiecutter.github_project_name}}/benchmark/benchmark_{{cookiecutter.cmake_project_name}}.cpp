#include <benchmark/benchmark.h>

#include <string>


static void BM_SomeBenchmark(benchmark::State& state)
{


    while (state.KeepRunning())
    {
        std::string empty_string;
    }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeBenchmark);