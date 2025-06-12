#include "tower.h"
#include <iostream>
#include <cmath>
#include "atomicTower.h"
#include "../Enemies_factory/enemies/enemy.hpp"

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
    if (isInRange(enemy)) // observer should take care of it to activate tower and then attack
    {
        std::cout << "\t\tBOOM Déclenchement attaque Tour normal.\n";
        enemy->takeDamage(this->damage);}
        std::cout<<"\t\tHP enemy : "<<enemy->getHp()<<endl;
}

void Tower::special_attack(Enemy *enemy)
{
    std::cout << "Declenchement attaque spéciale\n"
              << std::endl;
}

bool Tower::isInRange(Enemy* enemy)
{
    return (std::abs(enemy->getX() - this->x) <= perimeter && std::abs(enemy->getY() - this->y) <= perimeter);
}

void Tower::upgrade()
{
    std::cout << "Amélioration de ma tour.\n";
}
