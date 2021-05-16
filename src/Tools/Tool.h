//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_TOOL_H
#define SUPER_MARIO_BROS_3_C_TOOL_H
#include "../Elements/Tiles/Tile.h"
#include "../Elements/Tiles/Adjustables.h"
#include "../Elements/Tiles/LayeredTile.h"

class Tool : public Tile, public Adjustables, public LayeredTile {

private:
    int middleBlocks, layers;
    Clock timerX,timerY;

public:
    Tool(Layer layer, Point location, bool collision, int middleBlocks, int layers, Global global);
    void tick();
    void changeLength() override;
    void changeHeight() override;
    void calculateTileLayers() override;
    void to_string();

};


#endif //SUPER_MARIO_BROS_3_C_TOOL_H
