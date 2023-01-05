find_package(benchmark CONFIG REQUIRED)

add_executable(tentrix_benchmark
    compute_bits.cpp
    compute_move.cpp
)

set_target_properties(tentrix_benchmark
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(tentrix_benchmark
    tentrix
    benchmark::benchmark
    benchmark::benchmark_main
)
