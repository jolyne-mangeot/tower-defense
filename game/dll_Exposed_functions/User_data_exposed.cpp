//
// Created by Anwender on 15/06/2025.
//

#include "exposed_utils.hpp"

extern "C" {

    __declspec(dllexport) int get_gold(const shared_ptr<Pointer_manager> &manager) {
        return manager->user_data_ptr->current_gold;
    }

    __declspec(dllexport) int get_score(const shared_ptr<Pointer_manager> &manager) {
        return manager->user_data_ptr->score;
    }

    __declspec(dllexport) int get_through_enemies(const shared_ptr<Pointer_manager> &manager) {
        return manager->user_data_ptr->through_enemies;
    }

}