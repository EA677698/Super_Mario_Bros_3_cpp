//
// Created by Erick on 2/20/2021.
//

#include "RedMushroom.h"

RedMushroom::RedMushroom(Elements::Layer layer, Point coordinates, int width, int height, int direction,
                         bool hasCollision) : NonLiving(layer, coordinates, width, height, direction, hasCollision) {
    setEntityName("RedMushroom");
}

RedMushroom::RedMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                         int direction, bool hasGravity, bool hasCollision) : NonLiving(layer, coordinates, width,
                                                                                        height, life, damage, direction,
                                                                                        hasGravity, hasCollision) {
    setEntityName("RedMushroom");
}

RedMushroom::RedMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                         double velocity, double gravity, int direction, bool hasGravity, bool hasCollision)
        : NonLiving(layer, coordinates, width, height, life, damage, velocity, gravity, direction, hasGravity,
                    hasCollision) {
    setEntityName("RedMushroom");
}

void RedMushroom::executeUponTouch(Player player) {
    player.setPower(player.BIG);
    SFX.powerUp.setFramePosition(0);
    SFX.powerUp.start();
    removeFromLayer();
    Main.game.getManager().getEnts().remove(this);}

void RedMushroom::tick() {
    Entity::tick();
}

void RedMushroom::death() {
    Entity::death();
}

Sprite RedMushroom::getSprite() {
    return NonLiving::getSprite();
}
