//
// Created by Erick on 2/20/2021.
//

#include "HammerBro.h"

HammerBro::HammerBro(Elements::Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision,
                     int type) : Enemy(layer, coordinates, width, height, direction, hasCollision) {
    this->type = type;
    setEntityName("HammerBro");
}

HammerBro::HammerBro(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                     int direction, bool hasGravity, bool hasCollision, int type) : Enemy(layer, coordinates, width, height, life, damage, direction, hasGravity, hasCollision) {
    this->type = type;
    setEntityName("HammerBro");
}

HammerBro::HammerBro(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                     double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, int type) : Enemy(layer, coordinates, width, height, life, damage, velocity, gravity, direction, hasGravity, hasCollision) {
    this->type = type;
    setEntityName("HammerBro");
}

void HammerBro::tick() {
    Entity::tick();
    elapsed = one.getElapsedTime();
    if(elapsed.asMilliseconds()>200){
        if(getCurrentSprite() > 0){
            setSpriteIndex(-1);
        }
        elapsed = attackTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>2000){
            if(isFacingEntity(Main.game.getManager().getPlayer())){
                attack();
            } else {
                setDirection(getDirection()*-1);
            }
            attackTimer.restart();
        }
        setSpriteIndex(getCurrentSprite() + 1);
        one.restart();
    }
}

void HammerBro::attack() {
    if(type==3){
        setSpriteIndex(1);
        Main.game.getManager().getEnts().add(new Fireball(Layer.MIDDLE_LAYER,getLocation(),40,40,getDirection(),false));
    }
}

Sprite HammerBro::getSprite() {
    return Enemy::getSprite();
}

int HammerBro::getType() {
    return type;
}

void HammerBro::setType(int type) {
    HammerBro::type = type;
}

string HammerBro::to_String() {
    return Enemy::to_string()+::to_string(type)+",";
}
