//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_ENEMY_H
#define SUPER_MARIO_BROS_3_C_ENEMY_H
#include "../Entity.h"

class Enemy : public Entity{

public:

    Enemy(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision);
    Enemy(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity, bool hasCollision);
    Enemy(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity, bool hasCollision);
    void death();
    Sprite getSprite();
    string to_string();
};


#endif //SUPER_MARIO_BROS_3_C_ENEMY_H
