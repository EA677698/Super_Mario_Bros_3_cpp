//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_FLOOR_H
#define SUPER_MARIO_BROS_3_C_FLOOR_H
#include "Tile.h"
#include "Adjustables.h"
#include "LayeredTile.h"
#include "../../Settings/Controls.h"

class Floor : public Tile, public Adjustables, public LayeredTile{

private:
    int middleBlocks,layers;
    Clock timerX, timerY;
    Time elapsed;

public:

    Floor(Layer layer, Point location, bool collision, int middleBlocks, int layers);
    void tick();
    void changeLength() override;
    void changeHeight() override;
    Sprite getSprite();
    void calculateTileLayers() override;
    Sprite get2DSprites() override;
    string to_string();



};


#endif //SUPER_MARIO_BROS_3_C_FLOOR_H
