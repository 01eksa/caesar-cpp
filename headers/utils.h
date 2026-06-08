#pragma once

#include <array>
#include <string>

inline std::pair<double, std::string> convert_bytes(double bytes) {
    std::array<const char*, 6>  units = {"B", "KiB", "MiB", "GiB", "TiB", "PiB"};

    int index = 0;
    while (bytes >= 1024 && index <  units.size() - 1) {
        bytes /= 1024;
        index++;
    }

    return {bytes,  units[index]};
}

inline double calc_average_speed(const double average_time, const double file_size) {
    return file_size / (average_time / 1000) * 2;
}

inline std::pair<double, std::string> convert_time(const double ms) {
    std::array k_and_units = {
        std::pair<int, std::string>{1000, "ms"},
        std::pair<int, std::string>{60, "s"},
        std::pair<int, std::string>{60, "m"},
        std::pair<int, std::string>{60, "h"},
        std::pair<int, std::string>{24, "d"},
    };

    int index = 0;
    double time = ms;
    while (index < k_and_units.size() - 1 && time >= k_and_units[index].first) {
        time /= k_and_units[index].first;
        index++;
    }

    return {time, k_and_units[index].second};
}
