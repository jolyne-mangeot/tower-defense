#ifndef UPMOVEMENT_HPP
#define UPMOVEMENT_HPP
#include <array>
#include "IMovementStrategy.hpp"

class UpMovement : public IMovementStrategy {
public:
    void move(Enemy& enemy, const std::array<int, 2>& checkpoint) override;
};

#endif
