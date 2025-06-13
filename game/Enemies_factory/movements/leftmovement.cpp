#include "leftmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

int LeftMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    if (enemy.getX() - enemy.getSpeed() < checkpoint[0]) {
        enemy.setSpeed(abs(checkpoint[0] - enemy.getX()));
    }

    enemy.setX(static_cast<int>(enemy.getSpeed())*-1);

    cout<<"← : L'ennemi se déplace x : "<<enemy.getX()<<" y : "<<enemy.getY()<<endl;

    return 3;
}