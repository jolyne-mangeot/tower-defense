#include "TowerFactory.h"
#include <iostream>
#include "../Enemies_factory/enemyfactories/enemyfactory.hpp"
#include "../Enemies_factory/enemyfactories/bossfactory.hpp"
#include "../Enemies_factory/enemyfactories/flashfactory.hpp"
#include "../Enemies_factory/enemyfactories/tankfactory.hpp"
#include "../Enemies_factory/movements/upmovement.hpp"
#include "../Enemies_factory/movements/downmovement.hpp"
#include "../Enemies_factory/movements/leftmovement.hpp"
#include "../Enemies_factory/movements/rightmovement.hpp"
// #include "../Enemies_factory/enemies/enemy.hpp"
// #include "../Enemies_factory/enemies/boss.hpp"
// #include "../Enemies_factory/enemies/tank.hpp"
// #include "../Enemies_factory/enemies/flash.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    std::setlocale(LC_ALL, ".utf8");
    std::cout << "Création d'un ennemi...\n";
    // Enemy *enemy = new Enemy(2.0f, 2.0f);
    EnemyFactory* factory = new EnemyFactory;
    FlashFactory* flash_Factory = new FlashFactory;
    TankFactory* tank_factory = new TankFactory;

    Enemy* enemy = factory->createEnemy(new UpMovement);
    Enemy* flash = flash_Factory->createEnemy(new UpMovement);
    Enemy* tank = tank_factory->createEnemy(new UpMovement);

    Tower* tower = TowerFactory::createTower(ATOMIC);

   
    Tower* tower1 = TowerFactory::createTower(BASIC);
    Tower* tower2 = TowerFactory::createTower(CRAZY);
     Tower* tower3 = TowerFactory::createTower(BASIC);
    tower->x = 465;
    tower->y = 240;

    flash->setHp(400);
    flash->presentYourself();
    
    enemy->presentYourself();
    
    std::vector<std::array<int,2>> checkpoints;
    // for (int i = 0; i < 10; i++) {
    std::array<int, 2> checkpoint1{450, 50};
    std::array<int, 2> checkpoint2{450, 250};
    std::array<int, 2> checkpoint3{150, 250};
    std::array<int, 2> checkpoint4{150, 250};
    std::array<int, 2> checkpoint5{550, 250};
    std::array<int, 2> checkpoint6{550, 850};
    std::array<int, 2> checkpoint7{550, 250};
    std::array<int, 2> checkpoint8{480, 250};
    std::array<int, 2> checkpoint9{450, 50};
    std::array<int, 2> checkpoint10{450, 250};

    checkpoints.push_back(checkpoint1);
    checkpoints.push_back(checkpoint2);
    checkpoints.push_back(checkpoint3);
    checkpoints.push_back(checkpoint4);
    checkpoints.push_back(checkpoint5);
    checkpoints.push_back(checkpoint6);
    checkpoints.push_back(checkpoint7);
    checkpoints.push_back(checkpoint8);
    checkpoints.push_back(checkpoint9);
    checkpoints.push_back(checkpoint10);
    // }
    
    cout<<"Je déplace l'ennemi boss"<<endl;
    flash->setX(350);
    // cout<<"checkpoint visé x : "<<checkpoints[2][0]<<" y : "<<checkpoints[2][1]<<endl;
    cout<<"enemi x : "<<flash->getX()<<" enemi y : "<<flash->getY()<<endl;
    // cout<<"Je vérifie le point y de départ de l'ennemi : "<<flash->getY()<<endl;
    int count{0};
    for (std::array<int,2> actual_checkpoint : checkpoints) {
        cout<<"\tactual checkpoint : "<<actual_checkpoint[0]<<" "<<actual_checkpoint[1]<<endl;
        while(actual_checkpoint[0] != flash->getX() || actual_checkpoint[1] != flash->getY()) {
            
            flash->move(actual_checkpoint);
            tower->attack(flash);

            count++;
        }
    }
    std::cout << "Un ennemi est apparu aux coordonnées (" << enemy->getX() << ", " << enemy->getY() << ")\n";

   /* std::vector<Tower *> towers;
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
            if (tower->isInRange(enemy))
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
}*/

}