#include "TowerFactory.h"
#include <iostream>
#include "enemy.h"
#include <vector>

int main()
{
    std::cout << "Création d'un ennemi...\n";
    Enemy *enemy = new Enemy(2.0f, 2.0f);
    std::cout << "Un ennemi est apparu aux coordonnées (" << enemy->x << ", " << enemy->y << ")\n";

    std::vector<Tower *> towers;
    int choix = 0;

    while (choix != 4)
    {
        std::cout << "\n-- MENU --\n";
        std::cout << "1 Acheter une tour\n";
        std::cout << "2 Attaquer l'ennemi avec une tour\n";
        std::cout << "3 Faire évoluer une tour\n";
        std::cout << "4 Quitter\n";
        std::cout << " -- Choix : ";
        std::cin >> choix;

        switch (choix)
        {
        case 1:
        {
            std::cout << "Choisissez le type de tour à acheter :\n";
            std::cout << "1. Atomic Tower\n";
            std::cout << "2. Crazy Tower\n";
            std::cout << " -- Choix : ";
            int typeTour;
            std::cin >> typeTour;

            Tower *newTower = nullptr;
            if (typeTour == 1)
                newTower = TowerFactory::createTower(ATOMIC);
            else if (typeTour == 2)
                newTower = TowerFactory::createTower(CRAZY);
            else
            {
                std::cout << "Type de tour invalide.\n";
                break;
            }

            if (newTower)
            {
                // newTower->buy();
                towers.push_back(newTower);
                std::cout << "Tour achetée et ajoutée à votre arsenal.\n";
            }
            else
            {
                std::cout << "Impossible d'acheter cette tour.\n";
            }
            break;
        }
        case 2:
        {
            if (towers.empty())
            {
                std::cout << "Vous n'avez pas de tours pour attaquer.\n";
                break;
            }
            std::cout << "Choisissez la tour avec laquelle attaquer (index 0 à " << towers.size() - 1 << ") : ";
            int idx;
            std::cin >> idx;
            if (idx < 0 || idx >= (int)towers.size())
            {
                std::cout << "Index invalide.\n";
                break;
            }

            Tower *tower = towers[idx];
            std::cout << "On regarde si l'ennemi est à portée du viseur...\n";
            if (tower->isInRange(enemy->x, enemy->y, 0, 0))
            {
                std::cout << "L'ennemi est en portée, on tire !\n";
                for (int i = 0; i < 3; i++)
                {
                    std::cout << "Attaque enclenchée " << (i + 1) << "\n";
                    tower->attack(enemy);
                }
                tower->special_attack(enemy);
            }
            else
            {
                std::cout << "Pas de chance. L'ennemi s'enfuit. On est trop nul.\n";
            }
            break;
        }
        case 3:
        {
            if (towers.empty())
            {
                std::cout << "Vous n'avez pas de tours pour évoluer.\n";
                break;
            }
            std::cout << "Choisissez la tour à faire évoluer (index 0 à " << towers.size() - 1 << ") : ";
            int idx;
            std::cin >> idx;
            if (idx < 0 || idx >= (int)towers.size())
            {
                std::cout << "Index invalide.\n";
                break;
            }

            Tower *tower = towers[idx];
            tower->upgrade(); // Appelle directement upgrade()
            std::cout << "Tour évoluée !\n";

            break;
        }
        case 4:
            std::cout << "Merci d'avoir joué !\n";
            break;
        default:
            std::cout << "Choix invalide, merci de choisir entre 1 et 4.\n";
        }
    }

    // Nettoyage mémoire
    for (auto t : towers)
        delete t;
    delete enemy;

    return 0;
}