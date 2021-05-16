//
// Created by Erick on 2/20/2021.
//
#include "../../../Tools/GeneralTools.cpp"
#include "Coin.h"

Coin::Coin(Elements::Layer layer, Point *coordinates, int width, int height, int direction, bool hasCollision, Global global)
        : NonLiving(layer, *coordinates, width, height, direction, hasCollision, global) {
}

Coin::Coin(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, int direction,
           bool hasGravity, bool hasCollision, Global global) : NonLiving(layer, coordinates, width, height, life, damage, direction,
                                                           hasGravity, hasCollision, global) {

}

Coin::Coin(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, double velocity,
           double gravity, int direction, bool hasGravity, bool hasCollision, Global global) : NonLiving(layer, coordinates, width,
                                                                                          height, life, damage,
                                                                                          velocity, gravity, direction,
                                                                                          hasGravity, hasCollision, global) {

}

void Coin::executeUponTouch(Player player) {
    global.money++;
    global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\coin.wav");
    removeFromLayer();
    vecRemove(this, global.manager->getEnts());
}

void Coin::death() {
    Entity::death();
}

Sprite Coin::getSprite() {

}
