//
// Created by josur on 11/06/2025.
//
#ifndef USER_DATA_HPP
#define USER_DATA_HPP

#include "utils.hpp"
#include "game_structs.hpp"

class User_data {

public:
    int current_gold{120};
    int spent_gold{0};
    int total_gold{120};
    int through_enemies{0};
    int score{0};
    int current_level{1};
    vector<wave_results> waves_outcomes;

    array<int, 3> towers_base_price{120,280,600};

    array<int, 3> towers_actual_prices{120,280,600};

    array<int, 3> towers_bought{0,0,0};

    weak_ptr<User_data> self_ptr;

    void refresh_prices() {
        for (int tower_index = 0; tower_index < 3; tower_index++) {
            towers_actual_prices.at(tower_index) = static_cast<int>(
                towers_base_price.at(tower_index) +
                (towers_base_price.at(tower_index) * towers_bought.at(tower_index) * 0.1)
            );
        }
        cout << "Towers new prices : " <<
            to_string(towers_actual_prices.at(0)) << " " <<
                to_string(towers_actual_prices.at(1)) << " " <<
                    to_string(towers_actual_prices.at(2)) << " " << endl;
    }

    void win_gold(const int reward) {
        current_gold += reward;
        total_gold += reward;
    }

    void buy_tower(const int tower_level) {
        current_gold -= towers_actual_prices.at(tower_level);
        spent_gold += towers_actual_prices.at(tower_level);
        towers_bought.at(tower_level)++;
        refresh_prices();
    }

    void win_score(const int reward) {
        score += reward;
    }
};

#endif //USER_DATA_HPP
