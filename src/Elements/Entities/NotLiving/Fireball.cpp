//
// Created by Erick on 2/20/2021.
//

#include "Fireball.h"

Fireball::Fireball(Elements::Layer layer, Point coordinates, int width, int height, int direction, bool hasCollision, Global global)
        : NonLiving(layer, coordinates, width, height, direction, hasCollision, global) {

}

void Fireball::executeUponTouch(Player &mario) {
    if(&mario != NULL){
        elapsed = hitTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>2000){
            if(mario.getHitBox().intersects(getHitBox())){
                switch (mario.getPower()){
                    case Player::SMALL: mario.setDead(true);
                        global.player.stop();
                        global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\1down.wav");
                        break;
                    case Player::BIG: mario.setPower(Player::SMALL);
                        global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\pipe.wav");
                        break;
                    default: mario.setPower(Player::BIG);
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
