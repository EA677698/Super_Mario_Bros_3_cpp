//
// Created by Erick on 2/20/2021.
//

#include "GreenMushroom.h"

GreenMushroom::GreenMushroom(Elements::Layer layer, Point coordinates, int width, int height, int direction,
                             bool hasCollision, Global global) : NonLiving(layer, coordinates, width, height, direction,
                                                            hasCollision, global) {
    setEntityName("GreenMushroom");
}

GreenMushroom::GreenMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                             int direction, bool hasGravity, bool hasCollision, Global global) : NonLiving(layer, coordinates, width,
                                                                                            height, life, damage,
                                                                                            direction, hasGravity,
                                                                                            hasCollision, global) {
    setEntityName("GreenMushroom");
}

GreenMushroom::GreenMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                             double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, Global global)
        : NonLiving(layer, coordinates, width, height, life, damage, velocity, gravity, direction, hasGravity,
                    hasCollision, global) {
    setEntityName("GreenMushroom");
}

void GreenMushroom::executeUponTouch(Player player) {
    global.lives++;
    global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\1up.wav")
    removeFromLayer();
    vecRemove(this, global.manager->getEnts());
}

void GreenMushroom::death() {
    Entity::death();
}

void GreenMushroom::tick() {
    Entity::tick();
}

Sprite GreenMushroom::getSprite() {
    return NonLiving::getSprite();
}
