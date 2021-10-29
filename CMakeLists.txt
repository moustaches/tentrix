cmake_minimum_required(VERSION 3.5)

project(tentrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(/home/moustache/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(benchmark CONFIG REQUIRED)

add_executable(tentrix
    main.cpp
    structure.h structure.cpp
    print.h print.cpp
    move.h move.cpp
)

add_executable(tentrix_2
    main.cpp
    structure.h structure.cpp
    print.h print.cpp
    move.h move.cpp
)

target_link_libraries(tentrix
    PRIVATE
    benchmark::benchmark
    benchmark::benchmark_main
)

target_link_libraries(tentrix_2
    PRIVATE
    benchmark::benchmark
    benchmark::benchmark_main
)
