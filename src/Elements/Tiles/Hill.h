//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_HILL_H
#define SUPER_MARIO_BROS_3_C_HILL_H
#include "Tile.h"
#include "LayeredTile.h"
#include "Adjustables.h"


class Hill : public Tile, public LayeredTile, public Adjustables {

private:
    int type;
    int blocks;
    Clock timer;
    Time elapsed;
public:
    int getType() const;
    void setType(int type);
    int getBlocks() const;
    void setBlocks(int blocks);
    Hill(Layer layer, Point location, bool collision, int type, int blocks);
    void tick();
    void changeHeight() override;
    void calculateTileLayers() override;
    Sprite get2DSprites() override;
    string to_string();

};


#endif //SUPER_MARIO_BROS_3_C_HILL_H
