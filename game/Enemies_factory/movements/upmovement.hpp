#ifndef UPMOVEMENT_HPP
#define UPMOVEMENT_HPP

#include <array>
#include "IMovementStrategy.hpp"

class IMovementStrategy;
class Enemy;

class UpMovement : public IMovementStrategy {
public:
    int move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
