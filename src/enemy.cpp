
#include "enemy.h"
#include <iostream>

using std::cout;
using std::endl;

Enemy::Enemy(float x, float y) : x(x), y(y) {}

void Enemy::takeDamage(int dmg)
{
    health -= dmg;
    std::cout << "L'ennemi a subi " << dmg << "degats";
    if (health <= 0)
    {
        std::cout << "Le vilain très vilain est ko !! \n";
    }
    else
    {
        std::cout << "PV restants : " << health << "\n";
    }
}

bool Enemy::isDead() const
{
    return health <= 0;
}
