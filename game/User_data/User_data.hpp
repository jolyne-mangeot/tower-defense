//
// Created by josur on 11/06/2025.
//
#ifndef USER_DATA_HPP
#define USER_DATA_HPP

#include "utils.hpp"
#include "game_structs.hpp"

class Level_core;

class User_data {
public:
    int current_gold{120};
    int spent_gold{0};
    int total_gold{0};
    int score{0};
    int current_level{1};
    vector<wave_results> waves_outcomes;

    array<int, 3> towers_base_price{150,300,600};

    array<int, 3> towers_actual_prices{150,300,600};

    array<int, 3> towers_bought{0,0,0};

    weak_ptr<User_data> self_ptr;
    weak_ptr<Level_core> current_level_ptr{};

    void refresh_prices() {
        for (int i = 0; i < 3; i++) {
            towers_actual_prices.at(i) = static_cast<int>(towers_base_price[i] +
            ( towers_base_price[i] * towers_bought[i] * 0.1 ));
        }
    }

    void win_gold(const int reward) {
        current_gold += reward;
        total_gold += reward;
    }
    void buy_turret(const int tower_level) {
        current_gold -= towers_actual_prices.at(tower_level);
        towers_bought[tower_level]++;
        refresh_prices();
    }
    void win_score(const int reward) {
        score += reward;
    }
};

#endif //USER_DATA_HPP
