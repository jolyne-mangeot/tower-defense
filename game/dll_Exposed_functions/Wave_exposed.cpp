//
// Created by Anwender on 15/06/2025.
//

#include "exposed_utils.hpp"

extern "C" {

    __declspec(dllexport) void wave_instantiation(const shared_ptr<Pointer_manager> &manager, int* enemy_amount, int* spawn_rate) {
        cout << "In wave Instantiation updated" << endl;
        manager->instantiate_level_wave();
        cout << "Wave instantiated !" << endl;
        *enemy_amount = manager->level_core_ptr->waves.at(manager->level_core_ptr->current_wave_id - 1).number_of_enemies;
        *spawn_rate = manager->level_core_ptr->waves.at(manager->level_core_ptr->current_wave_id - 1).spawn_interval;
    }

    __declspec(dllexport) int wave_is_running(const shared_ptr<Pointer_manager> &manager) {
        return manager->wave_is_running();
    }

    __declspec(dllexport) void wave_end(const shared_ptr<Pointer_manager> &manager) {
        manager->current_wave_ptr->wave_end();
        manager->current_wave_ptr.reset();
    }

    __declspec(dllexport) void wave_win(const shared_ptr<Pointer_manager> &manager, const int seconds_elapsed) {
        cout << "Wave " << to_string(manager->level_core_ptr->current_wave_id) << " won" << endl;
        manager->current_wave_ptr->wave_victory_defeat = true;
        manager->current_wave_ptr->seconds_elapsed = seconds_elapsed;
        wave_end(manager);
    }

    __declspec(dllexport) void wave_lost(const shared_ptr<Pointer_manager> &manager, const int seconds_elapsed) {
        cout << "Wave " << to_string(manager->level_core_ptr->current_wave_id) << " lost" << endl;
        manager->current_wave_ptr->wave_victory_defeat = false;
        manager->current_wave_ptr->seconds_elapsed = seconds_elapsed;
        wave_end(manager);
    }

    __declspec(dllexport) int advance_wave(const shared_ptr<Pointer_manager> &manager) {
        if (manager->level_core_ptr->current_wave_id == manager->level_core_ptr->number_of_waves) {
            cout << "Last wave reached, return 0" << endl;
            return 0;
        } else {
            manager->level_core_ptr->current_wave_id++;
            cout << "Advancing to wave " << to_string(manager->level_core_ptr->current_wave_id) << endl;
            return manager->level_core_ptr->current_wave_id;
        }
    }

}