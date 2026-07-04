#include <iostream>

#include "CLI/CLI.hpp"
#include "benchmark.h"
#include "config.h"
#include "loader.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    CLI::App app{description};

    {
        auto formatter = app.get_formatter();
        formatter->description_paragraph_width(120);
        formatter->column_width(40);
    }

    std::string    file_path;
    bench_settings settings{};
    bool           show_logo;

    // clang-format off
    app.add_option("file_path", file_path, "Path to the file used in the benchmark")
        ->required()
        ->check(CLI::ExistingFile);
    app.add_option("-w,--warmup", settings.warmup, "Warm-up cycles")
        ->capture_default_str();
    app.add_option("-r,--repeat", settings.repeat, "Benchmark cycles")
        ->capture_default_str();
    app.add_option("-o,--offset", settings.offset, "Offset in Caesar cipher")
        ->capture_default_str();
    app.add_flag("-l,--logo", show_logo, "Show logo");
    // clang-format on

    CLI11_PARSE(app, argc, argv);

    if (show_logo)
        std::cout << std::format("{}\n{}\n", benchmark_logo, implementation_logo) << std::endl;

    try {
        const auto data = load(file_path);

        auto [size, size_unit] = convert_bytes(data.size());
        std::cout << sys_info << std::format(cpu_template, get_processor()) << std::endl;

        std::cout << std::format(
            configuration_template,
            size,
            size_unit,
            settings.warmup,
            settings.repeat,
            settings.offset
        ) << std::endl;

        auto result = run_benchmark(data, settings);

        auto [total_time, total_time_unit]     = convert_time(result.total_time);
        auto [average_time, average_time_unit] = convert_time(result.average_time);
        auto [speed, speed_unit] =
            convert_bytes(calc_average_speed(result.average_time, data.size()));
        auto score = static_cast<int>(speed * 4);

        std::cout << std::format(
            result_template,
            total_time,
            total_time_unit,
            average_time,
            average_time_unit,
            speed,
            speed_unit,
            score
        ) << std::endl;

    } catch (std::exception& e) {
        std::cerr << '\n' << e.what() << std::endl;
        return 1;
    }

    return 0;
}
