//
// Created by Adeline on 05/06/2025.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "level_utils.hpp"

class IMovementStrategy; 
class Enemy {
public:
    Enemy(IMovementStrategy* movement, float x, float y);
    ~Enemy();
    weak_ptr<Level_core> level_ptr;
    weak_ptr<Enemy> self_ptr;
    int current_following_checkpoint{1};
    int revenue{80};
    virtual int move();
    void set_level_ptr(const weak_ptr<Level_core> &level_ptr);
    void takeDamage(int damage);
    float getHp() const;
    void setHp(float percent);
    float getSpeed() const;
    void initSpeed(float percent);
    void setSpeed(float new_speed);
    int getX() const;
    void setX(int x_movement);
    int getY() const;
    void setY(int y_movement);
    void setMovement(IMovementStrategy* new_movement_strategy);
    void die() const;

    virtual void presentYourself();

private:
    int health_points{100};
    int x{0}, y{0};
    float speed{50.0f}; // pixel per frame
    IMovementStrategy* movement_strategy;
    void changeDirection(array<int, 2> checkpoint);
};

#endif //ENEMY_H
