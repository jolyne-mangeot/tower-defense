cmake_minimum_required(VERSION 3.13)

project(plugin-unity)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(main
        main.cpp
        Basic_enemy.cpp
)

add_library(plugin-unity SHARED
        Basic_enemy.cpp
        Basic_enemy_exposed.cpp
)

#install(TARGETS plugin-unity DESTINATION Tower-Defense/Assets/Plugins/x86_64)