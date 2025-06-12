#ifndef DOWNMOVEMENT_HPP
#define DOWNMOVEMENT_HPP
#include <array>
#include "IMovementStrategy.hpp"

class DownMovement : public IMovementStrategy {
public:
    int move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
