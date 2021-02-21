//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_REDMUSHROOM_H
#define SUPER_MARIO_BROS_3_C_REDMUSHROOM_H
#include "NonLiving.h"

class RedMushroom : public NonLiving {


public:

    RedMushroom(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision);
    RedMushroom(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity,bool hasCollision);
    RedMushroom(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity,bool hasCollision);
    void executeUponTouch(Player player) override;
    void tick();
    void death();
    Sprite getSprite();

};


#endif //SUPER_MARIO_BROS_3_C_REDMUSHROOM_H
