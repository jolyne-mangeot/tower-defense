// AtomicTowerFactory.h
#ifndef ATOMICTOWERFACTORY_H
#define ATOMICTOWERFACTORY_H

#include "tower.h"
#include "towerFactory.h"

class AtomicTowerFactory : public TowerFactory
{
public:
    virtual Tower *createTower() = 0;
     virtual ~AtomicTowerFactory() = default;

};

#endif
