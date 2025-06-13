//
// Created by josur on 12/06/2025.
//

#ifndef GAME_STRUCTS_HPP
#define GAME_STRUCTS_HPP

#include "enemyfactories/enemyfactory.hpp"
#include "enemyfactories/tankfactory.hpp"
#include "enemyfactories/flashfactory.hpp"
#include "enemyfactories/bossfactory.hpp"

typedef struct {
    shared_ptr<EnemyFactory> basic_enemy_factory;
    shared_ptr<FlashFactory> flash_enemy_factory;
    shared_ptr<TankFactory> tank_enemy_factory;
    shared_ptr<BossFactory> boss_factory;
} enemy_factories_shared_ptrs;

typedef struct {
    weak_ptr<EnemyFactory> basic_enemy_factory;
    weak_ptr<FlashFactory> flash_enemy_factory;
    weak_ptr<TankFactory> tank_enemy_factory;
    weak_ptr<BossFactory> boss_factory;
} enemy_factories_weak_ptrs;

typedef struct {
    int number_of_enemies;
    int spawn_interval;
    vector<int> spawn_order;
} level_wave_info;

typedef struct {
    int wave_won;
    int gold_collected;
    int seconds_elapsed;
    int enemies_slayed;
    int enemies_through;
} wave_results;

#endif //GAME_STRUCTS_HPP
