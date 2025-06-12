#include "upmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

void UpMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    if (enemy.getY() + enemy.getSpeed() > checkpoint[1]) {
        // enemy.setSpeed(abs(enemy.getY()+enemy.getSpeed()-checkpoint[1]));
        enemy.setSpeed(checkpoint[1] - enemy.getY());
        // enemy.setSpeed(checkpoint[1]);
    }
    enemy.setY(static_cast<int>(enemy.getSpeed()));
    cout<<"↑ : L'ennemi se déplace x : "<<enemy.getX()<<" y : "<<enemy.getY()<<endl;
}
