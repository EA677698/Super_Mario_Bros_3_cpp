//
// Created by Erick on 2/20/2021.
//

#include "Tile.h"

int Tile::getWidth() const {
    return width;
}

void Tile::setWidth(int width) {
    Tile::width = width;
}

int Tile::getHeight() const {
    return height;
}

void Tile::setHeight(int height) {
    Tile::height = height;
}

bool Tile::isCollision() const {
    return collision;
}

void Tile::setCollision(bool collision) {
    Tile::collision = collision;
}

const HitBox Tile::getHitBox() const {
    return hitBox;
}

void Tile::setHitBox(const HitBox &hitbox) {
    Tile::hitBox = hitbox;
}

const string &Tile::getTileName() const {
    return tileName;
}

void Tile::setTileName(const string &tileName) {
    Tile::tileName = tileName;
}

int Tile::getBlocksPerLayer() const {
    return blocksPerLayer;
}

void Tile::setBlocksPerLayer(int blocksPerLayer) {
    Tile::blocksPerLayer = blocksPerLayer;
}

Tile::Tile(Elements::Layer layer, Point location, bool collision) : Elements(layer, location) {
    this->location = location;
    this->collision = collision;
    hitBox = HitBox(location.x, location.y, width, height);
}

void Tile::tick() {

}

void Tile::callingException() {
    hitBox.setLocation(getLocation().x,getLocation().y);
    hitBox.setSize(width,height);
}
