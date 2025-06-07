#include "TowerFactory.h"

Tower *TowerFactory::createTower(TowerType type)
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
        std::cout << "Je connais pas cette tour !\n";
        return nullptr;
    }

    tower->buy(); // achète la tour directement ici

    return tower;
}
