//
// Created by Adeline on 05/06/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

class IMovementStrategy; 
class Enemy {
public:
    Enemy(IMovementStrategy* movement);
    int revenue{80};
    virtual void move();
    void getDamage(int damage);
    float getHp();
    void setHp(float percent);
    float getSpeed();
    void setSpeed(float percent);
    int getX();
    void setX(int x_movement);
    int getY();
    void setY(int y_movement);

private:
    int health_points{100};
    int x{0}, y{0};
    float speed{50.0f}; // pixel per frame
    IMovementStrategy* movement_strategy;
};

#endif //ENEMY_H
