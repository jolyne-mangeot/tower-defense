//
// Created by Anwender on 12/06/2025.
//

#ifndef POINTER_MANAGER_HPP
#define POINTER_MANAGER_HPP

#include "utils.hpp"

#include "User_data.hpp"
#include "Level_core.hpp"
#include "Level_wave.hpp"
#include "game_structs.hpp"
#include "tower.hpp"

class Pointer_manager {

    public:

    shared_ptr<Level_core> level_core_ptr;
    shared_ptr<User_data> user_data_ptr;
    shared_ptr<Level_wave> current_wave_ptr;
    vector<shared_ptr<Tower>> towers_ptr;
    enemy_factories_shared_ptrs factories_shared_ptrs;

    void instantiate_level_core(const char* json_path);
    void instantiate_user_data();
    void instantiate_level_wave();
    void instantiate_enemy_factories();
    void instantiate_towers();

    int wave_is_running() const;

    void delete_manager();

};


#endif //POINTER_MANAGER_HPP
