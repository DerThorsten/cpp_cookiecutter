#include <benchmark/benchmark.h>

#include <string>
#include <vector>

// our headers
#include "{{cookiecutter.cpp_root_folder_name}}/{{ cookiecutter.package_name}}.hpp"


static void BM_SomeBenchmark(benchmark::State& state)
{


    while (state.KeepRunning())
    {
        std::string empty_string;
    }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeBenchmark);





static void BM_SomeBenchmark2(benchmark::State& state)
{
    std::size_t s = state.range(0);

    while (state.KeepRunning())
    {
        benchmark::DoNotOptimize(
            std::vector<int>(s)
        );
    }
}
// Register the function as a benchmark
// Now arguments generated are [ 8, 16, 32, 64, 128, 256, 512, 1024, 2k, 4k, 8k ].
BENCHMARK(BM_SomeBenchmark2)->RangeMultiplier(2)->Range(8, 8<<12);