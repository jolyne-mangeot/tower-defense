
#include "flash.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Flash::Flash(IMovementStrategy* strategy)
    : Enemy(strategy) {
        this->setHp(80);
        this->setSpeed(150);
        this->revenue = static_cast<int>(this->revenue * 0.8f); 

        cout<<"Je suis rapide !"<<endl;
        cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
        cout<<this->getSpeed()<<" de vitesse"<<endl;
        cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
