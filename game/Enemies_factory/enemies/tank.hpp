#ifndef TANK_HPP
#define TANK_HPP
#include "../movements/imovementstrategy.hpp"
#include "enemy.hpp"

class Tank : public Enemy {
public:
    Tank(IMovementStrategy* strategy);
};

#endif
