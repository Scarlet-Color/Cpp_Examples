cmake_minimum_required(VERSION 3.27)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_library(untitled3 STATIC library.cpp
        binary.cpp
        extinct.cpp
        side.cpp
        cmake-build-debug/lowest.cpp)
