// TowerFactory.h
#ifndef CRAZYTOWERFACTORY_H
#define CRAZYTOWERFACTORY_H
#include "TowerFactory.h"
#include "tower.h"
// #include "crazyTower.h"

class CrazyTowerFactory : public TowerFactory {
public:
    virtual Tower* createTower() = 0;
    virtual ~CrazyTowerFactory() = default;
};

#endif
