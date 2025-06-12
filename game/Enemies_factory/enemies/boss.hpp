#ifndef BOSS_HPP
#define BOSS_HPP

#include "../enemies/enemy.hpp"
#include "../movements/imovementstrategy.hpp"

class Boss : public Enemy {
public:
    Boss(IMovementStrategy* strategy);
    void presentYourself() override;
};

#endif
