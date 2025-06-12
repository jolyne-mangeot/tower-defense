#ifndef FLASH_HPP
#define FLASH_HPP

#include "enemy.hpp"
#include "../movements/imovementstrategy.hpp"

class Flash : public Enemy {
public:
    Flash(IMovementStrategy* strategy, const int x, const int y);
    void presentYourself();
};


#endif
