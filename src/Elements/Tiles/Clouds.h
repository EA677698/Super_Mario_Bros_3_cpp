//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_CLOUDS_H
#define SUPER_MARIO_BROS_3_C_CLOUDS_H
#include "Tile.h"
#include "LayeredTile.h"

class Clouds : public Tile, public LayeredTile {

private:
     int type;

public:
    Clouds(Layer layer, Point location, bool collision, int type, Global global);
    Sprite getSprites();
    void calculateTileLayers() override;
    string to_string();

};


#endif //SUPER_MARIO_BROS_3_C_CLOUDS_H
