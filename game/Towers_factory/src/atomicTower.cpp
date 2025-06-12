#include "AtomicTower.h"
#include "enemy.h"

using std::cout;
using std::endl;

// Initialisation du compteur
int AtomicTower::atomic_tower_count = 0;

AtomicTower::AtomicTower()
{
    damage = 80;
    cost = base_cost; // see in buy()
    hit_speed = 1.5f;
    perimeter = 5.0f;
    hit_counter = 0;
    special_ready = false;
}

void AtomicTower::buy()
{
    atomic_tower_count++;

    // Calcul du coût réel avec l’augmentation
    float multiplier = 1.0f + cost_multiplier * (atomic_tower_count - 1);
    int final_cost = static_cast<int>(base_cost * multiplier);
    cost = final_cost;

    spent_money_count += final_cost;

    cout << "Tour atomique achetée pour " << final_cost << " unités. ";
    cout << "Total dépensé : " << spent_money_count << endl;
}

void AtomicTower::attack(Enemy *enemy)
{
    std::cout << "AtomicTower attaque avec la puissance de Shadow\n";
    enemy->takeDamage(80);

    hit_counter++;
    if (hit_counter >= 3)
    {
        special_ready = true;
        std::cout << "L'attaque spéciale est maintenant prête !\n";
    }
}

void AtomicTower::special_attack(Enemy *enemy)
{
    if (special_ready)
    {
        cout << "AtomicTower lance une explosion atomique shadomique!\n";
        special_ready = false;
        hit_counter = 0;
    }
}
void AtomicTower::upgrade()
{

    damage = static_cast<int>(damage * 1.2f);
    hit_speed *= 1.1f;
    perimeter += 1.0f;

    cost = static_cast<int>(cost * 1.5f);

    cout << "AtomicTower améliorée ! Dégâts: " << damage << ", Vitesse: " << hit_speed
         << ", Périmètre: " << perimeter << ", Nouveau coût: " << cost << endl;
}
