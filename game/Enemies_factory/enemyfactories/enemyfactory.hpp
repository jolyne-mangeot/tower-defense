#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include "enemy.hpp"
#include "imovementstrategy.hpp"

class EnemyFactory {
public:
    int x;
    int y;
    weak_ptr<Level_core> level;
    EnemyFactory(const int x, const int y) : x(x), y(y) {};
    void set_level_ptr(const weak_ptr<Level_core> &level) {
        this->level = level;
    }
    virtual ~EnemyFactory() = default;

    virtual shared_ptr<Enemy> createEnemy(IMovementStrategy* strategy) {
        shared_ptr<Enemy> new_enemy = make_shared<Enemy>(strategy, x, y);
        new_enemy->set_level_ptr(level); // comment when back-end debugging
        return new_enemy;
    }
};

#endif
