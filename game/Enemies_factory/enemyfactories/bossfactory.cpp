#include "bossfactory.hpp"

Enemy* BossFactory::createEnemy(IMovementStrategy* strategy) {
        Enemy* new_enemy = new Boss(strategy);
        new_enemy->setX(x);
        new_enemy->setY(y);
        return new_enemy;
    }

// shared_ptr<Enemy> BossFactory::createEnemy(IMovementStrategy* strategy) override {
//     shared_ptr<Enemy> new_boss_ptr = make_shared<Boss>(strategy);
//     new_boss_ptr->setX(x);
//     new_boss_ptr->setY(y);

//     return new_boss_ptr;
// }

