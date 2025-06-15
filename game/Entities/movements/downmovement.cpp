#include "downmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

int DownMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    if (enemy.getY() - enemy.getSpeed() < checkpoint[1]) {
        enemy.setSpeed(abs(checkpoint[1] - enemy.getY()));
        enemy.current_following_checkpoint++;
    }
    enemy.setY(enemy.getSpeed()*-1);
    return 2;
}