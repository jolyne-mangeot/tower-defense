
#include "flash.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Flash::Flash(IMovementStrategy* strategy, const float x, const float y)
    : Enemy(strategy, x, y) {
        this->set_type_id(1);
        this->setHp(80.0f);
        this->initSpeed(150.0f);
        this->revenue = static_cast<int>(this->revenue * 0.8f);
        cout<<"Constructeur Flash"<<endl;     
}

void Flash::presentYourself() {
    cout<<"Je suis rapide !"<<endl;
    cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
    cout<<this->getSpeed()<<" de vitesse"<<endl;
    cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
