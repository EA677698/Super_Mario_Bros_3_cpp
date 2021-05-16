//
// Created by Erick on 2/20/2021.
//

#include "Goomba.h"

Goomba::Goomba(Elements::Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision, Global global)
        : Enemy(layer, coordinates, width, height, direction, hasCollision, global) {
    setEntityName("Goomba");
    this->setDirection(direction);
    this->setXVelocity(3);
}

Goomba::Goomba(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, int direction,
               bool hasGravity, bool hasCollision, Global global) : Enemy(layer, coordinates, width, height, life, damage, direction,
                                                           hasGravity, hasCollision, global) {
    setEntityName("Goomba");
    this->setDirection(direction);
    this->setXVelocity(3);
}

Goomba::Goomba(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity,
               double gravity, int direction, bool hasGravity, bool hasCollision, Global global) : Enemy(layer, coordinates, width,
                                                                                          height, life, damage,
                                                                                          velocity, gravity, direction,
                                                                                          hasGravity, hasCollision, global) {
    setEntityName("Goomba");
    this->setDirection(direction);
    this->setXVelocity(3);
}

void Goomba::tick() {
    Entity::tick();
    if(isAllowedMoving()){
        elapsed = one.getElapsedTime();
        if(elapsed.asMilliseconds()>10){
            if(getDirection()==1){
                addX(3);
            } else if(getDirection()==-1) {
                addX(-3);
            }
            one.restart();
        }
    } else {
        setDirection(getDirection()*-1);
    }
}

void Goomba::death() {
    setHeight(10);
    Enemy::death();
}

sf::Sprite Goomba::getSprite() {
    return Enemy::getSprite();
}
