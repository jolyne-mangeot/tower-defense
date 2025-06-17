#ifndef TOWER_HPP
#define TOWER_HPP

#include "utils.hpp"
#include "enemy.hpp"
#include "User_data.hpp"

class Tower
{
protected:
    int damage{20};
    int tower_level{0};
    float shooting_speed{1};
    float perimeter{10.5f};
    int special_charge{5};

    int hit_counter{0};
    bool special_ready{false};

public:
    Tower(int x, int y);
    int x, y;
    void attack(Enemy *enemy);
    void special_attack(Enemy *enemy);
    bool isInRange(const Enemy* enemy) const;
    void buy_tower();
    void upgrade_tower();

    int get_hit_counter() const {
        return hit_counter;
    }

    int get_special_ready() const {
        return special_ready;
    }

    int get_level() const {
        return tower_level;
    }

    float get_shooting_speed() const {
        return shooting_speed;
    }

    int get_special_charge() const {
        return special_charge;
    }

    int get_damage() const {
        return damage;
    }
};

#endif