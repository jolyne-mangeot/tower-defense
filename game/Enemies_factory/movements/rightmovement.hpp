#ifndef RIGHTMOVEMENT_HPP
#define RIGHTMOVEMENT_HPP

#include <array>
#include "IMovementStrategy.hpp"

class IMovementStrategy;
class Enemy;

class RightMovement : public IMovementStrategy {
public:
    int move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
