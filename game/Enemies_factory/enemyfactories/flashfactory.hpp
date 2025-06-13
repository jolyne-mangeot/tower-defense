#ifndef FLASH_FACTORY_HPP
#define FLASH_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/enemy.hpp"
#include "flash.hpp"

class EnemyFactory;
class Enemy;

class FlashFactory : public EnemyFactory {
public:
    FlashFactory() = default;

    virtual Enemy* createEnemy(IMovementStrategy* strategy);
    // shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override;

};

#endif // FLASH_FACTORY_HPP
