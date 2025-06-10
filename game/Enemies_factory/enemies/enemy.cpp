//
// Created by Adeline on 05/06/2025.
//
#include <iostream>

#include "enemy.hpp"
#include "../movements/imovementstrategy.hpp"


using std::cout;
using std::endl;

Enemy::Enemy(IMovementStrategy* movement) : movement_strategy(movement)
{
    cout<<"Je suis un ennemi classique"<<endl;
    cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
    cout<<this->getSpeed()<<" de vitesse"<<endl;
    cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}

Enemy::~Enemy() {
    delete movement_strategy;
}

void Enemy::move()
{
    if (movement_strategy)
        movement_strategy->move(*this);
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

void Enemy::setSpeed(float percent)
{
    this->speed = this->speed * (percent/100.0f);
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
