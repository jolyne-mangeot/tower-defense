#ifndef BOSS_FACTORY_HPP
#define BOSS_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/boss.hpp"

class BossFactory : public EnemyFactory {
public:
    BossFactory(const int x, const int y) : EnemyFactory(x, y) {}
    shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override {
        return make_shared<Boss>(strategy, x, y);
    }
};

#endif // BOSS_FACTORY_HPP
