#include "enemyfactory.hpp"

Enemy* EnemyFactory::createEnemy(IMovementStrategy* strategy) {
        Enemy* new_enemy = new Enemy(strategy);
        new_enemy->setX(x);
        new_enemy->setY(y);
        return new_enemy;
    }

// shared_ptr<Enemy> EnemyFactory::createEnemy(IMovementStrategy* strategy) override {
//     shared_ptr<Enemy> new_enemy_ptr = make_shared<Enemy>(strategy);
//     new_enemy_ptr->setX(x);
//     new_enemy_ptr->setY(y);

//     return new_enemy_ptr;
// }

