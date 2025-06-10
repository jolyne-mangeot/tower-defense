#include "crazyTower.h"
#include "enemy.h"

using std::cout;
using std::endl;

// init Nb of towers
int CrazyTower::crazy_tower_count = 0;

CrazyTower::CrazyTower()
{
    damage = 40;
    cost = base_cost;
    shot_speed = 2.0f;
    perimeter = 3.5f;
    hit_counter = 0;
    special_ready = false;
}

void CrazyTower::attack(Enemy *enemy)
{
    enemy->takeDamage(40);
    cout << "CrazyTower attaque de manière imprévisible!\n";
}

void CrazyTower::special_attack(Enemy *enemy)
{
    cout << "CrazyTower a pété son cable!\n";
}

void CrazyTower::buy()
{
    crazy_tower_count++;

    float multiplier = 1.0f + cost_multiplier * (crazy_tower_count - 1);
    int final_cost = static_cast<int>(base_cost * multiplier);
    cost = final_cost;

    spent_money_count += final_cost;

    cout << "Crazy tour achetée pour " << final_cost << " unités. ";
    cout << "Total dépensé : " << spent_money_count << endl;
}

void CrazyTower::upgrade()
{

    damage = static_cast<int>(damage * 1.3f);
    shot_speed *= 1.2f;
    perimeter += 0.5f;

    cost = static_cast<int>(cost * 1.4f);

    std::cout << "CrazyTower améliorée ! Dégâts: " << damage
              << ", Vitesse: " << shot_speed
              << ", Périmètre: " << perimeter
              << ", Nouveau coût: " << cost << std::endl;
}
