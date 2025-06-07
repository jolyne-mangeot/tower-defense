#include "straightmovement.hpp"
#include "../enemies/enemy.hpp"

void StraightMovement::move(Enemy& enemy) {
    enemy.setY(static_cast<int>(enemy.getSpeed()));
}
