//
// Created by Adeline on 05/06/2025.
//

#include "enemy.hpp"

#include "imovementstrategy.hpp"
#include "upmovement.hpp"
#include "downmovement.hpp"
#include "leftmovement.hpp"
#include "rightmovement.hpp"

Enemy::Enemy(
    IMovementStrategy* movement,
    const float x, const float y) :
        movement_strategy(movement),
        x(x), y(y)
{
    cout<<"Constructeur Enemy"<<endl;
}

Enemy::~Enemy() {
    delete movement_strategy;
}

void Enemy::set_type_id(const int id) {
    enemy_type_id = id;
}


int Enemy::move(const vector<array<int,2>>& checkpoints, float time_multiplicator)
{
    const float usual_speed = this->speed;

    setSpeed(this->speed * time_multiplicator);
    int movement_status = -1;

    if (x != checkpoints.at(checkpoints.size() -1).at(0)
        && y != checkpoints.at(checkpoints.size() - 1).at(1) ||
        current_following_checkpoint < checkpoints.size()) {

        changeDirection(checkpoints.at(current_following_checkpoint));
    }
    else {
        movement_status = 5;
    }

    if (movement_strategy && movement_status != 5) {
        movement_status = movement_strategy->move(*this, checkpoints.at(current_following_checkpoint));
    }

    if (this->speed != usual_speed) {
        setSpeed(usual_speed);
    }

    return movement_status;
}

void Enemy::takeDamage(const int damage) {
    this->health_points -= damage;
}

float Enemy::getHp() const {
    return this->health_points;
}

void Enemy::setHp(const float percent)
{   
    this->health_points = this->health_points * (percent/100.0f);
}

float Enemy::getSpeed() const {
    return this->speed;
}

void Enemy::initSpeed(const float percent)
{
    this->speed = this->speed * (percent/100.0f);
}

void Enemy::setSpeed(const float new_speed)
{
    this->speed = new_speed;
}

float Enemy::getX() const {
    return this->x;
}

void Enemy::setX(const float x_movement)
{
    this->x += x_movement;
}

float Enemy::getY() const {
    return this->y;
}

void Enemy::setY(const float y_movement)
{
    this->y += y_movement;
}

void Enemy::setMovement(IMovementStrategy *new_movement_strategy)
{
    this->movement_strategy = new_movement_strategy;
}

void Enemy::changeDirection(const std::array<int, 2> checkpoint)
{
    if (checkpoint[0] < this->x) {
        this->movement_strategy = new LeftMovement;
    } else if (checkpoint[0] > this->x) {
        this->movement_strategy = new RightMovement;
    } else if (checkpoint[1] > this->y) {
        this->movement_strategy = new UpMovement;
    } else if (checkpoint[1] < this->y) {
        this->movement_strategy = new DownMovement;
    }
}
