#include "tower.h"
#include <iostream>
#include <cmath>
#include "atomicTower.h"
#include "enemy.h"

using std::cout;
using std::endl;

int Tower::spent_money_count = 0;

void Tower::buy()
{
    spent_money_count += cost;
    std::cout << "Tour achetée pour : " << cost << "credits. \nTotal dépensé : "
              << spent_money_count << " \n";
}

void Tower::attack(Enemy *enemy)

{
    std::cout << " Déclenchement attaque Tour normal.\n"
              << std::endl;
}

void Tower::special_attack(Enemy *enemy)
{
    std::cout << "Declenchement attaque spéciale\n"
              << std::endl;
}

bool Tower::isInRange(float enemyX, float enemyY, float towerX, float towerY)
{
    return (std::abs(enemyX - towerX) <= perimeter && std::abs(enemyY - towerY) <= perimeter);
}

void Tower::upgrade()
{
    std::cout << "Amélioration de ma tour.\n";
}
