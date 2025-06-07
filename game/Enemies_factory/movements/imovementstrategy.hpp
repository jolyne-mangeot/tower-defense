#ifndef MOVEMENTSTRATEGY_HPP
#define MOVEMENTSTRATEGY_HPP

class Enemy;

class IMovementStrategy {
public:
    virtual ~IMovementStrategy() = default;
    virtual void move(Enemy& enemy) = 0;
};

#endif // MOVEMENTSTRATEGY_HPP
