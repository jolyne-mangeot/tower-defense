#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

// class IMovementStrategy;
// class Enemy;

#include "enemy.hpp"


class EnemyFactory {
public:
    float x;
    float y;
    EnemyFactory(const float x, const float y) : x(x), y(y) {};

    virtual ~EnemyFactory() = default;

    virtual shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) {
        shared_ptr<Enemy> new_enemy = make_shared<Enemy>(strategy, x, y);
        return new_enemy;
    }
};

#endif
