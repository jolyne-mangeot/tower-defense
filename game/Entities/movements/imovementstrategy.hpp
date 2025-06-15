#ifndef MOVEMENTSTRATEGY_HPP
#define MOVEMENTSTRATEGY_HPP

#include <array>
#include "enemy.hpp"

class IMovementStrategy {
public:
    virtual ~IMovementStrategy() = default;
    virtual int move(Enemy& enemy, const std::array<int, 2>& checkpoint) = 0;
};

#endif // MOVEMENTSTRATEGY_HPP
