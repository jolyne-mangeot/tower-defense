cmake_minimum_required(VERSION 3.31)
project(Unity_cpp_backend)

set(CMAKE_CXX_STANDARD 17)

include_directories(game)
include_directories(game/common)
include_directories(game/Enemies_factory)
include_directories(game/Enemies_factory/enemies)
include_directories(game/Enemies_factory/enemyfactories)
include_directories(game/Enemies_factory/movements)
include_directories(game/Level_core)
include_directories(game/Towers_factory)
include_directories(game/Towers_factory/src)

add_executable(Unity_cpp_backend
        game/main.cpp
        game/common/utils.hpp
        game/Level_core/Level_core.cpp
        game/Level_core/Level_core.hpp
        game/levels/level_1.json)
