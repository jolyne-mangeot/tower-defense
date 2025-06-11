#include <iostream>
// #include "enemies/enemy.cpp"
// #include "enemies/tank.cpp"
// #include "enemies/flash.cpp"
// #include "enemies/boss.cpp"

#include "enemyfactories/enemyfactory.hpp"
#include "enemyfactories/tankfactory.hpp"
#include "enemyfactories/flashfactory.hpp"
#include "enemyfactories/bossfactory.hpp"
// #include "movements/straightmovement.hpp"
#include "movements/upmovement.hpp"
#include "movements/downmovement.hpp"
#include "movements/leftmovement.hpp"
#include "movements/rightmovement.hpp"

#include <array>
#include <vector>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{   
    cout<<"TESTING 123"<<endl;
    EnemyFactory* enemy_factory = new EnemyFactory();
    EnemyFactory* flash_factory = new FlashFactory();
    EnemyFactory* boss_factory = new BossFactory();
    EnemyFactory* tank_factory = new TankFactory();

    // cout<<"### Je créé un ennemi normal : ###"<<endl;
    Enemy* standard = enemy_factory->createEnemy(new UpMovement);
    // cout<<endl<<endl;
    // cout<<"### Je créé un ennemi rapide : ###"<<endl;
    Enemy* flash = flash_factory->createEnemy(new UpMovement);
    // cout<<endl<<endl;
    // cout<<"### Je créé un tank : ###"<<endl;
    Enemy* tank = tank_factory->createEnemy(new UpMovement);
    // cout<<endl<<endl;
    // cout<<"### Je créé un boss : ###"<<endl;
    Enemy* boss = boss_factory->createEnemy(new UpMovement);
    
    cout<<endl;
    boss->presentYourself();
    tank->presentYourself();
    flash->presentYourself();
    standard->presentYourself();

    cout<<endl<<endl;

    std::vector<std::array<int,2>> checkpoints;
    // for (int i = 0; i < 10; i++) {
    std::array<int, 2> checkpoint1{450, 50};
    std::array<int, 2> checkpoint2{450, 250};
    std::array<int, 2> checkpoint3{150, 250};
    std::array<int, 2> checkpoint4{150, 250};
    std::array<int, 2> checkpoint5{550, 250};
    std::array<int, 2> checkpoint6{550, 850};

    checkpoints.push_back(checkpoint1);
    checkpoints.push_back(checkpoint2);
    checkpoints.push_back(checkpoint3);
    checkpoints.push_back(checkpoint4);
    checkpoints.push_back(checkpoint5);
    checkpoints.push_back(checkpoint6);
    // }
    
    cout<<"Je déplace l'ennemi standard"<<endl;
    standard->setX(150);
    cout<<"checkpoint visé x : "<<checkpoints[2][0]<<" y : "<<checkpoints[2][1]<<endl;
    cout<<"enemi x : "<<standard->getX()<<" enemi y : "<<standard->getY()<<endl;
    // cout<<"Je vérifie le point y de départ de l'ennemi : "<<standard->getY()<<endl;
    int count{0};
    for (std::array<int,2> actual_checkpoint : checkpoints) {
        cout<<"\tactual checkpoint : "<<actual_checkpoint[0]<<" "<<actual_checkpoint[1]<<endl;
        while(actual_checkpoint[0] != standard->getX() || actual_checkpoint[1] != standard->getY() && count <10) {
            standard->move(actual_checkpoint);
            count++;
        }

    }
   
    

    // enemy_f<<endlactory = new EnemyFactory;
    
    /* code */
    return 0;
}