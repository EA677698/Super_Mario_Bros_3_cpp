//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_LAYEREDTILE_H
#define SUPER_MARIO_BROS_3_C_LAYEREDTILE_H
#include <SFML/Graphics.hpp>
using namespace sf;

class LayeredTile {

public:
    LayeredTile();
    virtual void calculateTileLayers();
    virtual Sprite get2DSprites();

};


#endif //SUPER_MARIO_BROS_3_C_LAYEREDTILE_H
