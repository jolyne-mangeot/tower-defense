cmake_minimum_required(VERSION 3.13)

project(Test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include_directories(game/common)
include_directories(game/Enemies_factory)
include_directories(game/Enemies_factory/enemies)
include_directories(game/Enemies_factory/enemyfactories)
include_directories(game/Enemies_factory/movements)
include_directories(game/Level_core)
include_directories(game/Lever_wave)
include_directories(game/Pointer_manager)
include_directories(game/Towers_factory)
include_directories(game/User_data)

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

add_executable(FloExecutable
    game/Towers_factory/main.cpp
    game/Enemies_factory/enemies/enemy.cpp
    game/Enemies_factory/enemies/boss.cpp
    game/Enemies_factory/enemies/tank.cpp
    game/Enemies_factory/enemies/flash.cpp
    game/Enemies_factory/enemyfactories/bossfactory.cpp
    game/Enemies_factory/enemyfactories/enemyfactory.cpp
    game/Enemies_factory/enemyfactories/flashfactory.cpp
    game/Enemies_factory/enemyfactories/tankfactory.cpp
    game/Enemies_factory/movements/upmovement.cpp
    game/Enemies_factory/movements/downmovement.cpp
    game/Enemies_factory/movements/leftmovement.cpp
    game/Enemies_factory/movements/rightmovement.cpp
    game/Towers_factory/atomicTower.cpp
    game/Towers_factory/crazyTower.cpp 
    game/Towers_factory/towerFactory.cpp 
    game/Towers_factory/tower.cpp 
    game/Towers_factory/basicTower.cpp 
)

# target_include_directories(FloExecutable PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/game/enemies
#     ${CMAKE_CURRENT_SOURCE_DIR}/game/enemyfactories
#     ${CMAKE_CURRENT_SOURCE_DIR}/game/movements
# )