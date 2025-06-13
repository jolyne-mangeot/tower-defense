#ifndef TANK_FACTORY_HPP
#define TANK_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/enemy.hpp"
#include "tank.hpp"

class TankFactory : public EnemyFactory {
public:
    TankFactory() = default;

    virtual Enemy* createEnemy(IMovementStrategy* strategy);

    // shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override;
};

#endif // TANK_FACTORY_HPP
