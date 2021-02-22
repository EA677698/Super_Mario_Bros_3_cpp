//
// Created by Erick on 2/20/2021.
//

#include "LuckyBlock.h"
#include "../../Entities/NotLiving/Coin.h"

LuckyBlock::LuckyBlock(Elements::Layer layer, Point Location, bool collision, Coin *containedEntity) : Interactable(layer, location, collision) {
    this->containedEntity = containedEntity;
    setTileName("LuckyBlock");
}

void LuckyBlock::tick() {
    Interactable::tick();
    if(!isActivated()){
        if(Main.game.getManager().getPlayer()!=NULL) {
            if (Main.game.getManager().getPlayer().getHitBox().intersects(getHitBox())) {
                if(getHitBox().outcode(Main.game.getManager().getPlayer().getHitBox().getCenterX(),Main.game.getManager().getPlayer().getHitBox().getCenterY())==8){
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
        containedEntity.setLocation(Point(getLocation().x,getLocation().y));
        Main.game.getManager().getEnts().add(containedEntity);
        elapsed = executeTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>100){
            containedEntity.changeLayer(MIDDLE_LAYER);
            containedEntity.addY(-1);
            executeTimer.restart()
        }
    }
}

string LuckyBlock::to_string() {
    return std::__cxx11::string();
}

Sprite LuckyBlock::getSprite() {
    return Sprite();
}
