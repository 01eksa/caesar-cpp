#pragma once

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>

namespace fs = std::filesystem;

inline std::string load(const std::string& path) {
    std::uintmax_t size;
    if (fs::exists(path) && fs::is_regular_file(path)) {
        size = fs::file_size(path);
    } else {
        throw std::invalid_argument("path does not exist");
    }

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("could not open file");
    }

    std::string result;
    result.resize(size);
    file.read(&result[0], size);
    if (file.gcount() != size)
        throw std::runtime_error("could not read file");

    return result;
}
