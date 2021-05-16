//
// Created by Erick on 2/20/2021.
//

#include "NonLiving.h"

NonLiving::NonLiving(Elements::Layer layer, Point coordinates, int width, int height, int direction,
                     bool hasCollision, Global global) : Entity(layer, coordinates, width, height, hasCollision, global) {
    this->setDirection(direction);
}

NonLiving::NonLiving(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                     int direction, bool hasGravity, bool hasCollision, Global global) : Entity(layer, coordinates, width, height, life, damage, hasGravity, hasCollision, global) {
    this->setDirection(direction);
}

NonLiving::NonLiving(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                     double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, Global global) : Entity(layer, coordinates, width, height, life, damage, velocity, gravity, hasGravity, hasCollision, global) {
    this->setDirection(direction);
}

void NonLiving::executeUponTouch(Player player) {

}

Sprite NonLiving::getSprite() {
    return Entity::getSprite();
}

string NonLiving::to_String() {
    string currLayer;
    switch (layer) {
        case FRONT_LAYER: currLayer = "FRONT_LAYER";
            break;
        case MIDDLE_LAYER: currLayer = "MIDDLE_LAYER";
            break;
        case BACK_LAYER: currLayer = "MIDDLE_LAYER";
            break;
    }
    return entityName+","+currLayer+","+::to_string(location.x)+","+::to_string(location.y)+","+::to_string(width)+","+
           ::to_string(height)+","+::to_string(life)+","+::to_string(damage)+","+::to_string(XVelocity)+","+::to_string(gravity)+
           ","+::to_string(direction)+","+::to_string(hasGravity)+","+::to_string(collision)+",";
}
