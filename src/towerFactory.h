#ifndef TOWERFACTORY_H
#define TOWERFACTORY_H

#include <iostream>
#include "tower.h"
#include "AtomicTower.h"
#include "CrazyTower.h"

enum TowerType
{
    ATOMIC,
    CRAZY
};

class TowerFactory
{
public:
    static Tower *createTower(TowerType type);
};

#endif
