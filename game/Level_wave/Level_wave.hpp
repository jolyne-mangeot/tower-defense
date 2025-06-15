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
    vector<array<int, 2>> checkpoints_coordinates;
    int slayed_enemies{0};
    int gold_won{0};
    int seconds_elapsed{0};

    explicit Level_wave(
            const level_wave_info &wave_data,
            const weak_ptr<User_data>& user_data_ptr,
            const enemy_factories_weak_ptrs& factories_weak_ptrs,
            const vector<array<int, 2>>& checkpoints_coordinates);

    bool wave_is_running();

    void enemy_slayed(Enemy *enemy);

    void enemy_went_through(Enemy *enemy);

    void enemy_erased(shared_ptr<Enemy> &enemy);

    void wave_end() const {
        wave_results wave_results;

        if (this->wave_victory_defeat) {
            wave_results.wave_won = 1;
        }
        else {
            wave_results.wave_won = 0;
        }

        wave_results.enemies_slayed = slayed_enemies;
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