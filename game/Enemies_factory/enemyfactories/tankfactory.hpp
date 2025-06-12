#ifndef TANK_FACTORY_HPP
#define TANK_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/tank.hpp"

class TankFactory : public EnemyFactory {
public:
    Enemy* createEnemy(IMovementStrategy* strategy) override {
        return new Tank(strategy);
    }
};

#endif // TANK_FACTORY_HPP
