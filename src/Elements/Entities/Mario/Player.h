//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_PLAYER_H
#define SUPER_MARIO_BROS_3_C_PLAYER_H
#include "../../../Settings/Controls.h"
#include "../Entity.h"


class Player : public Entity{

private:
    Clock movementTimer,slowDownTimer,spriteTimer,speedTimer,runTimer,deathTimer,jumpTimer;
    Time elapsed;
    const int WALK_SPEED = 4;
    const int MAX_SPEED = 10;
    const int MAX_JUMP_SPEED = -11;
    int previousDirection;
    bool flag,middle,start,middleH,startH,initialJump;
    void jump();
    void walk();
    void slowDown();
    void sideScrolling();
    void changeSprite();

public:

    Player(Layer layer, Point coordinates, int width, int height, bool hasCollision, Global global);

    Player(Layer layer, Point coordinates, int width, int height, int life, int damage, bool hasGravity, bool hasCollision, Global global);

    Player(Layer layer, Point coordinates, int width, int height, int life, int damage, double speed, double gravity, bool hasGravity, bool hasCollision, Global global);

    enum Power{DEAD,NONE,SMALL,BIG,FIRE,TANOOKI,STAR};

    Power power;

    Power getPower() const;

    void setPower(Power power);

    bool isMiddle() const;

    void setMiddle(bool middle);

    bool isStart() const;

    void setStart(bool start);

    bool isMiddleH() const;

    void setMiddleH(bool middleH);

    bool isStartH() const;

    void setStartH(bool startH);

    void tick();

    Sprite getSprite();

    void death();

    string to_string();


};


#endif //SUPER_MARIO_BROS_3_C_PLAYER_H
