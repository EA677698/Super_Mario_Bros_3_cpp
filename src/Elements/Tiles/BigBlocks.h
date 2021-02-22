//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_BIGBLOCKS_H
#define SUPER_MARIO_BROS_3_C_BIGBLOCKS_H
#include "Tile.h"
#include "Adjustables.h"
#include "LayeredTile.h"
#include "../../Settings/Controls.h"

class BigBlocks : public Tile, public Adjustables, public LayeredTile {

private:
    int type;
    int extraYLayers,extraXLayers;
    Clock timerX, timerY;
    Time elapsed;

public:

    BigBlocks(Layer layer, Point location, bool collision, int type, int rows, int columns);
    void tick();
    void changeLength();
    void changeHeight();
    Sprite getTypeTextures();

    void calculateTileLayers() override;

    void to_string();

    int getType() const;

    void setType(int type);

    int getExtraYLayers() const;

    void setExtraYLayers(int extraYLayers);

    int getExtraXLayers() const;

    void setExtraXLayers(int extraXLayers);


};

#endif //SUPER_MARIO_BROS_3_C_BIGBLOCKS_H
