
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
    static Tower *createTower(TowerType type)
    {
        Tower *tower = nullptr;

        switch (type)
        {
        case ATOMIC:
            tower = new AtomicTower();
            break;
        case CRAZY:
            tower = new CrazyTower();
            break;
        default:
            std::cout << "Type de tour inconnu !\n";
            return nullptr;
        }

        return tower; // on ne fait pas buy ici
    }
};

#endif