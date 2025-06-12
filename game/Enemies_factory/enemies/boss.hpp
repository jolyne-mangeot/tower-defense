#ifndef BOSS_HPP
#define BOSS_HPP

#include "enemy.hpp"
#include "../movements/imovementstrategy.hpp"

class Boss : public Enemy {
public:
    Boss(IMovementStrategy* strategy, const int x, const int y);
    void presentYourself() override;
};

#endif
