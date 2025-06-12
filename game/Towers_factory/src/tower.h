// Tower.h
#ifndef TOWER_H
#define TOWER_H

#include "level_utils.hpp"

class Enemy; // Forward declaration

class Tower
{
protected:
    static int spent_money_count;
    int tower_level{0};
    int cost{150};
    int damage{0};
    float perimeter{0};
    int hit_speed{0};
    int hit_cooldown{0};
    int hit_counter{0};
    bool special_ready{false};

public:
    virtual void attack(Enemy *enemy);
    virtual void special_attack(Enemy *enemy);
    virtual void buy();
    virtual bool isInRange(float enemyX, float enemyY, float towerX, float towerY);
    virtual void upgrade();
    virtual ~Tower() = default;
};

#endif