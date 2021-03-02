//
// Created by Erick on 2/20/2021.
//

#include "Fireball.h"

Fireball::Fireball(Elements::Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision)
        : NonLiving(layer, coordinates, width, height, direction, hasCollision) {

}

void Fireball::executeUponTouch(Player mario) {
    if(&mario != NULL){
        elapsed = hitTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>2000){
            if(mario.getHitBox().intersects(getHitBox())){
                switch (mario.getPower()){
                    case mario.SMALL: mario.setDead(true);
                        Main.game.getBgmPlayer().getMusic().stop();
                        SFX.down1.setFramePosition(0);
                        SFX.down1.start();
                        break;
                    case mario.BIG: mario.setPower(mario.SMALL);
                        SFX.pipe.setFramePosition(0);
                        SFX.pipe.start();
                        break;
                    default: mario.setPower(mario.BIG);
                }
                hitTimer.restart();
            }
        }
    }
}

void Fireball::tick() {
    Entity::tick();
    elapsed = timer.getElapsedTime();
    if(elapsed.asMilliseconds()>100){
        if(getCurrentSprite()>=3){
            setSpriteIndex(0);
        }
        setSpriteIndex(getCurrentSprite()+1);
        timer.restart();
    }
    elapsed = moveTimer.getElapsedTime();
    if(elapsed.asMilliseconds()>10){
        if(getDirection()==1){
            addX(5);
        } else if(getDirection()==-1) {
            addX(-5);
        }
        moveTimer.restart();
    }
}

void Fireball::death() {
    Entity::death();
}

Sprite Fireball::getSprite() {
    return NonLiving::getSprite();
}
