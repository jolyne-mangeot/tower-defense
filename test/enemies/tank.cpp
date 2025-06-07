#include "Tank.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Tank::Tank(IMovementStrategy* strategy)
    : Enemy(strategy) {
        this->setHp(150);
        this->setSpeed(80);
        this->revenue = static_cast<int>(this-revenue * 1.2f);

        cout<<"Je suis un tank"<<endl;
        cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
        cout<<this->getSpeed()<<" de vitesse"<<endl;
        cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
