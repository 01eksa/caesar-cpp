#pragma once

#include <format>

inline constexpr auto benchmark_version      = "v0.1.0";
inline constexpr auto implementation_version = "v0.2.0";

#define STRINGIFY_IMPL(x) #x
#define STRINGIFY(x)      STRINGIFY_IMPL(x)
#if defined(__clang__)
#define COMPILER "Clang " __clang_version__
#elif defined(__GNUC__)
#define COMPILER "GCC " __VERSION__
#elif defined(_MSC_VER)
#define COMPILER "MSVC " STRINGIFY(_MSC_VER)
#else
#define COMPILER "Unknown compiler"
#endif

inline constexpr auto benchmark_logo = R"(
               ____    _    _____ ____    _    ____
              / ___|  / \  | ____/ ___|  / \  |  _ \
             | |     / _ \ |  _| \___ \ / _ \ | |_) |
             | |___ / ___ \| |___ ___) / ___ \|  _ <
              \____/_/   \_\_____|____/_/   \_\_| \_\

      ____  _____ _   _  ____ _   _ __  __    _    ____  _  __
     | __ )| ____| \ | |/ ___| | | |  \/  |  / \  |  _ \| |/ /
     |  _ \|  _| |  \| | |   | |_| | |\/| | / _ \ | |_) | ' /
     | |_) | |___| |\  | |___|  _  | |  | |/ ___ \|  _ <| . \
     |____/|_____|_| \_|\____|_| |_|_|  |_/_/   \_\_| \_\_|\_\
)";

inline constexpr auto implementation_logo = R"(
 _________                     _______________________
 __  ____/___________     ___________  /__(_)_  /___(_)____________
 _  /    ___/ /___/ /_    _  _ \  __  /__  /_  __/_  /_  __ \_  __ \
 / /___  /_  __/_  __/    /  __/ /_/ / _  / / /_ _  / / /_/ /  / / /
 \____/   /_/   /_/       \___/\__,_/  /_/  \__/ /_/  \____//_/ /_/
)";

inline const auto sys_info = std::format(R"(
  Caesar Benchmark {}
  C++ edition {}
  Compiled with: {} ({}))",
benchmark_version,
implementation_version,
COMPILER,
BUILD_TYPE
);

inline const auto description = std::format(R"({}

  License: GPL v3
  GitHub: https://github.com/01eksa/caesar-cpp

  The benchmark runs in two phases:
    1. Warm-up: runs M cycles to warm up the CPU and load the file into cache.
    2. Measurement: runs N cycles and measures the time.
  Both phases verify that the result matches the original file.

  Average speed is calculated as: file_size / (average_cycle_time / 2)
  Each cycle encodes the file, then decodes it back (2 algorithm runs per cycle).

  Use the same implementation on different hardware to compare hardware performance.
  Use different implementations on the same hardware to compare language performance.
)",
sys_info
);

inline constexpr auto cpu_template = R"(
  CPU: {}
)";

inline constexpr auto configuration_template = R"(
  Configuration
------------------------------------
  File size            {:.2f} {}
  Warm-up cycles       {}
  Bench cycles         {}
  Offset               {}
------------------------------------
)";

inline constexpr auto result_template = R"(
  Result
------------------------------------
  Total time        {:>7.3f} {}
  Average time      {:>7.3f} {}
  Average speed     {:>6.2f}  {}/s
------------------------------------
  Final Score       {:<6}
------------------------------------
)";
