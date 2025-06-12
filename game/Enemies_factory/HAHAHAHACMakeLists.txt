cmake_minimum_required(VERSION 3.13)

project(Test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# add_library(Test SHARED
#         test_main.cpp
#         ../enemies/enemy.cpp
#         ../enemies/tank.cpp
#         ../enemies/flash.cpp
#         ../enemies/boss.cpp
#         ../movements/straightmovement.cpp
#         ../enemyfactories/enemyfactory.cpp)

# Collect all your source files, e.g.:
file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(TestExecutable
    test_main.cpp
    enemies/enemy.cpp
    enemies/tank.cpp
    enemies/flash.cpp
    enemies/boss.cpp
    movements/upmovement.cpp
    movements/downmovement.cpp
    movements/leftmovement.cpp
    movements/rightmovement.cpp
    enemyfactories/enemyfactory.cpp
)

target_include_directories(TestExecutable PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/enemies
    ${CMAKE_CURRENT_SOURCE_DIR}/enemyfactories
    ${CMAKE_CURRENT_SOURCE_DIR}/movements
)