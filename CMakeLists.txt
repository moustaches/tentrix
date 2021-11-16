cmake_minimum_required(VERSION 3.5)

project(tentrix LANGUAGES CXX)

#include(/home/moustache/vcpkg/scripts/buildsystems/vcpkg.cmake)

add_subdirectory(tentrix)
add_subdirectory(tentrix_benchmark)
add_subdirectory(tentrix_tests)
add_subdirectory(tentrix_play)
