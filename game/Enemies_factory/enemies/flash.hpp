#ifndef FLASH_HPP
#define FLASH_HPP

// #include "enemy.hpp"
#include "../enemies/enemy.hpp"
#include "../movements/imovementstrategy.hpp"

class Flash : public Enemy {
public:
    Flash(IMovementStrategy* strategy);
    void presentYourself();
};


#endif
