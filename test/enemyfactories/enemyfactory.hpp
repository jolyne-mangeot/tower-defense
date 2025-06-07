#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

// #include <memory>
// #include <string>
// #include "enemy.hpp"

// class EnemyFactory {
// public:
//     static Enemy* createEnemy(IMovementStrategy* strategy);
// };

#include "enemy.hpp"
#include "../movements/imovementstrategy.hpp"

class EnemyFactory {
public:
    virtual ~EnemyFactory() = default;
    
    // Factory Method (note: still allows Standard enemy here)
    virtual Enemy* createEnemy(IMovementStrategy* strategy) {
        return new Enemy(strategy); // default behavior
    }
};



#endif
