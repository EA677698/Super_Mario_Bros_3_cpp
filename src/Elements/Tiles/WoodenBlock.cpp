//
// Created by Erick on 2/20/2021.
//

#include "WoodenBlock.h"

WoodenBlock::WoodenBlock(Elements::Layer layer, Point location, bool collision, Global global) : Tile(layer, location, collision, global) {
    setTileName("WoodenBlock");
}

sf::Sprite WoodenBlock::getSprite() {
    sprite.setTexture(texture);
    return sprite;
}
