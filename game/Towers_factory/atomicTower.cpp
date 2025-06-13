#include "AtomicTower.h"
// #include "enemy.h"
#include "../Enemies_factory/enemies/enemy.hpp"

using std::cout;
using std::endl;

// Initialisation du compteur
int AtomicTower::atomic_tower_count = 0;

AtomicTower::AtomicTower()
{
    damage = 80;
    cost = base_cost; // see in buy()
    shot_speed = 1.5f;
    // perimeter = 5.0f;
    perimeter = 20.0f;
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

    if (isInRange(enemy)) // observer should take care of it to activate tower and then attack
    {
        std::cout << "\t\tBOOM Déclenchement attaque Tour ATOMIC.\n";
        enemy->takeDamage(this->damage);
        std::cout<<"\t\tHP enemy : "<<enemy->getHp()<<endl;
        hit_counter++;
        if (hit_counter >= 3) {
            special_ready = true;
            std::cout << "\t\tBOOM Déclenchement attaque speciale Tour CRAZY.\n";

            if(special_ready){
                special_attack(enemy);
                special_ready = false;
                hit_counter = 0;
            }
        }
        
    } 
}
    // std::cout << "AtomicTower attaque avec la puissance de Shadow\n";
    // enemy->takeDamage(80);

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
    shot_speed *= 1.1f;
    perimeter += 1.0f;

    cost = static_cast<int>(cost * 1.5f);

    cout << "AtomicTower améliorée ! Dégâts: " << damage << ", Vitesse: " << shot_speed
         << ", Périmètre: " << perimeter << ", Nouveau coût: " << cost << endl;
}
