#pragma once

#include <chrono>

struct bench_settings {
    unsigned warmup = 10;
    unsigned repeat = 100;
    unsigned offset = 3;
};

struct bench_result {
    double total_time;
    double average_time;
};

bench_result run_benchmark(const std::string& data, const bench_settings& settings);
