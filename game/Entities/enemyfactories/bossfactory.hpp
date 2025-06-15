#ifndef BOSS_FACTORY_HPP
#define BOSS_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/boss.hpp"
#include "enemy.hpp"

class EnemyFactory;
class Enemy;

class BossFactory : public EnemyFactory {
public:
    BossFactory(const float x, const float y) : EnemyFactory(x, y) {}

    shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override {
        shared_ptr<Enemy> new_boss_ptr = make_shared<Boss>(strategy, x, y);
        return new_boss_ptr;
    }
};

#endif // BOSS_FACTORY_HPP
