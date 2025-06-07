// AtomicTowerFactory.h
#ifndef ATOMICTOWERFACTORY_H
#define ATOMICTOWERFACTORY_H

// #include "TowerFactory.h"
// #include "AtomicTower.h"
#include "tower.h"
#include "CrazyTower.h"

class AtomicTowerFactory : public TowerFactory
{
public:
    Tower *createTower() override
    {

        return new AtomicTower();
    }
};

#endif