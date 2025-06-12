//
// Created by josur on 11/06/2025.
//

#ifndef LEVEL_WAVE_HPP
#define LEVEL_WAVE_HPP

#include "level_utils.hpp"

class Level_core;
class User_data;

class Level_wave {
public:
    level_wave_info wave_data;
    weak_ptr<Level_core> level_core_ptr;
    weak_ptr<User_data> user_data_ptr;
    enemy_factories_weak_ptrs factories_weak_ptrs;

    vector<shared_ptr<Enemy>> instantiated_enemies;
    int slayed_enemies{0};
    int gold_won{0};
    int seconds_elapsed{0};

    explicit Level_wave(
            const level_wave_info &wave_data,
            const weak_ptr<Level_core>& level_core_ptr,
            const weak_ptr<User_data>& user_data_ptr,
            const enemy_factories_weak_ptrs& factories_weak_ptrs)
        : wave_data(wave_data),
        level_core_ptr(level_core_ptr),
        user_data_ptr(user_data_ptr),
        factories_weak_ptrs(factories_weak_ptrs){

        instantiated_enemies.resize(wave_data.number_of_enemies);

        for (int i = 0; i < wave_data.number_of_enemies; i++) {

            switch (wave_data.spawn_order.at(i+1)) {
                case 0:
                    instantiated_enemies.at(i) = factories_weak_ptrs.basic_enemy_factory.lock()->createEnemy(new StraightMovement);
                    break;
                case 1:
                    instantiated_enemies.at(i) = factories_weak_ptrs.flash_enemy_factory.lock()->createEnemy(new StraightMovement);
                    break;
                case 2:
                    instantiated_enemies.at(i) = factories_weak_ptrs.tank_enemy_factory.lock()->createEnemy(new StraightMovement);
                    break;
                case 3:
                    instantiated_enemies.at(i) = factories_weak_ptrs.boss_factory.lock()->createEnemy(new StraightMovement);
                    break;
                default:
                    continue;
            }
        }
    };

    bool wave_is_running() const;

    ~Level_wave() {
        wave_results wave_results;

        if (level_core_ptr.lock()->enemies_through >= 3) {
            wave_results.wave_won = 0;
        } else {wave_results.wave_won = 1;}
        wave_results.enemies_slayed = 0;
        wave_results.enemies_through = level_core_ptr.lock()->enemies_through;
        wave_results.gold_collected = gold_won;
        wave_results.seconds_elapsed = seconds_elapsed;
        user_data_ptr.lock()->waves_outcomes.push_back(wave_results);

        for (shared_ptr<Enemy> enemy : instantiated_enemies) {
            enemy.reset();
        }
    }
};

#endif //LEVEL_WAVE_HPP