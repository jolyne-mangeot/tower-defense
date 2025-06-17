//
// Created by Anwender on 15/06/2025.
//

#include "exposed_utils.hpp"

extern "C" {

    __declspec(dllexport) Tower* recover_tower_ptr(const shared_ptr<Pointer_manager> &manager, const int tower_id) {
        cout << "Tower pointer recovered" << endl;
        return manager->towers_ptr.at(tower_id).get();
    }

    __declspec(dllexport) void get_tower_coordinates(const Tower *tower, int *x, int *y) {
        *x = tower->x;
        *y = tower->y;
    }

    __declspec(dllexport) void get_tower_buy_status(
            const shared_ptr<Pointer_manager> &manager, const Tower *tower,
            int *tower_price, int *buyable_tower) {

        *tower_price = manager->user_data_ptr->towers_actual_prices.at(tower->get_level());

        if (manager->user_data_ptr->current_gold >= *tower_price) {
            *buyable_tower = 1;
        } else {
            *buyable_tower = 0;
        }
    }

    __declspec(dllexport) void get_tower_special_status(const Tower *tower, int *hit_counter, int *special_ready) {

        *hit_counter = tower->get_hit_counter();
        *special_ready = tower->get_special_ready();
    }

    __declspec(dllexport) int buy_tower(const shared_ptr<Pointer_manager> &manager, Tower *tower) {
        cout << "Tower bought !" << endl;

        manager->user_data_ptr->buy_tower(tower->get_level());
        tower->buy_tower();

        return tower->get_level();
    }

    __declspec(dllexport) void upgrade_tower(const shared_ptr<Pointer_manager> &manager, Tower *tower,
            int *tower_level, float *shooting_speed, int *special_charge) {
        cout << "Tower upgraded to level " << to_string(*tower_level + 1) << " !" << endl;
        if (tower->get_level() < 3) {

            manager->user_data_ptr->buy_tower(tower->get_level());
            tower->upgrade_tower();
        }

        *tower_level = tower->get_level();
        *shooting_speed = tower->get_shooting_speed();
        *special_charge = tower->get_special_charge();
    }

    __declspec(dllexport) Enemy* enemy_observer(const shared_ptr<Pointer_manager> &manager, const Tower *tower) {
        if (manager->current_wave_ptr != nullptr) {
            for (const shared_ptr<Enemy>& potential_target : manager->current_wave_ptr->instantiated_enemies) {
                if (tower->isInRange(potential_target.get()) && potential_target->getHp() > 0 &&
                    potential_target->enemy_spawned) {
                    cout << "Target detected" << endl;
                    return potential_target.get();
                    }
            }
        }
        return nullptr;
    }

    __declspec(dllexport) int attack_close_enemy(Tower* tower, Enemy* enemy) {
        cout << "Tower attacking enemy ! ";
        if (enemy != nullptr) {
            if (tower->get_special_ready() == 1) {
                tower->special_attack(enemy);
                return 1;
            }
            tower->attack(enemy);
            return 0;
        }
        return -1;
    }

}
