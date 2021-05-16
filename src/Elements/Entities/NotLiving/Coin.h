//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_COIN_H
#define SUPER_MARIO_BROS_3_C_COIN_H
#include "NonLiving.h"
#include "../../../Tools/GeneralTools.cpp"

class Coin : public NonLiving {

public:
    Coin(Layer layer, Point *coordinates, int width, int height, int direction, bool hasCollision, Global global);
    Coin(Layer layer, Point coordinates, int width, int height, int life, int damage, int direction, bool hasGravity, bool hasCollision, Global global);
    Coin(Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, Global global);
    void executeUponTouch(Player player) override;
    void death();
    Sprite getSprite();

};


#endif //SUPER_MARIO_BROS_3_C_COIN_H
