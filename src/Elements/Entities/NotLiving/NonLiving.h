//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_NONLIVING_H
#define SUPER_MARIO_BROS_3_C_NONLIVING_H
#include "../Entity.h"
#include "../Mario/Player.h"

class NonLiving : public Entity{

public:
    NonLiving(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision, Global global);
    NonLiving(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity, bool hasCollision, Global global);
    NonLiving(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, Global global);
    virtual void executeUponTouch(Player player);
    Sprite getSprite();
    string to_String();
};


#endif //SUPER_MARIO_BROS_3_C_NONLIVING_H
