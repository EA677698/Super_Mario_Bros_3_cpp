//
// Created by Erick on 2/20/2021.
//

#include "Bricks.h"
#include "../../Entities/Mario/Player.h"

const Entity &Bricks::getContainedEntity() const {
    return containedEntity;
}

bool Bricks::isBreakable() const {
    return breakable;
}

Bricks::Bricks(Elements::Layer layer, Point location, bool collision, Entity containedEntity, Global global) : Interactable(layer, location, collision, global){
    this->containedEntity = containedEntity;
    setTileName("Brick");
    breakable = false;
}

Bricks::Bricks(Elements::Layer layer, Point location, bool collision, bool breakable, Global global) : Interactable(layer, location, collision, global) {
    setTileName("Brick");
    breakable = breakable;
}

void Bricks::tick() {
    Interactable::tick();
    if(!isActivated()){
        if(global->manager->getPlayer()!=NULL) {
            if (global->manager->getPlayer()->getHitBox().intersects(getHitBox())&&getHitBox().outcode(global->manager->getPlayer()->getHitBox().getCenterX(),global->manager->getPlayer()->getHitBox().getCenterY())==8) {
                executeOnTouch();
            }
        }
        elapsed = timer.getElapsedTime();
        if(elapsed.asMilliseconds()>200){
            setCurrentSprite(getCurrentSprite()+1);
            if(getCurrentSprite()>3){
                setCurrentSprite(0);
            }
            timer.restart();
        }
    } else {
        setCurrentSprite(4);
    }
}

void Bricks::executeOnTouch() {
    setActivated(true);
    if(breakable&&global->manager->getPlayer()->getPower()==Player::BIG){
        removeFromLayer();
        vecRemove(this,global->manager->getTiles());
    }
    if(&containedEntity != NULL){
        containedEntity.setLocation(location);
        global->manager->getEnts().push_back(&containedEntity);
        elapsed = executeTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>100){
            containedEntity.addY(-1);
            executeTimer.restart();
        }
    }
    setCurrentSprite(4);
}

sf::Sprite Bricks::getSprite() {
    return sf::Sprite();
}

string Bricks::to_string() {
    return "";
}
