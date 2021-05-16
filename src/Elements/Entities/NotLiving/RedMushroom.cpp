//
// Created by Erick on 2/20/2021.
//

#include "RedMushroom.h"

RedMushroom::RedMushroom(Elements::Layer layer, Point coordinates, int width, int height, int direction,
                         bool hasCollision, Global global) : NonLiving(layer, coordinates, width, height, direction, hasCollision, global) {
    setEntityName("RedMushroom");
}

RedMushroom::RedMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                         int direction, bool hasGravity, bool hasCollision, Global global) : NonLiving(layer, coordinates, width,
                                                                                        height, life, damage, direction,
                                                                                        hasGravity, hasCollision, global) {
    setEntityName("RedMushroom");
}

RedMushroom::RedMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                         double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, Global global)
        : NonLiving(layer, coordinates, width, height, life, damage, velocity, gravity, direction, hasGravity,
                    hasCollision, global) {
    setEntityName("RedMushroom");
}

void RedMushroom::executeUponTouch(Player player) {
    player.setPower(player.BIG);
    global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\powerup.wav");
    removeFromLayer();
    vecRemove(this, global.manager->getEnts());
}

void RedMushroom::tick() {
    Entity::tick();
}

void RedMushroom::death() {
    Entity::death();
}

Sprite RedMushroom::getSprite() {
    return NonLiving::getSprite();
}
