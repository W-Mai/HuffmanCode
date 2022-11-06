cmake_minimum_required(VERSION 3.10)
project(HuffmanCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HuffmanCode
        HuffmanCode.cpp
        HuffmanCode.h
        Main.cpp)
