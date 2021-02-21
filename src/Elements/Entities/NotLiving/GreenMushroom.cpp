//
// Created by Erick on 2/20/2021.
//

#include "GreenMushroom.h"

GreenMushroom::GreenMushroom(Elements::Layer layer, Point coordinates, int width, int height, int direction,
                             bool hasCollision) : NonLiving(layer, coordinates, width, height, direction,
                                                            hasCollision) {
    setEntityName("GreenMushroom");
}

GreenMushroom::GreenMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                             int direction, bool hasGravity, bool hasCollision) : NonLiving(layer, coordinates, width,
                                                                                            height, life, damage,
                                                                                            direction, hasGravity,
                                                                                            hasCollision) {
    setEntityName("GreenMushroom");
}

GreenMushroom::GreenMushroom(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                             double velocity, double gravity, int direction, bool hasGravity, bool hasCollision)
        : NonLiving(layer, coordinates, width, height, life, damage, velocity, gravity, direction, hasGravity,
                    hasCollision) {
    setEntityName("GreenMushroom");
}

void GreenMushroom::executeUponTouch(Player player) {
    Global.lives++;
    SFX.up1.setFramePosition(0);
    SFX.up1.start();
    removeFromLayer();
    Main.game.getManager().getEnts().remove(this);
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
