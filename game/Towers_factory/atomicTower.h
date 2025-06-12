// AtomicTower.h
#ifndef ATOMICTOWER_H
#define ATOMICTOWER_H

#include "Tower.h"
#include <iostream>

class AtomicTower : public Tower
{
private:
    static int atomic_tower_count;                 // nb tower bought
    static constexpr float cost_multiplier = 0.2f; // +20 % per tower
    static constexpr int base_cost = 600;          // base cost

public:
    AtomicTower();
    void attack(Enemy *enemy) override;
    void special_attack(Enemy *enemy) override;
    void buy() override;
    void upgrade() override;
};

#endif
