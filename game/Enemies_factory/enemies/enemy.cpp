//
// Created by Adeline on 05/06/2025.
//
#include <iostream>

#include "../enemies/enemy.hpp"
#include "../movements/imovementstrategy.hpp"
#include "../movements/upmovement.hpp"
#include "../movements/downmovement.hpp"
#include "../movements/leftmovement.hpp"
#include "../movements/rightmovement.hpp"

using std::cout;
using std::endl;

Enemy::Enemy(
    IMovementStrategy* movement) :
        movement_strategy(movement)
{
    cout<<"Constructeur Enemy"<<endl;
}

Enemy::~Enemy() {
    delete movement_strategy;
}

void Enemy::set_type_id(const int id) {
    this->enemy_type_id = id;
}


int Enemy::move(const vector<array<int,2>>& checkpoints)
{
    const float usual_speed = this->speed;
    // changeDirection(checkpoints_coordinates.lock()->at(current_following_checkpoint));
    changeDirection(checkpoints);
    int movement_status = -1;
    if (this->movement_strategy) {
        movement_status = movement_strategy->move(*this, checkpoints.at(this->index));
    }
    
    if (this->speed != usual_speed) {
        setSpeed(usual_speed);
    }

    if (this->index >= checkpoints.size()) {
        movement_status = 5;
    }

    return movement_status;
}

void Enemy::takeDamage(const int damage) {
    this->health_points -= damage;
    // if (health_points < 0) {
    //     die();
    // }
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

// void Enemy::changeDirection(const std::array<int, 2> checkpoint)
void Enemy::changeDirection(const vector<array<int,2>>& checkpoints)
{   
    if (checkpoints.at(this->index).at(0) == this->x && checkpoints.at(this->index).at(1) == this->y) {
        this->index++;
    }

    if (checkpoints.at(this->index).at(0) < this->x) {
        this->movement_strategy = new LeftMovement;
    } else if (checkpoints.at(this->index).at(0) > this->x) {
        this->movement_strategy = new RightMovement;
    } else if (checkpoints.at(this->index).at(1) > this->y) {
        this->movement_strategy = new UpMovement;
    } else if (checkpoints.at(this->index).at(1) < this->y) {
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
