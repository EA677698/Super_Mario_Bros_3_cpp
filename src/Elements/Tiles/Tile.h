//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_TILE_H
#define SUPER_MARIO_BROS_3_C_TILE_H
#include "../Elements.h"
#include "../../Tools/HitBox.h"
#include <SFML/Graphics.hpp>

class Tile : public Elements {

protected:
    int width = 60;
    int height = 60;
    bool collision;
    HitBox hitBox;
    string tileName;
    int blocksPerLayer;

public:

    Tile(Layer layer, Point location, bool collision);

    void tick();

    void callingException();

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    bool isCollision() const;

    void setCollision(bool collision);

    const HitBox getHitBox() const;

    void setHitBox(const HitBox &hitbox);

    const string &getTileName() const;

    void setTileName(const string &tileName);

    int getBlocksPerLayer() const;

    void setBlocksPerLayer(int blocksPerLayer);



};


#endif //SUPER_MARIO_BROS_3_C_TILE_H
