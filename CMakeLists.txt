cmake_minimum_required(VERSION 3.27)
project(caesar-benchmark-cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(caesar-cpp main.cpp
)

target_include_directories(caesar-cpp PRIVATE headers)

include(FetchContent)
FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11
        GIT_TAG        v2.6.2
)
FetchContent_MakeAvailable(cli11)
target_link_libraries(caesar-cpp PRIVATE CLI11::CLI11)

target_compile_definitions(caesar-cpp PRIVATE BUILD_TYPE="$<CONFIG>")
