#ifndef BOSS_FACTORY_HPP
#define BOSS_FACTORY_HPP

#include "enemyfactory.hpp"
#include "../enemies/boss.hpp"
#include "enemy.hpp"

class EnemyFactory;
class Enemy;

class BossFactory : public EnemyFactory {
public:
    BossFactory();

    virtual Enemy* createEnemy(IMovementStrategy* strategy);

    // shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) override;
};

#endif // BOSS_FACTORY_HPP
