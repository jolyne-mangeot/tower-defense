#include "tower.h"

void Tower::buy()
{
    spent_money_count += cost;
    cout << "Tour achetée pour : " << cost << "credits. \nTotal dépensé : "
              << spent_money_count << " \n";
}

void Tower::attack(Enemy *enemy)
{
    cout << " Déclenchement attaque Tour normal.\n"
              << endl;
}

void Tower::special_attack(Enemy *enemy)
{
    cout << "Declenchement attaque spéciale\n"
              << endl;
}

bool Tower::isInRange(float enemyX, float enemyY, float towerX, float towerY)
{
    return (abs(enemyX - towerX) <= perimeter && abs(enemyY - towerY) <= perimeter);
}

void Tower::upgrade()
{
    cout << "Amélioration de ma tour.\n";
}
