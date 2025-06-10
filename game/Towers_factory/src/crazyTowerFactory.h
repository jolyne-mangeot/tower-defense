
// CrazyTowerFactory.h
#ifndef CRAZYTOWERFACTORY_H
#define CRAZYTOWERFACTORY_H

#include "TowerFactory.h"
#include "CrazyTower.h"

class CrazyTowerFactory : public TowerFactory
{
public:
    Tower *createTower() override
    {
        // Tower *tower = new CrazyTower();

        return new CrazyTower();
        }
};

#endif