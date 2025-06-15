
#include "tower.hpp"

Tower::Tower(const int x, const int y) : x(x), y(y) {}

void Tower::attack(Enemy *enemy)
{
    enemy->takeDamage(this->damage);
    hit_counter++;
    if (hit_counter >= special_charge) {
        special_ready = true;
    }
}

void Tower::special_attack(Enemy *enemy)
{
    enemy->takeDamage(damage * 2);
    special_ready = false;
    hit_counter = 0;
}

bool Tower::isInRange(const Enemy* enemy) const
{
    return (
        abs(enemy->getX() - static_cast<float>(this->x)) <= perimeter &&
        abs(enemy->getY() - static_cast<float>(this->y)) <= perimeter
    );
}

void Tower::buy_tower() {
    tower_level++;
}

void Tower::upgrade_tower()
{
    tower_level ++;
    damage *=2;
    shooting_speed *=2;
    perimeter +=1;
    special_charge -=1;
    hit_counter = 0;
    special_ready = false;
}
