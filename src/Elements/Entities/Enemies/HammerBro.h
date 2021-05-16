//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_HAMMERBRO_H
#define SUPER_MARIO_BROS_3_C_HAMMERBRO_H
#include "Enemy.h"

class HammerBro : public Enemy {

private:
    int type;
    sf::Clock one,attackTimer;
    sf::Time elapsed;

public:
    HammerBro(Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision, int type, Global global);
    HammerBro(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity, bool hasCollision, int type, Global global);
    HammerBro(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, int type, Global global);
    void tick();
    void attack();
    sf::Sprite getSprite();
    int getType();
    void setType(int type);
    string to_String();
};


#endif //SUPER_MARIO_BROS_3_C_HAMMERBRO_H
