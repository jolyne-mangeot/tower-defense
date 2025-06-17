#ifndef BOSS_HPP
#define BOSS_HPP

#include "../enemies/enemy.hpp"
#include "../movements/imovementstrategy.hpp"

class Enemy;
class Boss : public Enemy {
public:
    Boss(IMovementStrategy* strategy, float x, float y);
};

#endif
