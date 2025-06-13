
// CrazyTowerFactory.h
#ifndef BASICTOWERFACTORY_H
#define BASICTOWERFACTORY_H

#include "TowerFactory.h"
#include "basicTower.h"


class BasicTowerFactory : public BasicFactory
{
public:
    Tower *createTower() override
    {
        // Tower *tower = new CrazyTower();

        return new BasicTower();
        }
};

#endif