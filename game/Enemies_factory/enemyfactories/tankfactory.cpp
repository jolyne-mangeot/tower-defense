#include "tankfactory.hpp"

Enemy* TankFactory::createEnemy(IMovementStrategy* strategy) {
        Enemy* new_enemy = new Tank(strategy);
        new_enemy->setX(x);
        new_enemy->setY(y);
        return new_enemy;
    }

// shared_ptr<Enemy> TankFactory::createEnemy(IMovementStrategy* strategy) override {
//     shared_ptr<Enemy> new_tank_ptr = make_shared<Tank>(strategy);
//     new_tank_ptr->setX(x);
//     new_tank_ptr->setY(y);

//     return new_tank_ptr;
// }

