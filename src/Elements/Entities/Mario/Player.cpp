//
// Created by Erick on 2/20/2021.
//

#include "Player.h"

Player::Power Player::getPower() const {
    return power;
}

void Player::setPower(Player::Power power) {
    Player::power = power;
}

bool Player::isMiddle() const {
    return middle;
}

void Player::setMiddle(bool middle) {
    Player::middle = middle;
}

bool Player::isStart() const {
    return start;
}

void Player::setStart(bool start) {
    Player::start = start;
}

bool Player::isMiddleH() const {
    return middleH;
}

void Player::setMiddleH(bool middleH) {
    Player::middleH = middleH;
}

bool Player::isStartH() const {
    return startH;
}

void Player::setStartH(bool startH) {
    Player::startH = startH;
}

void Player::jump() {
    addY((int) getYVelocity());
    elapsed = jumpTimer.getElapsedTime();
    if(elapsed.asMilliseconds()>37){
        if(getYVelocity()<0){
            setYVelocity(getYVelocity()+1);
        } else {
            setHasGravity(true);
        }
        jumpTimer.restart();
    }
}

void Player::walk() {
    if (ALT) {
        elapsed = runTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>300) {
            if (getXVelocity() < WALK_SPEED) {
                setXVelocity(getXVelocity() + 1);
            } else if (getXVelocity() > WALK_SPEED) {
                setXVelocity(getXVelocity() - 1);
            }
            runTimer.restart();
        }
    } else {
        elapsed = speedTimer.getElapsedTime();
        if (elapsed.asMilliseconds()> 100 && !isOffGround()) {
            if (getXVelocity() < MAX_SPEED) {
                setXVelocity(getXVelocity() + 1);
            }
            speedTimer.restart();
        }
    }
}

void Player::slowDown() {
    elapsed = slowDownTimer.getElapsedTime();
    if(elapsed.asMilliseconds()>200){
        if(getXVelocity()>0.0){
            setXVelocity(getXVelocity()-1);
            slowDownTimer.restart();
        }
    }
}

void Player::sideScrolling() {
    middle = false;
    start = false;
    middleH = false;
    startH = false;
    if(getLocation().y>850){
        setDead(true);
        return;
    }
    if(getLocation().y<300){
        addY(5);
        middleH = true;
    }
    if(getLocation().y>720){
        addY(-5);
        startH = true;
    }
    if(getLocation().x>=(1920/2)){
        addX((int)(getXVelocity()*-1));
        middle = true;
    }
    if(getLocation().x<=860){
        addX((int) getXVelocity());
        start = true;
    }
}

void Player::changeSprite() {
    elapsed = spriteTimer.getElapsedTime();
    if (elapsed.asMilliseconds() > 100*(5/(getXVelocity()+.01))) {
        if (getCurrentSprite() == 1) {
            setSpriteIndex(0);
        } else {
            setSpriteIndex(1);
        }
        spriteTimer.restart();
    }
}

Player::Player(Elements::Layer layer, Point coordinates, int width, int height, bool hasCollision, Global global) : Entity(layer,
                                                                                                            coordinates,
                                                                                                            width,
                                                                                                            height,
                                                                                                            hasCollision, global) {
    power = SMALL;
    this->setEntityName("Mario");
    this->setXVelocity(0);
    this->setYVelocity(0);
}

Player::Player(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, bool hasGravity,
               bool hasCollision, Global global) : Entity(layer, coordinates, width, height, life, damage, hasGravity, hasCollision, global) {
    power = SMALL;
    this->setEntityName("Mario");
    this->setXVelocity(0);
    this->setYVelocity(0);
}

Player::Player(Elements::Layer layer, Point coordinates, int width, int height, int life, int damage, double speed,
               double gravity, bool hasGravity, bool hasCollision, Global global) : Entity(layer, coordinates, width, height, life,
                                                                            damage, speed, gravity, hasGravity,
                                                                            hasCollision, global) {
    power = SMALL;
    this->setEntityName("Mario");
    this->setXVelocity(0);
    this->setYVelocity(0);
}

void Player::tick() {
    Entity::tick();
    if(!isDead()){
        sideScrolling();
        elapsed = movementTimer.getElapsedTime();
        if(elapsed.asMilliseconds()>10){
            addX((int)(getXVelocity()*getDirection()));
            if(JUMP){
                if(initialJump){
                    setYVelocity(MAX_JUMP_SPEED);
                    setHasGravity(false);
                    setSpriteIndex(3);
                    initialJump = false;
                }
                jump();
            } else {
                setHasGravity(true);
            }
            movementTimer.restart();
        }
        if(!isOffGround()){
            initialJump = true;
        }
        if(!isOffGround()&&getXVelocity()>0){
            changeSprite();
        } else if(!isOffGround()&&getXVelocity()==0) {
            setSpriteIndex(0);
        }
        if(RIGHT){
            setDirection(1);
            walk();
            previousDirection = getDirection();
        } else if(LEFT){
            setDirection(-1);
            walk();
            previousDirection = getDirection();
        } else {
            slowDown();
        }
    } else {
        death();
    }
}

Sprite Player::getSprite() {
    return Entity::getSprite();
}

void Player::death() {
    Entity::death();
    setSpriteIndex(9);
    elapsed = deathTimer.getElapsedTime();
    if(elapsed.asMilliseconds()>10){
        addY(10);
        deathTimer.restart();
    }
}

string Player::to_string() {
    return Entity::to_string();
}
