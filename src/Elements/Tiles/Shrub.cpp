//
// Created by Erick on 2/20/2021.
//

#include "Shrub.h"

Shrub::Shrub(Elements::Layer layer, Point location, bool collision) : Tile(layer, location, collision) {
    setTileName("Shrub");
}

Sprite Shrub::getSprites() {
    return Sprite();
}
