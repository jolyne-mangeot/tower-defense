//
// Created by josur on 11/06/2025.
//

#define LEVEL_EXPOSED_CPP
#include "utils.hpp"

#include "Level_core/Level_core.hpp"
#include "Level_wave.hpp"
#include "User_data.hpp"
#include "Pointer_manager.hpp"
// #include "tower.h"

extern "C" {

    __declspec(dllexport) shared_ptr<Pointer_manager>* level_user_instantiation(const int level_id) {
        shared_ptr<Pointer_manager> ptr_manager = make_shared<Pointer_manager>();
        ptr_manager->instantiate_level_core(level_id);
        ptr_manager->instantiate_user_data();
        ptr_manager->instantiate_enemy_factories();
        // ptr_manager->instantiate_towers();
        return &ptr_manager;
    }

    __declspec(dllexport) void wave_instantiation(const shared_ptr<Pointer_manager> &manager) {
        manager->instantiate_level_wave();
    }

    __declspec(dllexport) int wave_is_running(const shared_ptr<Pointer_manager> &manager) {
        return manager->wave_is_running();
    }

    __declspec(dllexport) int advance_wave(const shared_ptr<Pointer_manager> &manager) {
        if (manager->level_core_ptr->current_wave_id == manager->level_core_ptr->number_of_waves) {
            return 0;
        } else {return manager->level_core_ptr->current_wave_id++;}
    }

    __declspec(dllexport) int get_gold(const shared_ptr<Pointer_manager> &manager) {
        return manager->user_data_ptr->current_gold;
    }

    __declspec(dllexport) int get_score(const shared_ptr<Pointer_manager> &manager) {
        return manager->user_data_ptr->score;
    }

    __declspec(dllexport) int check_through_enemies(const shared_ptr<Pointer_manager> &manager) {
        if (manager->current_wave_ptr->enemy_went_through_flag) {
            manager->level_core_ptr->enemies_through++;
        }
        return manager->level_core_ptr->enemies_through;
    }

    __declspec(dllexport) void wave_end(const shared_ptr<Pointer_manager> &manager) {
        manager->current_wave_ptr->~Level_wave();
        manager->current_wave_ptr.reset();
    }

    __declspec(dllexport) void level_end(shared_ptr<Pointer_manager> manager) {
        manager->~Pointer_manager();
        manager.reset();
    }

    __declspec(dllexport) void user_data_end(shared_ptr<User_data> user_data) {
        user_data->~User_data();
        user_data.reset();
    }
}
