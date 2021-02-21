//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_FIREBALL_H
#define SUPER_MARIO_BROS_3_C_FIREBALL_H
#include "NonLiving.h"

class Fireball : public NonLiving{

private:
    Clock timer,moveTimer,hitTimer;
    Time elapsed;


public:
    Fireball(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision);
    void executeUponTouch(Player player);
    void tick();
    void death();
    Sprite getSprite();



};


#endif //SUPER_MARIO_BROS_3_C_FIREBALL_H
