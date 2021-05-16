//
// Created by Erick on 2/20/2021.
//

#include "LuckyBlock.h"
#include "../../Entities/NotLiving/Coin.h"

LuckyBlock::LuckyBlock(Elements::Layer layer, Point Location, bool collision, Entity containedEntity, Global global) : Interactable(layer, location, collision, global) {
    this->containedEntity = containedEntity;
    setTileName("LuckyBlock");
}

void LuckyBlock::tick() {
    Interactable::tick();
    if(!isActivated()){
        if(global.manager->getPlayer()!=NULL) {
            if (global.manager->getPlayer()->getHitBox().intersects(getHitBox())) {
                if(getHitBox().outcode(global.manager->getPlayer()->getHitBox().getCenterX(),global.manager->getPlayer()->getHitBox().getCenterY())==8){
                    executeOnTouch();
                }
            }
        }
        elapsed = timer.getElapsedTime();
        if(elapsed.asMilliseconds()>100){
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

void LuckyBlock::executeOnTouch() {
    setActivated(true);
    if(&containedEntity != NULL){
        containedEntity.setLocation(getLocation().x,getLocation().y);
        global.manager->getEnts().push_back(containedEntity);
        elapsed = executeTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>100){
            containedEntity.changeLayer(MIDDLE_LAYER);
            containedEntity.addY(-1);
            executeTimer.restart();
        }
    }
}

string LuckyBlock::to_string() {
    return "";
}

Sprite LuckyBlock::getSprite() {
    return Sprite();
}
