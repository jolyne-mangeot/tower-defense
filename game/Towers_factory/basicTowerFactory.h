// CrazyTowerFactory.h
#ifndef BASICTOWERFACTORY_H
#define BASICTOWERFACTORY_H
#include "tower.h"
#include "TowerFactory.h"
// #include "basicTower.h"


class BasicTowerFactory : public TowerFactory
{
public:
    virtual Tower *createTower() = 0;
    virtual ~BasicTowerFactory() = default;

};

#endif
