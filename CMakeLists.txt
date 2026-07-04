cmake_minimum_required(VERSION 3.27)
project(caesar-benchmark-cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(caesar-cpp src/main.cpp
        src/benchmark.cpp
        src/caesar.cpp
        src/loader.cpp
)

target_include_directories(caesar-cpp PRIVATE include)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_EXECUTABLE OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11
        GIT_TAG        v2.6.2
)
FetchContent_Declare(
        google_cpu_features
        GIT_REPOSITORY https://github.com/google/cpu_features
        GIT_TAG        v0.11.0
)
FetchContent_MakeAvailable(cli11 google_cpu_features)
target_link_libraries(caesar-cpp PRIVATE CLI11::CLI11)
target_link_libraries(caesar-cpp PRIVATE CpuFeatures::cpu_features)
target_compile_definitions(caesar-cpp PRIVATE BUILD_TYPE="$<CONFIG>")
