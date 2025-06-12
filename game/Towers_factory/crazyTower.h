#ifndef CRAZYTOWER_H
#define CRAZYTOWER_H

#include "tower.h"
#include <iostream>

class CrazyTower : public Tower
{
private:
    static int crazy_tower_count;
    static constexpr float cost_multiplier = 0.15f;
    static constexpr int base_cost = 380;

public:
    CrazyTower();
    void attack(Enemy *enemy) override;
    void special_attack(Enemy *enemy) override;
    void buy() override;
    void upgrade() override;
};

#endif