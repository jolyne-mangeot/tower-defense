//
// Created by josur on 06/06/2025.
//

#include "Basic_enemy.hpp"

extern "C" {

    __declspec(dllexport) Enemy* CreateEnemy(int hp, float speed, int reward) {
        return new Enemy(hp, speed, reward);
    }

    __declspec(dllexport) void DestroyEnemy(Enemy* enemy) {
        delete enemy;
    }

    __declspec(dllexport) void EnemyMove(Enemy* enemy) {
        if (enemy) enemy->Move();
    }

    __declspec(dllexport) void EnemyTakeDamage(Enemy* enemy, int dmg) {
        if (enemy) enemy->TakeDamage(dmg);
    }

    __declspec(dllexport) bool EnemyIsDead(Enemy* enemy) {
        return enemy ? enemy->IsDead() : true;
    }

    __declspec(dllexport) int EnemyGetReward(Enemy* enemy) {
        return enemy ? enemy->GetReward() : 0;
    }
}
