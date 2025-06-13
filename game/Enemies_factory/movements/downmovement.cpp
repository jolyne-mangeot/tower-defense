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
    }
    enemy.setY(static_cast<int>(enemy.getSpeed())*-1);

    cout<<"↓ : L'ennemi se déplace x : "<<enemy.getX()<<" y : "<<enemy.getY()<<endl;

    return 2;
}