//
// Created by josur on 10/06/2025.
//

#ifndef LEVEL_CORE_HPP
#define LEVEL_CORE_HPP

#include "utils.hpp"
#include "game_structs.hpp"
// #include "tower.h"

class Level_wave;
class User_data;

class Level_core {

public:
    int number_of_checkpoints{};
    shared_ptr<vector<array<int, 2>>> checkpoints_coordinates;

    int number_of_turrets{};
    vector<array<int, 2>> turrets_coordinates = {};

    int current_wave_id{0};
    weak_ptr<Level_wave> current_wave_pointer;

    int number_of_enemies{};
    int number_of_waves{};
    int enemies_through{0};
    vector<level_wave_info> waves = {};

    weak_ptr<Level_core> self_pointer;
    weak_ptr<User_data> user_data_ptr;

    enemy_factories_weak_ptrs factories_weak_ptrs{};
    vector<weak_ptr<Enemy>> enemies_weak_ptrs{};

    explicit Level_core(const string& level_json_path);

    ~Level_core() {
        checkpoints_coordinates.reset();
    }
};

#endif //LEVEL_CORE_HPP