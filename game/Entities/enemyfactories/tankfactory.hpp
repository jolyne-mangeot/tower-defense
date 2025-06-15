#ifndef TANK_FACTORY_HPP
#define TANK_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/enemy.hpp"
#include "tank.hpp"

class TankFactory : public EnemyFactory {
public:
    TankFactory(const float x, const float y) : EnemyFactory(x, y) {}

    shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override {
        shared_ptr<Enemy> new_tank_ptr = make_shared<Tank>(strategy, x, y);
        return new_tank_ptr;
    }
};

#endif // TANK_FACTORY_HPP
