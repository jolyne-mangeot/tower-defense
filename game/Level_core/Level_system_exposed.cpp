//
// Created by josur on 11/06/2025.
//

#define LEVEL_EXPOSED_CPP
#include "level_utils.hpp"

extern "C" {

    __declspec(dllexport) shared_ptr<Level_core> level_instantiation(const int level_id) {
        const shared_ptr<Level_core> current_level_ptr = make_shared<Level_core>(
            "Assets/Scenes/level_0" + to_string(level_id)
            + "/level_" + to_string(level_id) + ".json"
            );
        const weak_ptr<Level_core> level_weak_ptr = current_level_ptr;
        current_level_ptr->self_pointer = level_weak_ptr;
        return current_level_ptr;
    }

    __declspec(dllexport) shared_ptr<User_data> user_instantiation(const shared_ptr<Level_core> &level_ptr) {
        const shared_ptr<User_data> current_user_ptr = make_shared<User_data>();

        const weak_ptr level_weak_ptr = level_ptr;
        current_user_ptr->current_level_ptr = level_weak_ptr;

        const weak_ptr user_weak_ptr = current_user_ptr;
        level_ptr->user_data_ptr = user_weak_ptr;

        return current_user_ptr;
    }

    __declspec(dllexport) void factories_instantiation(const shared_ptr<Level_core> &level) {
        level->generate_pointers(level);
    }

    __declspec(dllexport) weak_ptr<Level_wave> wave_instantiation(const shared_ptr<Level_core> &level) {
        return level->instantiate_wave();
    }

    __declspec(dllexport) int wave_is_running(const shared_ptr<Level_core> &level) {
        return level->wave_is_running();
    }

    __declspec(dllexport) int enemy_went_through(const shared_ptr<Level_core> &level) {
        level->enemies_through++;
        return level->enemies_through;
    }

    __declspec(dllexport) int get_gold(const shared_ptr<User_data> &user_ptr) {
        return user_ptr->current_gold;
    }

    __declspec(dllexport) int get_score(const shared_ptr<User_data> &user_ptr) {
        return user_ptr->score;
    }

    __declspec(dllexport) void wave_end(const shared_ptr<Level_core> &level) {
        level->current_wave_pointer->~Level_wave();
        level->current_wave_pointer.reset();
    }

    __declspec(dllexport) void level_end(shared_ptr<Level_core> level) {
        level->~Level_core();
        level.reset();
    }

    __declspec(dllexport) void user_data_end(shared_ptr<User_data> user_data) {
        user_data->~User_data();
        user_data.reset();
    }
}
