#include "Boss.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Boss::Boss(IMovementStrategy* strategy, const float x, const float y)
    : Enemy(strategy, x, y) {
        this->set_type_id(3);
        this->setHp(750.0f);
        this->initSpeed(125.0f);
        this->revenue = static_cast<int>(this->revenue * 5.0f);
        cout<<"Constructeur Boss"<<endl;
}
