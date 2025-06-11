#include "straightmovement.hpp"
#include "../enemies/enemy.hpp"
#include <array>
#include <iostream>

using std::cout;
using std::endl;

// 0,0 = corner top left

void StraightMovement::move(Enemy& enemy, const std::array<int, 2>& checkpoint) {
    cout<<"hAAAAAA"<<endl;
    if (checkpoint[0] < enemy.getX()) {
        //move left x --
        enemy.setX(static_cast<int>(enemy.getSpeed())*-1);
    } else if (checkpoint[0] > enemy.getX()) {
        //move right x ++
        enemy.setX(static_cast<int>(enemy.getSpeed()));
    }
    if (checkpoint[1] < enemy.getY()) {
        //move up y ++
        enemy.setY(static_cast<int>(enemy.getSpeed())*-1);
    } else if (checkpoint[1] > enemy.getY()) {
        //move down y --
        enemy.setY(static_cast<int>(enemy.getSpeed()));
    }
    cout<<"L'ennemi se déplace x : "<<enemy.getX()<<" y : "<<enemy.getY()<<endl;
}
