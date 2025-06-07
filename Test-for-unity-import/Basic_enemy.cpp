//
// Created by josur on 05/06/2025.
//

#include "Basic_enemy.hpp"
#include <iostream>

Enemy::Enemy(int hp, float spd, int reward)
    : health(hp), speed(spd), moneyReward(reward), dead(false) {}

Enemy::~Enemy() = default;

void Enemy::Move() {
    std::cout << "Enemy moves at speed " << speed << std::endl;
}

void Enemy::TakeDamage(int dmg) {
    if (dead) return;
    health -= dmg;
    std::cout << "Enemy takes " << dmg << " damage. HP left: " << health << std::endl;
    if (health <= 0) {
        Die();
    }
}

bool Enemy::IsDead() const {
    return dead;
}

int Enemy::GetReward() const {
    return moneyReward;
}

void Enemy::Die() {
    dead = true;
    std::cout << "Enemy has died!" << std::endl;
}
