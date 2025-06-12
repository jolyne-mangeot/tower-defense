//
// Created by Adeline on 05/06/2025.
//
#include <iostream>

#include "enemy.hpp"
#include "../movements/imovementstrategy.hpp"
#include "../movements/upmovement.hpp"
#include "../movements/downmovement.hpp"
#include "../movements/leftmovement.hpp"
#include "../movements/rightmovement.hpp"

using std::cout;
using std::endl;

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

void Enemy::set_level_ptr(const weak_ptr<Level_core> &level_ptr) {
    this->level_ptr = level_ptr;
}

int Enemy::move()
{
    const float usual_speed = this->speed;
    changeDirection(level_ptr.lock()->checkpoints_coordinates.at(current_following_checkpoint));
    int movement_status = -1;
    if (movement_strategy) {
        movement_status = movement_strategy->move(*this, level_ptr.lock()->checkpoints_coordinates.at(current_following_checkpoint));
    }
    
    if (this->speed != usual_speed) {
        setSpeed(usual_speed);
    }

    if (current_following_checkpoint >= level_ptr.lock()->number_of_checkpoints) {
        movement_status = 5;
    }

    return movement_status;
}

void Enemy::takeDamage(const int damage) {
    this->health_points -= damage;
    if (health_points < 0) {
        die();
    }
}

void Enemy::die() const {
    level_ptr.lock()->current_wave_pointer->enemy_slayed(self_ptr);
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

int Enemy::getX() const {
    return this->x;
}

void Enemy::setX(const int x_movement)
{
    this->x += x_movement;
}

int Enemy::getY() const {
    return this->y;
}

void Enemy::setY(const int y_movement)
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

void Enemy::presentYourself()
{
    cout<<"Je suis un ennemi classique"<<endl;
    cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
    cout<<this->getSpeed()<<" de vitesse"<<endl;
    cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
