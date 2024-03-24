cmake_minimum_required(VERSION 3.27)
project(producer)

set(CMAKE_CXX_STANDARD 17)

add_executable(producer main.cpp
        readwrite.cpp)
