//
// Created by josur on 10/06/2025.
//

#ifndef LEVEL_CORE_HPP
#define LEVEL_CORE_HPP

#include "level_utils.hpp"

class Level_wave;
class User_data;

class Level_core {

public:
    int number_of_checkpoints{};
    vector<array<int, 2>> checkpoints_coordinates = {};

    int number_of_turrets{};
    vector<array<int, 2>> turrets_coordinates = {};

    int current_wave_id{0};
    shared_ptr<Level_wave> current_wave_pointer;

    int number_of_enemies{};
    int number_of_waves{};
    int enemies_through{0};
    vector<level_wave_info> waves = {};

    weak_ptr<Level_core> self_pointer;
    weak_ptr<User_data> user_data_ptr;

    enemy_factories_shared_ptrs factories_shared_ptrs{};
    enemy_factories_weak_ptrs factories_weak_ptrs{};
    vector<weak_ptr<Enemy>> enemies_weak_ptrs{};
    vector<shared_ptr<Tower>> tower_shared_ptr{};

    explicit Level_core(const string& level_json_path);
    ~Level_core();
    void generate_pointers(const shared_ptr<Level_core>& self_pointer);
    weak_ptr<Level_wave> instantiate_wave();
    int wave_is_running() const;
};

#endif //LEVEL_CORE_HPP