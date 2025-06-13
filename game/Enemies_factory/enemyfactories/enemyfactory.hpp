#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

// class IMovementStrategy;
// class Enemy;

#include "enemy.hpp"


class EnemyFactory {
public:
    int x{0};
    int y{50};
    EnemyFactory() = default;

    virtual ~EnemyFactory() = default;

    virtual Enemy* createEnemy(IMovementStrategy* strategy);

    // virtual shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy);
};

#endif
