cmake_minimum_required(VERSION 3.5)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
endif()

project(tentrix LANGUAGES CXX)

add_subdirectory(tentrix)
add_subdirectory(tentrix_benchmark)
add_subdirectory(tentrix_tests)
add_subdirectory(tentrix_play)
add_subdirectory(tentrix_sandbox)
