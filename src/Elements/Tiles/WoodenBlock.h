//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_WOODENBLOCK_H
#define SUPER_MARIO_BROS_3_C_WOODENBLOCK_H
#include "Tile.h"

class WoodenBlock : public Tile {

private:
    Texture texture;
    Sprite sprite;

public:
    WoodenBlock(Layer layer, Point location, bool collision);
    Sprite getSprite();

};


#endif //SUPER_MARIO_BROS_3_C_WOODENBLOCK_H
