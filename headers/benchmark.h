#pragma once

#include <chrono>

#include "caesar.h"

struct bench_settings {
    unsigned warmup = 10;
    unsigned repeat = 100;
    unsigned offset = 3;
};

struct bench_result {
    double total_time;
    double average_time;
};

inline bench_result run_benchmark(const std::string& data, const bench_settings& settings) {
    std::string in_process = data;

    for (unsigned i = 0; i < settings.warmup; i++) {
        caesar::encode(in_process, settings.offset);
        caesar::decode(in_process, settings.offset);
    }

    if (in_process != data) {
        throw std::runtime_error("benchmark is corrupted!");
    }

    const auto start = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < settings.repeat; i++) {
        caesar::encode(in_process, settings.offset);
        caesar::decode(in_process, settings.offset);
    }
    const auto end = std::chrono::high_resolution_clock::now();

    if (in_process != data) {
        throw std::runtime_error("benchmark is corrupted!");
    }

    bench_result result{};
    result.total_time =
        static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 1000;
    result.average_time  = result.total_time / settings.repeat;

    return result;
}
