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

Enemy::Enemy(IMovementStrategy* movement) : movement_strategy(movement)
{
    cout<<"Constructeur Enemy"<<endl;
}

Enemy::~Enemy() {
    delete movement_strategy;
}

void Enemy::move(std::array<int, 2>& checkpoint)
{
    float usual_speed = this->speed;
    changeDirection(checkpoint);
    if (movement_strategy) {
        movement_strategy->move(*this, checkpoint);
    }
    
    if (this->speed != usual_speed) {
        setSpeed(usual_speed);
    }
    
}

void Enemy::takeDamage(const int damage) {
    this->health_points -= damage;
}

float Enemy::getHp()
{
    return this->health_points;
}

void Enemy::setHp(float percent)
{   
    this->health_points = this->health_points * (percent/100.0f);
}

float Enemy::getSpeed()
{
    return this->speed;
}

void Enemy::initSpeed(float percent)
{
    this->speed = this->speed * (percent/100.0f);
}

void Enemy::setSpeed(float new_speed)
{
    this->speed = new_speed;
}

int Enemy::getX()
{
    return this->x;
}

void Enemy::setX(int x_movement)
{
    this->x += x_movement;
}

int Enemy::getY()
{
    return this->y;
}

void Enemy::setY(int y_movement)
{
    this->y += y_movement;
}

void Enemy::setMovement(IMovementStrategy *new_movement_strategy)
{
    this->movement_strategy = new_movement_strategy;
}

void Enemy::presentYourself()
{
    cout<<"Je suis un ennemi classique"<<endl;
    cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
    cout<<this->getSpeed()<<" de vitesse"<<endl;
    cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}

void Enemy::changeDirection(std::array<int, 2> checkpoint)
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
