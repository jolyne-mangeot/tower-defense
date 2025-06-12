#ifndef TANK_FACTORY_HPP
#define TANK_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/tank.hpp"

class TankFactory : public EnemyFactory {
public:
    TankFactory(const int x, const int y) : EnemyFactory(x, y) {}
    shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override {
        return make_shared<Tank>(strategy, x, y);
    }
};

#endif // TANK_FACTORY_HPP
