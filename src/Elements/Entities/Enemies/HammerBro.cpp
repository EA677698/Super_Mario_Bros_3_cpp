//
// Created by Erick on 2/20/2021.
//

#include "HammerBro.h"
#include "../NotLiving/Fireball.h"

HammerBro::HammerBro(Elements::Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision,
                     int type, Global global) : Enemy(layer, coordinates, width, height, direction, hasCollision, global) {
    this->type = type;
    setEntityName("HammerBro");
}

HammerBro::HammerBro(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                     int direction, bool hasGravity, bool hasCollision, int type, Global global) : Enemy(layer, coordinates, width, height, life, damage, direction, hasGravity, hasCollision, global) {
    this->type = type;
    setEntityName("HammerBro");
}

HammerBro::HammerBro(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage,
                     double velocity, double gravity, int direction, bool hasGravity, bool hasCollision, int type, Global global) : Enemy(layer, coordinates, width, height, life, damage, velocity, gravity, direction, hasGravity, hasCollision, global) {
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
            Player *player = global.manager->getPlayer();
            if(isFacingEntity(player)){
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
        Point location;
        location = getLocation();
        global.manager->getEnts().push_back(new Fireball(Elements::MIDDLE_LAYER,location,40,40,getDirection(),false, global));
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
