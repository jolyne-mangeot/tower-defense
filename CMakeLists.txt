cmake_minimum_required(VERSION 3.13)

project(plugin-unity)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(main
        main.cpp
        entities/enemies/Basic_enemy.cpp
)

add_library(plugin-unity SHARED
        test/test.cpp
        entities/enemies/Basic_enemy.cpp
        entities/enemies/Basic_enemy_exposed.cpp
)