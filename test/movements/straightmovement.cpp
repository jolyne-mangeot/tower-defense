#include "straightmovement.hpp"
#include "Enemy.hpp"

void StraightMovement::move(Enemy& enemy) {
    enemy.setY(static_cast<int>(enemy.getSpeed()));
}
