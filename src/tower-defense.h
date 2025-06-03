//
// Created by josur on 03/06/2025.
//

#ifndef TOWER_DEFENSE_H
#define TOWER_DEFENSE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

    class GDExample : public Sprite2D {
        GDCLASS(GDExample, Sprite2D)

    private:
        double time_passed;

    protected:
        static void _bind_methods();

    public:
        GDExample();
        ~GDExample();

        void _process(double delta) override;
    };

}

#endif //TOWER_DEFENSE_H
