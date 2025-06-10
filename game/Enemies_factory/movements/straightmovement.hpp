#ifndef STRAIGHTMOVEMENT_HPP
#define STRAIGHTMOVEMENT_HPP

#include "IMovementStrategy.hpp"

class StraightMovement : public IMovementStrategy {
public:
    void move(Enemy& enemy) override;
};

#endif
