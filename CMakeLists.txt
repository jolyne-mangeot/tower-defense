cmake_minimum_required(VERSION 3.5.0)
project(13.3 VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(13.3 src/towerFactory.cpp src/Tower.cpp src/crazyTower.cpp src/atomicTower.cpp src/enemy.cpp src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)