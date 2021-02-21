//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_GREENMUSHROOM_H
#define SUPER_MARIO_BROS_3_C_GREENMUSHROOM_H
#include "NonLiving.h"

class GreenMushroom : public NonLiving {


public:
    GreenMushroom(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision);
    GreenMushroom(Layer layer,Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity,bool hasCollision);
    GreenMushroom(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity,bool hasCollision);
    void executeUponTouch(Player player);
    void death();
    void tick();
    Sprite getSprite();

};


#endif //SUPER_MARIO_BROS_3_C_GREENMUSHROOM_H
