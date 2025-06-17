#include "Tank.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Tank::Tank(IMovementStrategy* strategy, const float x, const float y)
    : Enemy(strategy, x, y) {
        this->set_type_id(2);
        this->setHp(400.0f);
        this->initSpeed(75.0f);
        this->revenue = static_cast<int>(this->revenue * 1.3f);
        cout<<"Constructeur Tank"<<endl;
}
