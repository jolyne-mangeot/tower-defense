#ifndef MOVEMENTSTRATEGY_HPP
#define MOVEMENTSTRATEGY_HPP
#include <array>

class Enemy;

class IMovementStrategy {
public:
    virtual ~IMovementStrategy() = default;
    virtual void move(Enemy& enemy, const std::array<int, 2>& checkpoint) = 0;
};

#endif // MOVEMENTSTRATEGY_HPP
