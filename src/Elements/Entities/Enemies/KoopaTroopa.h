//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_KOOPATROOPA_H
#define SUPER_MARIO_BROS_3_C_KOOPATROOPA_H
#include "Enemy.h"

class KoopaTroopa : public Enemy {

private:
    Clock one, two;
    Time elapsed;


public:
    KoopaTroopa(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision);
    KoopaTroopa(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity, bool hasCollision);
    KoopaTroopa(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity, bool hasCollision);
    void tick();
    void death();
    Sprite getSprite();

};


#endif //SUPER_MARIO_BROS_3_C_KOOPATROOPA_H
