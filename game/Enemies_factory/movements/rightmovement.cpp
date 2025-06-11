#include "rightmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

void RightMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    enemy.setX(static_cast<int>(enemy.getSpeed()));
    cout<<"RIGHTMOVEMENT : L'ennemi se déplace x : "<<enemy.getX()<<" y : "<<enemy.getY()<<endl;
}
