//
// Created by Erick on 2/20/2021.
//

#include "Entity.h"

int Entity::getWidth() const {
    return width;
}

void Entity::setWidth(int width) {
    Entity::width = width;
}

int Entity::getHeight() const {
    return height;
}

void Entity::setHeight(int height) {
    Entity::height = height;
}

int Entity::getLife() const {
    return life;
}

void Entity::setLife(int life) {
    Entity::life = life;
}

int Entity::getDamage() const {
    return damage;
}

void Entity::setDamage(int damage) {
    Entity::damage = damage;
}

int Entity::getCurrentSprite() const {
    return spriteIndex;
}

void Entity::setSpriteIndex(int spriteIndex) {
    Entity::spriteIndex = spriteIndex;
}

int Entity::getDirection() const {
    return direction;
}

void Entity::setDirection(int direction) {
    Entity::direction = direction;
}

double Entity::getXVelocity() const {
    return XVelocity;
}

void Entity::setXVelocity(double xVelocity) {
    XVelocity = xVelocity;
}

double Entity::getYVelocity() const {
    return YVelocity;
}

void Entity::setYVelocity(double yVelocity) {
    YVelocity = yVelocity;
}

double Entity::getGravity() const {
    return gravity;
}

void Entity::setGravity(double gravity) {
    Entity::gravity = gravity;
}

bool Entity::isAllowedMoving() const {
    return allowedMoving;
}

void Entity::setAllowedMoving(bool allowedMoving) {
    Entity::allowedMoving = allowedMoving;
}

bool Entity::isDead() const {
    return dead;
}

void Entity::setDead(bool isDead) {
    Entity::dead = isDead;
}

bool Entity::isCollision() const {
    return collision;
}

void Entity::setCollision(bool collision) {
    Entity::collision = collision;
}

bool Entity::isOffGround() const {
    return offGround;
}

bool Entity::HasGravity() const {
    return hasGravity;
}

void Entity::setGravity(bool hasGravity) {
    Entity::hasGravity = hasGravity;
}

bool Entity::isTouchingGround() const {
    return (touchingGround>0);
}

const string &Entity::getEntityName() const {
    return entityName;
}

HitBox &Entity::getHitBox() {
    return hitBox;
}

void Entity::setHitBox(HitBox hitBox) {
    Entity::hitBox = hitBox;
}

Entity::Entity(Elements::Layer layer, Point coordinates, int width, int height, bool hasCollision): Elements(layer, coordinates) {
    location = Point((int)(coordinates.x*scaleX),(int)(coordinates.y*scaleY));
    Entity::width = (int)(width*scaleX);
    Entity::height = (int)(height*scaleY);
    life = 1;
    collision = hasCollision;
    hasGravity = true;
    damage = 1;
    XVelocity = 1.0;
    gravity = 1;
    hitBox = HitBox(location, Entity::width, Entity::height);
}

Entity::Entity(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, bool hasGravity,
               bool hasCollision): Elements(layer, coordinates) {
    location = Point((int)(coordinates.x*scaleX),(int)(coordinates.y*scaleY));
    Entity::width = (int)(width*scaleX);
    Entity::height = (int)(height*scaleY);
    life = 1;
    collision = hasCollision;
    hasGravity = true;
    damage = 1;
    XVelocity = 1.0;
    gravity = 1;
    hitBox = HitBox(location, Entity::width, Entity::height);
}

Entity::Entity(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, double XVelocity,
               double gravity, bool hasGravity, bool hasCollision): Elements(layer, coordinates) {
    location = Point((int)(coordinates.x*scaleX),(int)(coordinates.y*scaleY));
    Entity::width = (int)(width*scaleX);
    Entity::height = (int)(height*scaleY);
    life = 1;
    collision = hasCollision;
    hasGravity = true;
    damage = 1;
    XVelocity = 1.0;
    gravity = 1;
    hitBox = HitBox(location, Entity::width, Entity::height);
}

void Entity::tick() {
    touchingGround = 0;
    for(Tile tile: Main.game.getManager().getTiles()){
        if(tile.isCollision()){
            int side = tile.getHitBox().outcode(hitBox.getCenterX(),hitBox.getCenterY());
            if(hitBox.intersects(tile.getHitBox())&&(side==2||side==3||side==6)){
                touchingGround++;
            }
        }
    }
    offGround = touchingGround <= 0;
    if(hasGravity){
        elapsed = gravityTimer.getElapsedTime();
        if(touchingGround==0&&!isSelected&&elapsed.asMicroseconds()>1200){
            addY((int)(gravity));
            gravityTimer.getElapsedTime();
        }
    }
}

void Entity::cullingException() {
    hitBox.setLocation(location);
    hitBox.setSize(width-20,height);
}

bool Entity::isFacingTile(Tile *tile) {
    if(tile == NULL){
        return false;
    }
    if(tile->getLocation().x<Entity::getLocation().x){
        if(Entity::getDirection()==-1){
            return true;
        }
    }
    if(Entity::getLocation().x>Entity::getLocation().x){
        return Entity::getDirection() == 1;
    }
    return false;
}

bool Entity::isFacingEntity(Entity *entity) {
    if(entity==NULL){
        return false;
    }
    if(entity->getLocation().x<Entity::getLocation().x){
        if(Entity::getDirection()==-1){
            return true;
        }
    }
    if(entity->getLocation().x>Entity::getLocation().x){
        return Entity::getDirection() == 1;
    }
    return false;
}

void Entity::setOffGround(bool offGround) {

}

void Entity::death() {

}

Sprite Entity::getSprite() {
    return Sprite();
}

string Entity::to_string() {
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
    ","+::to_string(hasGravity)+","+::to_string(collision)+",";
}

void Entity::setEntityName(const string &entityName) {
    Entity::entityName = entityName;
}
