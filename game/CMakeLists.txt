cmake_minimum_required(VERSION 3.31)
project(Plugin_unity)

set(CMAKE_CXX_STANDARD 14)

include_directories(common)

include_directories(Entities)
include_directories(Entities/enemies)
include_directories(Entities/enemyfactories)
include_directories(Entities/movements)
include_directories(Entities/towers)

include_directories(Level_core)
include_directories(Level_wave)
include_directories(Pointer_manager)
include_directories(User_data)

add_library(Plugin_unity SHARED
        dll_Exposed_functions/Pointer_manager_exposed.cpp
        dll_Exposed_functions/User_data_exposed.cpp
        dll_Exposed_functions/Enemy_exposed.cpp
        dll_Exposed_functions/Tower_exposed.cpp
        dll_Exposed_functions/Wave_exposed.cpp

        Pointer_manager/Pointer_manager.cpp
        Level_core/Level_core.cpp
        Level_wave/Level_wave.cpp
        User_data/User_data.cpp

        Entities/towers/tower.cpp

        Entities/enemies/boss.cpp
        Entities/enemies/enemy.cpp
        Entities/enemies/flash.cpp
        Entities/enemies/tank.cpp

        Entities/movements/downmovement.cpp
        Entities/movements/leftmovement.cpp
        Entities/movements/rightmovement.cpp
        Entities/movements/upmovement.cpp
)
