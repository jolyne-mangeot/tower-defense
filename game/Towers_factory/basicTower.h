#ifndef BASIC_TOWER_H
#define BASIC_TOWER_H

#include "tower.h"
#include <iostream>

class BasicTower : public Tower {
private:
    static int basic_tower_count;
    static constexpr float cost_multiplier = 0.10f;
     static constexpr int base_cost = 0;

public :
    BasicTower();
    void attack(Enemy *enemy) override;
    void buy() override;
    void upgrade() override;
};

#endif
