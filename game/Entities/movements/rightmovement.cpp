#include "rightmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

int RightMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    if (enemy.getX() + enemy.getSpeed() > checkpoint[0]) {
        enemy.setSpeed(checkpoint[0] - enemy.getX());
        enemy.current_following_checkpoint++;
    }
    enemy.setX(enemy.getSpeed());
    return 1;
}
