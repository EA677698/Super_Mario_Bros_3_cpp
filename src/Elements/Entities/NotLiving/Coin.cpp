//
// Created by Erick on 2/20/2021.
//

#include "Coin.h"

Coin::Coin(Elements::Layer layer, Point *coordinates, int width, int height, int direction, bool hasCollision)
        : NonLiving(layer, coordinates, width, height, direction, hasCollision) {

}

Coin::Coin(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, int direction,
           bool hasGravity, bool hasCollision) : NonLiving(layer, coordinates, width, height, life, damage, direction,
                                                           hasGravity, hasCollision) {

}

Coin::Coin(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity,
           double gravity, int direction, bool hasGravity, bool hasCollision) : NonLiving(layer, coordinates, width,
                                                                                          height, life, damage,
                                                                                          velocity, gravity, direction,
                                                                                          hasGravity, hasCollision) {

}

void Coin::executeUponTouch(Player player) {
    Global.money++;
    SFX.coin.setFramePosition(0);
    SFX.coin.start();
    removeFromLayer();
    Main.game.getManager().getEnts().remove(this);
}

void Coin::death() {
    Entity::death();
}

Sprite Coin::getSprite() {

}
