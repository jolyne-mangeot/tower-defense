//
// Created by josur on 11/06/2025.
//

#ifndef LEVEL_WAVE_HPP
#define LEVEL_WAVE_HPP

#include "utils.hpp"
#include "game_structs.hpp"
#include "upmovement.hpp"
#include "User_data.hpp"

class Level_wave {
public:
    level_wave_info wave_data;
    weak_ptr<User_data> user_data_ptr;
    enemy_factories_weak_ptrs factories_weak_ptrs;
    bool wave_victory_defeat{true};
    int enemies_through_wave{0};

    vector<shared_ptr<Enemy>> instantiated_enemies;
    weak_ptr<vector<array<int, 2>>> checkpoints_coordinates;
    bool enemy_went_through_flag{false};
    int slayed_enemies{0};
    int gold_won{0};
    int seconds_elapsed{0};

    explicit Level_wave(
            const level_wave_info &wave_data,
            const weak_ptr<User_data>& user_data_ptr,
            const enemy_factories_weak_ptrs& factories_weak_ptrs,
            const weak_ptr<vector<array<int, 2>>>& checkpoints_coordinates)
        : wave_data(wave_data),
        user_data_ptr(user_data_ptr),
        factories_weak_ptrs(factories_weak_ptrs),
        checkpoints_coordinates(checkpoints_coordinates){

        instantiated_enemies.resize(wave_data.number_of_enemies);

        for (int i = 0; i < wave_data.number_of_enemies; i++) {

            switch (wave_data.spawn_order.at(i+1)) {
                case 0:
                    instantiated_enemies.at(i) = factories_weak_ptrs.basic_enemy_factory.lock()->createEnemy(new UpMovement);
                    instantiated_enemies.at(i)->checkpoints_coordinates = checkpoints_coordinates;
                    break;
                case 1:
                    instantiated_enemies.at(i) = factories_weak_ptrs.flash_enemy_factory.lock()->createEnemy(new UpMovement);
                    instantiated_enemies.at(i)->checkpoints_coordinates = checkpoints_coordinates;

                    break;
                case 2:
                    instantiated_enemies.at(i) = factories_weak_ptrs.tank_enemy_factory.lock()->createEnemy(new UpMovement);
                    instantiated_enemies.at(i)->checkpoints_coordinates = checkpoints_coordinates;

                    break;
                case 3:
                    instantiated_enemies.at(i) = factories_weak_ptrs.boss_factory.lock()->createEnemy(new UpMovement);
                    instantiated_enemies.at(i)->checkpoints_coordinates = checkpoints_coordinates;

                    break;
                default:
                    continue;
            }
        }
    };

    bool wave_is_running();

    void enemy_slayed(shared_ptr<Enemy> &enemy);

    void enemy_went_through(const weak_ptr<Enemy> &enemy);

    void enemy_erased(shared_ptr<Enemy> &enemy);

    ~Level_wave() {
        wave_results wave_results;

        if (this->wave_victory_defeat) {
            wave_results.wave_won = 1;
        } else {wave_results.wave_won = 0;}
        wave_results.enemies_slayed = 0;
        wave_results.enemies_through = enemies_through_wave;
        wave_results.gold_collected = gold_won;
        wave_results.seconds_elapsed = seconds_elapsed;
        user_data_ptr.lock()->waves_outcomes.push_back(wave_results);

        for (shared_ptr<Enemy> enemy : instantiated_enemies) {
            enemy.reset();
        }
    }
};

#endif //LEVEL_WAVE_HPP