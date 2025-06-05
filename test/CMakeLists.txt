cmake_minimum_required(VERSION 3.13)

project(Test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(Test SHARED
        test.cpp)