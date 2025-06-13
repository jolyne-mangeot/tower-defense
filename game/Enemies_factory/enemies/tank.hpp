#ifndef TANK_HPP
#define TANK_HPP
#include "../movements/imovementstrategy.hpp"
#include "../enemies/enemy.hpp"

class Enemy;
class Tank : public Enemy {
public:
    Tank(IMovementStrategy* strategy, float x, float y);
    void presentYourself();
};

#endif
