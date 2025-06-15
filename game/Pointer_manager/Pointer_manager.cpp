//
// Created by Anwender on 12/06/2025.
//

#include "Pointer_manager.hpp"

void Pointer_manager::instantiate_level_core(const char* json_path) {
    this->level_core_ptr = make_shared<Level_core>(json_path);
    cout << "Level_core class instantiated" << endl;

    const weak_ptr<Level_core> level_weak_ptr = this->level_core_ptr;
    this->level_core_ptr->self_pointer = level_weak_ptr;
}

void Pointer_manager::instantiate_user_data() {
    this->user_data_ptr = make_shared<User_data>();

    const weak_ptr<Level_core> level_weak_ptr = this->level_core_ptr;

    const weak_ptr<User_data> user_weak_ptr = this->user_data_ptr;
    this->level_core_ptr->user_data_ptr = user_weak_ptr;
}

void Pointer_manager::instantiate_level_wave() {
    cout << "Current level wave " << this->level_core_ptr->current_wave_id << endl;

    this->current_wave_ptr = make_shared<Level_wave>(
        this->level_core_ptr->waves.at(this->level_core_ptr->current_wave_id - 1),
        this->user_data_ptr,
        this->level_core_ptr->factories_weak_ptrs,
        this->level_core_ptr->checkpoints_coordinates
        );

    const weak_ptr<Level_wave> wave_weak_ptr = this->current_wave_ptr;
    this->level_core_ptr->current_wave_pointer = wave_weak_ptr;
}

void Pointer_manager::instantiate_enemy_factories() {
    float factories_x = this->level_core_ptr->checkpoints_coordinates.at(0).at(0);
    float factories_y = this->level_core_ptr->checkpoints_coordinates.at(0).at(1);

    this->factories_shared_ptrs = {
        make_shared<EnemyFactory>(factories_x, factories_y),
        make_shared<FlashFactory>(factories_x, factories_y),
        make_shared<TankFactory>(factories_x, factories_y),
        make_shared<BossFactory>(factories_x, factories_y)
    };

    this->level_core_ptr->factories_weak_ptrs = {
        factories_shared_ptrs.basic_enemy_factory,
        factories_shared_ptrs.flash_enemy_factory,
        factories_shared_ptrs.tank_enemy_factory,
        factories_shared_ptrs.boss_factory
    };
}

void Pointer_manager::instantiate_towers() {
    towers_ptr.reserve(this->level_core_ptr->number_of_towers);

    for (int i = 0; i < this->level_core_ptr->number_of_towers; i++) {

        shared_ptr<Tower> tower_ptr = make_shared<Tower>(
            this->level_core_ptr->towers_coordinates.at(i).at(0),
            this->level_core_ptr->towers_coordinates.at(i).at(1)
            );

        this->towers_ptr.push_back(tower_ptr);
    }
}

void Pointer_manager::delete_manager() {
    cout << "Deleting manager" << endl;

    this->current_wave_ptr.reset();
    this->level_core_ptr.reset();
    this->user_data_ptr.reset();

    this->factories_shared_ptrs.basic_enemy_factory.reset();
    this->factories_shared_ptrs.flash_enemy_factory.reset();
    this->factories_shared_ptrs.tank_enemy_factory.reset();
    this->factories_shared_ptrs.boss_factory.reset();

    for (shared_ptr<Tower> tower_ptr : towers_ptr) {
        tower_ptr.reset();
    }
}

int Pointer_manager::wave_is_running() const {
    if (this->current_wave_ptr->wave_is_running()) {
        return 1;
    } else {
        return 0;
    }
}