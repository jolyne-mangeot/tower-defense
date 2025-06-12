#ifndef RIGHTMOVEMENT_HPP
#define RIGHTMOVEMENT_HPP
#include <array>
#include "IMovementStrategy.hpp"

class RightMovement : public IMovementStrategy {
public:
    void move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
