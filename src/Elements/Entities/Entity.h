//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_ENTITY_H
#define SUPER_MARIO_BROS_3_C_ENTITY_H
#include "../../Tools/Point.h"
#include "../../Tools/HitBox.h"
#include <SFML/Graphics.hpp>
#include "../Elements.h"
#include "../Tiles/tile.h"

class Entity: public Elements {

private:
    Clock gravityTimer;
    Time elapsed;

protected:
    Texture texture;
    Sprite sprite;
    int width, height, life, damage, spriteIndex, direction, touchingGround;
    double XVelocity, YVelocity, gravity;
    HitBox hitBox;
    bool allowedMoving = true;
    bool dead = false;
    bool collision, offGround, selected, hasGravity;
public:
    bool isSelected() const;

    void setSelected(bool selected);

protected:
    string entityName;
public:
    Entity();

    void setEntityName(const string &entityName);

    HitBox &getHitBox();

    void setHitBox(HitBox hitBox);

    bool isTouchingGround() const;

    const string &getEntityName() const;

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    int getLife() const;

    void setLife(int life);

    int getDamage() const;

    void setDamage(int damage);

    int getCurrentSprite() const;

    void setSpriteIndex(int spriteIndex);

    int getDirection() const;

    void setDirection(int direction);

    double getXVelocity() const;

    void setXVelocity(double xVelocity);

    double getYVelocity() const;

    void setYVelocity(double yVelocity);

    double getGravity() const;

    void setGravity(double gravity);

    bool isAllowedMoving() const;

    void setAllowedMoving(bool allowedMoving);

    bool isDead() const;

    void setDead(bool isDead);

    bool isCollision() const;

    void setCollision(bool collision);

    bool isOffGround() const;

    bool HasGravity() const;

    void setHasGravity(bool hasGravity);

    Entity(Layer layer, Point coordinates, int width, int height, bool hasCollision);

    Entity(Layer layer, Point coordinates, int width, int height, int life, int damage, bool hasGravity, bool hasCollision);

    Entity(Layer layer, Point coordinates, int width, int height, int life, int damage, double XVelocity, double gravity, bool hasGravity, bool hasCollision);

    void tick();

    void cullingException();

    bool isFacingTile(Tile *tile);

    bool isFacingEntity(Entity *entity);

    void setOffGround(bool offGround);

    virtual void death();

    virtual sf::Sprite getSprite();

    string to_string();







};


#endif //SUPER_MARIO_BROS_3_C_ENTITY_H
