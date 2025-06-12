#ifndef BOSS_FACTORY_HPP
#define BOSS_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/boss.hpp"

class BossFactory : public EnemyFactory {
public:
    Enemy* createEnemy(IMovementStrategy* strategy) override {
        return new Boss(strategy);
    }
};

#endif // BOSS_FACTORY_HPP
