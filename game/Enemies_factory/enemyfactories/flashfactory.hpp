#ifndef FLASH_FACTORY_HPP
#define FLASH_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/flash.hpp"

class FlashFactory : public EnemyFactory {
public:
    Enemy* createEnemy(IMovementStrategy* strategy) override {
        return new Flash(strategy);
    }
};

#endif // FLASH_FACTORY_HPP
