//
// Created by Adeline on 05/06/2025.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "utils.hpp"

class IMovementStrategy;

class Enemy {
public:
    Enemy(IMovementStrategy* movement, float x, float y);
    ~Enemy();
    weak_ptr<Enemy> self_ptr;
    int enemy_type_id{0};
    bool enemy_spawned{false};
    int current_following_checkpoint{1};
    int revenue{80};
    int health_points{100};
    virtual int move(const vector<array<int,2>>& checkpoints);
    void set_type_id(int id);
    void takeDamage(int damage);
    float getHp() const;
    void setHp(float percent);
    float getSpeed() const;
    void initSpeed(float percent);
    void setSpeed(float new_speed);
    float getX() const;
    void setX(float x_movement);
    float getY() const;
    void setY(float y_movement);
    void setMovement(IMovementStrategy* new_movement_strategy);

    virtual void presentYourself();

private:
    float x{0}, y{0};
    float speed{0.005f}; // pixel per frame
    IMovementStrategy* movement_strategy;
    void changeDirection(array<int, 2> checkpoint);
};

#endif //ENEMY_H
