//
// Created by josur on 05/06/2025.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
public:
    Enemy(int hp, float speed, int reward);
    ~Enemy();

    void Move(); // Pas d'implémentation réelle, c'est pour le principe
    void TakeDamage(int dmg);
    bool IsDead() const;
    int GetReward() const;

private:
    void Die();

    int health;
    float speed;
    int moneyReward;
    bool dead;
};

#endif
