//
// Created by Erick on 2/20/2021.
//

#include "Enemy.h"

Enemy::Enemy(Elements::Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision): Entity(layer,coordinates,width,height,hasCollision) {
    this->setDirection(direction);
}

Enemy::Enemy(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, int direction,
             bool hasGravity, bool hasCollision) : Entity(layer,coordinates,width,height,life, damage, hasGravity, hasCollision) {
    this->setDirection(direction);
}

Enemy::Enemy(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity,
             double gravity, int direction, bool hasGravity, bool hasCollision) : Entity(layer,coordinates,width,height,life, damage, velocity, gravity, hasGravity, hasCollision) {
    this->setDirection(direction);
}

void Enemy::death() {
    Entity::death();
}

Sprite Enemy::getSprite() {
    return Entity::getSprite();
}

string Enemy::to_string() {
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
                  ","+::to_string(getDirection())+","+::to_string(hasGravity)+","+::to_string(collision)+",";
}
