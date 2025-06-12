//
// Created by Adeline on 05/06/2025.
//
#include <array>
#ifndef ENEMY_H
#define ENEMY_H

class IMovementStrategy; 
class Enemy {
public:
    Enemy(IMovementStrategy* movement);
    ~Enemy();
    int revenue{80};
    virtual void move(std::array<int, 2>& checkpoint);
    void takeDamage(int damage);
    float getHp();
    void setHp(float percent);
    float getSpeed();
    void initSpeed(float percent);
    void setSpeed(float new_speed);
    int getX();
    void setX(int x_movement);
    int getY();
    void setY(int y_movement);
    void setMovement(IMovementStrategy* new_movement_strategy);

    virtual void presentYourself();

private:
    int health_points{100};
    int x{0}, y{0};
    float speed{50.0f}; // pixel per frame
    IMovementStrategy* movement_strategy;
    void changeDirection(std::array<int, 2> checkpoint);
};

#endif //ENEMY_H
