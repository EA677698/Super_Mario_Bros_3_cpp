//
// Created by Erick on 2/20/2021.
//

#include "Bricks.h"

const Entity &Bricks::getContainedEntity() const {
    return containedEntity;
}

bool Bricks::isBreakable() const {
    return breakable;
}

Bricks::Bricks(Elements::Layer layer, Point location, bool collision, Entity containedEntity) : Interactable(layer, location, collision){
    this->containedEntity = containedEntity;
    setTileName("Brick");
    breakable = false;
}

Bricks::Bricks(Elements::Layer layer, Point location, bool collision, bool breakable) : Interactable(layer, location, collision) {
    setTileName("Brick");
    breakable = breakable;
}

void Bricks::tick() {
    Interactable::tick();
    if(!isActivated()){
        if(Main.game.getManager().getPlayer()!=NULL) {
            if (Main.game.getManager().getPlayer().getHitBox().intersects(getHitBox())&&getHitBox().outcode(Main.game.getManager().getPlayer().getHitBox().getCenterX(),Main.game.getManager().getPlayer().getHitBox().getCenterY())==8) {
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
    if(breakable&&Main.game.getManager().getPlayer().getPower()==Powers.BIG){
        removeFromLayer();
        Main.game.getManager().getTiles().remove(this);
    }
    if(&containedEntity != NULL){
        containedEntity.setLocation(getLocation());
        Main.game.getManager().getEnts().add(containedEntity);
        elapsed = executeTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>100){
            containedEntity.addY(-1);
            executeTimer.restart()
        }
    }
    setCurrentSprite(4);
}

Sprite Bricks::getSprite() {
    return Sprite();
}

string Bricks::to_string() {
    return
}
