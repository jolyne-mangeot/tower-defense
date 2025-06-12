#include "Tank.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Tank::Tank(IMovementStrategy* strategy, const int x, const int y)
    : Enemy(strategy, x, y) {
        this->setHp(150.0f);
        this->initSpeed(80.0f);
        this->revenue = static_cast<int>(this->revenue * 1.2f);
        cout<<"Constructeur Tank"<<endl;
}

void Tank::presentYourself() {
    cout<<"Je suis un tank"<<endl;
    cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
    cout<<this->getSpeed()<<" de vitesse"<<endl;
    cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
