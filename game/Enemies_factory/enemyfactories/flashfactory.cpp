#include "flashfactory.hpp"

Enemy* FlashFactory::createEnemy(IMovementStrategy* strategy) {
        Enemy* new_enemy = new Flash(strategy);
        new_enemy->setX(x);
        new_enemy->setY(y);
        return new_enemy;
    }

// shared_ptr<Enemy> flashFactory::createEnemy(IMovementStrategy* strategy) override {
//     shared_ptr<Enemy> new_flash_ptr = make_shared<Flash>(strategy);
//     new_flash_ptr->setX(x);
//     new_flash_ptr->setY(y);

//     return new_flash_ptr;
// }

