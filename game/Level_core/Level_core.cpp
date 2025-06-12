//
// Created by josur on 10/06/2025.
//

#include "Level_core.hpp"

#include "tower.h"

Level_core::Level_core(const string &level_json_path) {

    ifstream level_json_file(level_json_path);

    basic_json<> level_data = json::parse(level_json_file);

    this->number_of_checkpoints = level_data.at("number_of_checkpoints");
    this->number_of_turrets = level_data.at("number_of_turrets");
    this->number_of_enemies = level_data.at("number_of_enemies");
    this->number_of_waves = level_data.at("number_of_waves");

    this->checkpoints_coordinates.reserve(number_of_checkpoints);
    this->turrets_coordinates.reserve(number_of_turrets);
    this->waves.reserve(number_of_waves);

    for (int i = 0; i < number_of_checkpoints; i++) {
        basic_json<> checkpoint_coordinates = level_data.at("checkpoints_coordinates").at(to_string(i));
        array<int, 2> coordinates = {checkpoint_coordinates.at("x"), checkpoint_coordinates.at("z")};
        this->checkpoints_coordinates.push_back(coordinates);
    }

    for (int i = 0; i < number_of_turrets; i++) {
        basic_json<> turret_coordinates = level_data.at("turrets_coordinates").at(to_string(i));
        array<int, 2> coordinates = {turret_coordinates.at("x"), turret_coordinates.at("z")};
        this->turrets_coordinates.push_back(coordinates);
    }

    for (int i = 0; i < number_of_waves; i++) {
        basic_json<> wave_data = level_data.at("wave_" + to_string(i + 1));

        level_wave_info wave;

        wave.number_of_enemies = wave_data.at("spawn_amount");
        wave.spawn_interval = wave_data.at("spawn_interval");
        wave.spawn_order.reserve(wave.number_of_enemies);

        for (int j = 0; j < wave.number_of_enemies; j++) {
            wave.spawn_order.push_back(wave_data.at("spawn_order").at(to_string(j + 1)));
        }
        this->waves.push_back(wave);
    }
}

void Level_core::generate_pointers(const shared_ptr<Level_core>& self_pointer) {

    int factories_x = checkpoints_coordinates.at(0).at(0);
    int factories_y = checkpoints_coordinates.at(0).at(1);

    this->factories_shared_ptrs = {
        make_shared<EnemyFactory>(factories_x, factories_y),
        make_shared<FlashFactory>(factories_x, factories_y),
        make_shared<TankFactory>(factories_x, factories_y),
        make_shared<BossFactory>(factories_x, factories_y)
    };

    for (shared_ptr<EnemyFactory> instantiated_factory : this->factories_shared_ptrs) {
        instantiated_factory->set_level_ptr(this->self_pointer);
    }

    this->factories_weak_ptrs = {
        factories_shared_ptrs.basic_enemy_factory,
        factories_shared_ptrs.flash_enemy_factory,
        factories_shared_ptrs.tank_enemy_factory,
        factories_shared_ptrs.boss_factory
    };

    tower_shared_ptr.reserve(this->number_of_turrets);
    for (int i = 0; i < this->number_of_turrets; i++) {
        shared_ptr<Tower> tower_ptr = make_shared<Tower>(this->turrets_coordinates.at(i));
        tower_shared_ptr.push_back(tower_ptr);
    }
}

void Level_core::update_enemies_through() {
    enemies_through++;
    if (enemies_through >= 3) {
        current_wave_pointer->~Level_wave();
    }
}


int Level_core::wave_is_running() const {
    if (this->current_wave_pointer->wave_is_running()) {
        return 1;
    } else {
        return 0;
    }
}

weak_ptr<Level_wave> Level_core::instantiate_wave() {
    if (this->current_wave_id > 1) {
        this->current_wave_pointer->~Level_wave();
        this->current_wave_pointer.reset();
    }
    this->current_wave_pointer = make_shared<Level_wave>(
        this->waves.at(current_wave_id - 1),
        this->self_pointer,
        this->user_data_ptr,
        this->factories_weak_ptrs
        );
    return current_wave_pointer;
}

Level_core::~Level_core() {
    this->current_wave_pointer.reset();

    this->factories_shared_ptrs.basic_enemy_factory.reset();
    this->factories_shared_ptrs.flash_enemy_factory.reset();
    this->factories_shared_ptrs.tank_enemy_factory.reset();
    this->factories_shared_ptrs.boss_factory.reset();

    for (shared_ptr<Tower> tower_ptr : tower_shared_ptr) {
        tower_shared_ptr.reset();
    }
}