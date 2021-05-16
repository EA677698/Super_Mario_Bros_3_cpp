//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_SHRUB_H
#define SUPER_MARIO_BROS_3_C_SHRUB_H
#include "Tile.h"

class Shrub : public Tile {

public:

    Shrub(Layer layer, Point location, bool collision, Global global);
    sf::Sprite getSprites();

};


#endif //SUPER_MARIO_BROS_3_C_SHRUB_H
