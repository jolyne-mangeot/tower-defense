//
// Created by josur on 10/06/2025.
//

#ifndef LEVEL_CORE_HPP
#define LEVEL_CORE_HPP

#include "utils.hpp"

class Level_core {

public:
    int number_of_checkpoints{};
    vector<array<int, 2>> checkpoints_coordinates = {};

    int number_of_turrets{};
    vector<array<int, 2>> turrets_coordinates = {};

    int number_of_enemies{};
    int number_of_waves{};
    vector<level_waves> waves = {};

    explicit Level_core(const string& level_json_path);
};

#endif //LEVEL_CORE_HPP


