//
// Created by Anwender on 15/06/2025.
//

#include "exposed_utils.hpp"

extern "C" {

    __declspec(dllexport) Enemy* recover_enemy_ptr(const shared_ptr<Pointer_manager> &manager, const int enemy_id) {
        cout << "Enemy pointer recovered" << endl;
        return manager->current_wave_ptr->instantiated_enemies.at(enemy_id).get();
    }

    __declspec(dllexport) int check_null_ptr(const Enemy *enemy) {
        if (enemy == nullptr) {
            return 1;
        }
        return 0;
    }

    __declspec(dllexport) void enemy_spawned(Enemy* enemy) {
        enemy->enemy_spawned = true;
    }

    __declspec(dllexport) int enemy_move(const shared_ptr<Pointer_manager> &manager, Enemy* enemy) {
        const int movement_status = enemy->move(manager->level_core_ptr->checkpoints_coordinates);
        return movement_status;
    }

    __declspec(dllexport) void get_enemy_status(const Enemy* enemy, float*x, float*y, float *health) {
        *x = enemy->getX();
        *y = enemy->getY();
        *health = enemy->getHp();
    }

    __declspec(dllexport) int recover_enemy_type(const Enemy* enemy) {
        cout << "Recovering enemy type" << endl;
        return enemy->enemy_type_id;
    }

    __declspec(dllexport) void enemy_slayed(const shared_ptr<Pointer_manager> &manager, Enemy *enemy) {
        manager->user_data_ptr->win_gold(enemy->revenue);
        manager->user_data_ptr->win_score(enemy->revenue);
        cout << "Enemy slayed, revenue added to data";
        manager->current_wave_ptr->enemy_slayed(enemy);
    }

    __declspec(dllexport) void enemy_went_through(const shared_ptr<Pointer_manager> &manager, Enemy *enemy) {
        manager->user_data_ptr->through_enemies++;
        cout << "Enemy went through !" << endl;
        manager->current_wave_ptr->enemy_went_through(enemy);
    }

}