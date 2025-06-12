#ifndef LEFTMOVEMENT_HPP
#define LEFTMOVEMENT_HPP
#include <array>
#include "IMovementStrategy.hpp"

class LeftMovement : public IMovementStrategy {
public:
    void move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
