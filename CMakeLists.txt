cmake_minimum_required(VERSION 3.5)

project(tentrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tentrix
    main.cpp
    structure.h structure.cpp
    print.h print.cpp
    move.h move.cpp)
