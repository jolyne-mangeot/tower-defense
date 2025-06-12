#include "Boss.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Boss::Boss(IMovementStrategy* strategy, const int x, const int y)
    : Enemy(strategy, x, y) {
        this->setHp(250);
        this->initSpeed(120.0f);
        this->revenue = static_cast<int>(this->revenue * 2.0f);
        cout<<"Constructeur Boss"<<endl;
}

void Boss::presentYourself() {
    cout<<"Je suis un boss"<<endl;
    cout<<"J'ai "<<this->getHp()<<" HP"<<endl;
    cout<<this->getSpeed()<<" de vitesse"<<endl;
    cout<<"Je rapporte : "<<this->revenue<<" gold"<<endl;
}
