// Tower.h
#ifndef TOWER_H
#define TOWER_H

class Enemy; // Forward declaration

class Tower
{
protected:
    static int spent_money_count; // tower_number_bought
    int damage;
    int tower_level;
    int cost;
    float shot_speed;
    float perimeter{20.0f};
    int hit_counter; 
    bool special_ready;
    

public:
    int x{0}, y{0};
    virtual void attack(Enemy *enemy);
    virtual void special_attack(Enemy *enemy);
    virtual void buy();
    // virtual bool isInRange(float enemyX, float enemyY, float towerX, float towerY);
    virtual bool isInRange(Enemy* enemy);
    virtual void upgrade();
    virtual ~Tower() = default;
};

#endif