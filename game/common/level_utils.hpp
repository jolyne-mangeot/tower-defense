//
// Created by josur on 11/06/2025.
//

#ifndef LEVEL_UTILS_HPP
#define LEVEL_UTILS_HPP

#include "utils.hpp"

#include "enemyfactories/enemyfactory.hpp"
#include "enemyfactories/tankfactory.hpp"
#include "enemyfactories/flashfactory.hpp"
#include "enemyfactories/bossfactory.hpp"
#include "movements/straightmovement.hpp"

#include "enemy.hpp"
#include "flash.hpp"
#include "tank.hpp"
#include "boss.hpp"

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

#if defined(USER_DATA_HPP) & !defined(USER_DATA_INCLUDED)
#define USER_DATA_INCLUDED

#include "Level_core.hpp"
#include "Level_wave.hpp"

#endif

#if defined (LEVEL_EXPOSED_CPP) & !defined(LEVEL_EXPOSED_INCLUDED)
#define LEVEL_EXPOSED_INCLUDED

#include "Level_core.hpp"
#include "Level_wave.hpp"
#include "User_data.hpp"

#endif

#if defined(LEVEL_CORE_HPP) & !defined(LEVEL_CORE_INCLUDED)
#define LEVEL_CORE_INCLUDED

#include "Level_wave.hpp"
#include "User_data.hpp"

#endif

#if defined(LEVEL_WAVE_HPP) & !defined(LEVEL_WAVE_INCLUDED)
#define LEVEL_WAVE_INCLUDED

#include "Level_core.hpp"
#include "User_data.hpp"

#endif

#endif //LEVEL_UTILS_HPP
