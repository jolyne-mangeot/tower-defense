#include <iostream>
// #include "enemies/enemy.cpp"
// #include "enemies/tank.cpp"
// #include "enemies/flash.cpp"
// #include "enemies/boss.cpp"

#include "enemyfactories/enemyfactory.hpp"
#include "enemyfactories/tankfactory.hpp"
#include "enemyfactories/flashfactory.hpp"
#include "enemyfactories/bossfactory.hpp"
#include "movements/straightmovement.hpp"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{   
    cout<<"TESTING 123"<<endl;
    EnemyFactory* enemy_factory = new EnemyFactory();
    EnemyFactory* flash_factory = new FlashFactory();
    EnemyFactory* boss_factory = new BossFactory();
    EnemyFactory* tank_factory = new TankFactory();

    cout<<"### Je créé un ennemi normal : ###"<<endl;
    Enemy* standard = enemy_factory->createEnemy(new StraightMovement);
    cout<<endl<<endl;
    cout<<"### Je créé un ennemi rapide : ###"<<endl;
    Enemy* flash = flash_factory->createEnemy(new StraightMovement);
    cout<<endl<<endl;
    cout<<"### Je créé un tank : ###"<<endl;
    Enemy* tank = tank_factory->createEnemy(new StraightMovement);
    cout<<endl<<endl;
    cout<<"### Je créé un boss : ###"<<endl;
    Enemy* boss = boss_factory->createEnemy(new StraightMovement);
    
    cout<<endl;
    // enemy_f<<endlactory = new EnemyFactory;
    
    /* code */
    return 0;
}