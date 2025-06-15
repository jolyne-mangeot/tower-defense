cmake_minimum_required(VERSION 3.31)
project(Plugin_unity)

set(CMAKE_CXX_STANDARD 14)

include_directories(game/common)

include_directories(game/Entities)
include_directories(game/Entities/enemies)
include_directories(game/Entities/enemyfactories)
include_directories(game/Entities/movements)
include_directories(game/Entities/towers)

include_directories(game/Level_core)
include_directories(game/Level_wave)
include_directories(game/Pointer_manager)
include_directories(game/User_data)

add_library(Plugin_unity SHARED
        game/dll_Exposed_functions/Pointer_manager_exposed.cpp
        game/dll_Exposed_functions/User_data_exposed.cpp
        game/dll_Exposed_functions/Enemy_exposed.cpp
        game/dll_Exposed_functions/Tower_exposed.cpp
        game/dll_Exposed_functions/Wave_exposed.cpp

        game/Pointer_manager/Pointer_manager.cpp
        game/Level_core/Level_core.cpp
        game/Level_wave/Level_wave.cpp
        game/User_data/User_data.cpp

        game/Entities/towers/tower.cpp

        game/Entities/enemies/boss.cpp
        game/Entities/enemies/enemy.cpp
        game/Entities/enemies/flash.cpp
        game/Entities/enemies/tank.cpp

        game/Entities/movements/downmovement.cpp
        game/Entities/movements/leftmovement.cpp
        game/Entities/movements/rightmovement.cpp
        game/Entities/movements/upmovement.cpp
)
