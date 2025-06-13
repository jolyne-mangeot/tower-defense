#ifndef LEFTMOVEMENT_HPP
#define LEFTMOVEMENT_HPP

#include <array>
#include "IMovementStrategy.hpp"

class IMovementStrategy;
class Enemy;

class LeftMovement : public IMovementStrategy {
public:
    int move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
