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
