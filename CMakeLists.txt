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
include_directories(game/Level_wave)
include_directories(game/User_data)
include_directories(game/Towers_factory)
include_directories(game/Towers_factory/src)

add_executable(Unity_cpp_backend
        game/main.cpp
        game/common/utils.hpp
        game/Level_core/Level_core.cpp
        game/Level_core/Level_core.hpp
        game/Level_wave/Level_wave.cpp
        game/Level_wave/Level_wave.hpp
        game/common/level_utils.hpp
        game/User_data/User_data.cpp
        game/User_data/User_data.hpp)
