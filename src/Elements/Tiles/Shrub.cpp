//
// Created by Erick on 2/20/2021.
//

#include "Shrub.h"

Shrub::Shrub(Elements::Layer layer, Point location, bool collision, Global global) : Tile(layer, location, collision, global) {
    setTileName("Shrub");
}

sf::Sprite Shrub::getSprites() {
    return sf::Sprite();
}
