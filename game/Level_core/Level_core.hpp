//
// Created by josur on 10/06/2025.
//

#ifndef LEVEL_CORE_HPP
#define LEVEL_CORE_HPP

#include "utils.hpp"
#include "game_structs.hpp"

class Level_wave;
class User_data;

class Level_core {

public:
    weak_ptr<Level_core> self_pointer;
    weak_ptr<User_data> user_data_ptr;
    enemy_factories_weak_ptrs factories_weak_ptrs;

    int number_of_checkpoints{};
    vector<array<int, 2>> checkpoints_coordinates = {};

    int number_of_towers{};
    vector<array<int, 2>> towers_coordinates = {};

    int current_wave_id{1};
    weak_ptr<Level_wave> current_wave_pointer;

    int number_of_waves{};
    vector<level_wave_info> waves = {};
    int number_of_enemies{};


    explicit Level_core(const string& level_json_path);
};

#endif //LEVEL_CORE_HPP