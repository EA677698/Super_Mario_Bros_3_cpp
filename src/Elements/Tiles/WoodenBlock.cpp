//
// Created by Erick on 2/20/2021.
//

#include "WoodenBlock.h"

WoodenBlock::WoodenBlock(Elements::Layer layer, Point location, bool collision) : Tile(layer, location, collision) {
    setTileName("WoodenBlock");
}

Sprite WoodenBlock::getSprite() {
    sprite.setTexture(texture);
    return sprite;
}
