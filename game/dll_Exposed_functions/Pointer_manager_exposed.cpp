//
// Created by josur on 11/06/2025.
//

#include "exposed_utils.hpp"

extern "C" {

    __declspec(dllexport) shared_ptr<Pointer_manager>* pointer_manager_instantiation() {
        freopen("plugin_log.txt", "w", stdout);
        cout << "DLL Loaded !" << endl;
        return new shared_ptr<Pointer_manager>(make_shared<Pointer_manager>());
    }

    __declspec(dllexport) void level_user_instantiation(
            const shared_ptr<Pointer_manager> &manager, const char* json_path,
            int* checkpoints, int* towers, int* waves) {

        cout << "Before Level_core, json path recovered : " << json_path << endl;

        manager->instantiate_level_core(json_path);
        cout << "Level_core started !" << endl;

        manager->instantiate_user_data();
        cout << "User_data started !" << endl;

        manager->instantiate_enemy_factories();
        cout << "Enemy_factories started !" << endl;

        manager->instantiate_towers();
        cout << "Towers started !" << endl;

        *checkpoints = manager->level_core_ptr->number_of_checkpoints;
        *towers = manager->level_core_ptr->number_of_towers;
        *waves = manager->level_core_ptr->number_of_waves;
    }

    __declspec(dllexport) void level_end(shared_ptr<Pointer_manager> &manager) {
        manager->delete_manager();
        cout << "Manager successfully deleted" << endl;
        manager.reset();
    }
}
