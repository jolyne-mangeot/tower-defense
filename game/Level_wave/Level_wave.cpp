//
// Created by josur on 11/06/2025.
//

#include "Level_wave.hpp"


bool Level_wave::wave_is_running() const {
    for (const shared_ptr<Enemy>& enemy : instantiated_enemies) {
        if (enemy->getHp() > 0) {
            return true;
        }
    }
    return false;
}

void Level_wave::enemy_slayed(const weak_ptr<Enemy> &enemy) {

    user_data_ptr.lock()->win_gold(enemy.lock()->revenue);
    user_data_ptr.lock()->win_score(enemy.lock()->revenue);
    slayed_enemies++;
    gold_won += enemy.lock()->revenue;

    enemy_erased(enemy);
}

void Level_wave::enemy_went_through(const weak_ptr<Enemy> &enemy) {

    enemy_erased(enemy);

    level_core_ptr.lock()->update_enemies_through();
}

void Level_wave::enemy_erased(const weak_ptr<Enemy> &enemy) {

    delete enemy.lock();

    instantiated_enemies.erase(
        remove(
            instantiated_enemies.begin(),
            instantiated_enemies.end(),
            enemy.lock()
            ),
            instantiated_enemies.end()
            );
}