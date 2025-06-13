//
// Created by josur on 11/06/2025.
//

#include "Level_wave.hpp"


bool Level_wave::wave_is_running() {
    bool wave_running = false;
    for (shared_ptr<Enemy> enemy : instantiated_enemies) {
        if (enemy->getHp() > 0) {
            enemy_slayed(enemy);
            wave_running = true;
        }
    }
    return wave_running;
}

void Level_wave::enemy_slayed(shared_ptr<Enemy> &enemy) {

    user_data_ptr.lock()->win_gold(enemy->revenue);
    user_data_ptr.lock()->win_score(enemy->revenue);
    slayed_enemies++;
    gold_won += enemy->revenue;

    enemy_erased(enemy);
}

void Level_wave::enemy_went_through(const weak_ptr<Enemy> &enemy) {

    for (shared_ptr<Enemy> enemy_in_memory : instantiated_enemies) {
        if (enemy_in_memory == enemy.lock()) {
            enemy_erased(enemy_in_memory);
        }
    }

    enemies_through_wave++;
    enemy_went_through_flag = true;
}

void Level_wave::enemy_erased(shared_ptr<Enemy> &enemy) {

    enemy.reset();

    instantiated_enemies.erase(
        remove(
            instantiated_enemies.begin(),
            instantiated_enemies.end(),
            enemy
            ),
            instantiated_enemies.end()
            );
}