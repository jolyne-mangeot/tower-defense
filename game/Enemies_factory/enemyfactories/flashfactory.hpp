#ifndef FLASH_FACTORY_HPP
#define FLASH_FACTORY_HPP

#include "enemyfactory.hpp"
#include "flash.hpp"

class FlashFactory : public EnemyFactory {
public:
    FlashFactory(const int x, const int y) : EnemyFactory(x, y) {}
    shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override {
        return make_shared<Flash>(strategy, x, y);
    }
};

#endif // FLASH_FACTORY_HPP
