cmake_minimum_required(VERSION 3.20)
project(nqueens-benchmark LANGUAGES CXX)

# ── C++ Standard ─────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)        # Use -std=c++20, not -std=gnu++20

# ── Compiler Warnings ───────────────────────────────────────
add_compile_options(-Wall -Wextra -Wpedantic)

# ── Solver Library ──────────────────────────────────────────
# All solver .cpp files get compiled into a static library.
# Executables link against this instead of recompiling everything.
add_library(solvers
    src/solver.cpp
    src/solvers/brute_force.cpp
    # src/solvers/backtracking.cpp
    # src/solvers/forward_checking.cpp
    # src/solvers/bitwise.cpp
    # src/solvers/min_conflicts.cpp
)

# Tell the compiler where to find our header files.
# PUBLIC means anything that links against 'solvers' also gets this include path.
target_include_directories(solvers PUBLIC ${CMAKE_SOURCE_DIR}/include)

# ── Main Executable ─────────────────────────────────────────
add_executable(nqueens src/main.cpp)
target_link_libraries(nqueens PRIVATE solvers)

# ── External Dependencies (downloaded at configure time) ────
include(FetchContent)

# Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)

# Google Benchmark
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.9.1
)

# Prevent Google Benchmark from building its own tests
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

# Actually download and build them
FetchContent_MakeAvailable(googletest googlebenchmark)

# ── Test Executable ─────────────────────────────────────────
add_executable(nqueens_tests tests/solver_tests.cpp)
target_link_libraries(nqueens_tests PRIVATE solvers GTest::gtest_main)

# Register tests with CTest so 'ctest' command works
include(GoogleTest)
gtest_discover_tests(nqueens_tests)

# ── Benchmark Executable ────────────────────────────────────
add_executable(nqueens_benchmarks benchmarks/solver_bench.cpp)
target_link_libraries(nqueens_benchmarks PRIVATE solvers benchmark::benchmark_main)