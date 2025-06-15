#ifndef FLASH_FACTORY_HPP
#define FLASH_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/enemy.hpp"
#include "flash.hpp"

class EnemyFactory;
class Enemy;

class FlashFactory : public EnemyFactory {
public:
    FlashFactory(const float x, const float y) : EnemyFactory(x, y) {}

    shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override {
        shared_ptr<Enemy> new_flash_ptr = make_shared<Flash>(strategy, x, y);
        return new_flash_ptr;
    }
};

#endif // FLASH_FACTORY_HPP
