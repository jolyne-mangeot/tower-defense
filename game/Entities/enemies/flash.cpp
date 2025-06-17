
#include "flash.hpp"
#include "../movements/imovementstrategy.hpp"
#include <iostream>

using std::cout;
using std::endl;

Flash::Flash(IMovementStrategy* strategy, const float x, const float y)
    : Enemy(strategy, x, y) {
        this->set_type_id(1);
        this->setHp(110.0f);
        this->initSpeed(350.0f);
        this->revenue = static_cast<int>(this->revenue * 1.1f);
        cout<<"Constructeur Flash"<<endl;     
}
