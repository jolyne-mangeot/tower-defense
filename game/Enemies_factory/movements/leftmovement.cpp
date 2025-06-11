#include "leftmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

void LeftMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    enemy.setX(static_cast<int>(enemy.getSpeed())*-1);
    cout<<"LEFTMOVEMENT : L'ennemi se déplace x : "<<enemy.getX()<<" y : "<<enemy.getY()<<endl;
}
