//
// Created by josur on 11/06/2025.
//

#include "Level_wave.hpp"

Level_wave::Level_wave(
    const level_wave_info &wave_data,
    const weak_ptr<User_data> &user_data_ptr,
    const enemy_factories_weak_ptrs &factories_weak_ptrs,
    const vector<array<int,2>> &checkpoints_coordinates)
        : wave_data(wave_data),
        user_data_ptr(user_data_ptr),
        factories_weak_ptrs(factories_weak_ptrs),
        checkpoints_coordinates(checkpoints_coordinates) {

    instantiated_enemies.resize(wave_data.number_of_enemies);

    cout << "In Enemies instantiation, number of enemies : " << to_string(wave_data.number_of_enemies) << endl;

    for (int i = 0; i < wave_data.number_of_enemies; i++) {
        cout << "Spawning enemy : " << to_string(i) << endl;

        switch (wave_data.spawn_order.at(i)) {
            case 0:
                instantiated_enemies.at(i) = factories_weak_ptrs.basic_enemy_factory.lock()->createEnemy(new UpMovement);
                break;
            case 1:
                instantiated_enemies.at(i) = factories_weak_ptrs.flash_enemy_factory.lock()->createEnemy(new UpMovement);
                break;
            case 2:
                instantiated_enemies.at(i) = factories_weak_ptrs.tank_enemy_factory.lock()->createEnemy(new UpMovement);
                break;
            case 3:
                instantiated_enemies.at(i) = factories_weak_ptrs.boss_factory.lock()->createEnemy(new UpMovement);
                break;
            default:
                continue;
        }
    }
}


bool Level_wave::wave_is_running() {
    bool wave_running = false;
    for (const shared_ptr<Enemy>& enemy : instantiated_enemies) {
        if (enemy->getHp() > 0) {
            wave_running = true;
        }
    }
    return wave_running;
}

void Level_wave::enemy_slayed(Enemy *enemy) {
    slayed_enemies++;
    gold_won += enemy->revenue;
    cout << " won revenue : " << to_string(enemy->revenue) << endl;
    enemy->enemy_spawned = false;
}

void Level_wave::enemy_went_through(Enemy *enemy) {

    enemy->enemy_spawned = false;
    enemies_through_wave++;
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