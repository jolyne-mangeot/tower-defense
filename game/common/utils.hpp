//
// Created by josur on 10/06/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "json.hpp"
#include <fstream>
#include <array>

using namespace std;
using namespace nlohmann;

typedef struct {
    int number_of_enemies;
    int spawn_interval;
    vector<int> spawn_order;
} level_waves;

#if defined(MAIN_CPP) & !defined(MAIN_INCLUDED)
#define MAIN_INCLUDED

#include "Level_core.hpp"

#endif

#if defined(LEVEL_CORE_HPP) & !defined(LEVEL_CORE_INCLUDED)
#define LEVEL_CORE_INCLUDED

#endif

#endif //UTILS_HPP