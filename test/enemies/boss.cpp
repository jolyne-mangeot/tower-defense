#include "Boss.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Boss::Boss(IMovementStrategy* strategy)
    : Enemy(strategy) {
        this->setHp(250);
        this->setSpeed(120);
        this->revenue = static_cast<int>(this->revenue * 2.0f);

        cout<<"Je suis un boss"<<endl;
        cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
        cout<<this->getSpeed()<<" de vitesse"<<endl;
        cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
