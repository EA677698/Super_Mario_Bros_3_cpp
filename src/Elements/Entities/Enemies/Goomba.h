//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_GOOMBA_H
#define SUPER_MARIO_BROS_3_C_GOOMBA_H
#include "Enemy.h"

class Goomba : public Enemy {

private:
    sf::Clock one, two;
    sf::Time elapsed;

public:
    Goomba(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision, Global global);
    Goomba(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity, bool hasCollision, Global global);
    Goomba(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, Global global);
    void tick();
    void death();
    sf::Sprite getSprite();
};


#endif //SUPER_MARIO_BROS_3_C_GOOMBA_H
