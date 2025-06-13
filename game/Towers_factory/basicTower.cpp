#include "BasicTower.h"
#include "../Enemies_factory/enemies/enemy.hpp"
#include <iostream>

using std::cout;
using std::endl;

int BasicTower::basic_tower_count = 0;

BasicTower::BasicTower()
{
    damage = 20; 
    cost = base_cost; 
    shot_speed = 1.5f;
    perimeter = 30.0f;
    hit_counter = 0;

}
void BasicTower::attack(Enemy *enemy) {
    if(isInRange(enemy)){
        std::cout << "\t\tBOOM Déclenchement attaque TourBasic.\n";
        enemy->takeDamage(this->damage);
        std::cout<<"\t\tHP enemy : "<<enemy->getHp()<<endl;
    }
}
void BasicTower::buy()
{
    basic_tower_count++;

    float multiplier = 1.0f + cost_multiplier * (basic_tower_count - 1);
    int final_cost = static_cast<int>(base_cost * multiplier);
    cost = final_cost;

    spent_money_count += final_cost;

    cout << "Basic Tour achetée pour " << final_cost << " unités. ";
    cout << "Total dépensé : " << spent_money_count << endl;
}

void BasicTower::upgrade()
{

    damage = static_cast<int>(damage * 1.3f);
    shot_speed *= 1.2f;
    perimeter += 0.5f;

    cost = static_cast<int>(cost * 1.4f);

    std::cout << "BasicTower améliorée ! Dégâts: " << damage
              << ", Vitesse: " << shot_speed
              << ", Périmètre: " << perimeter
              << ", Nouveau coût: " << cost << std::endl;
}

