//
// Created by Erick on 10/27/2020.
//

#ifndef FIRST_GAME_HITBOX_H
#define FIRST_GAME_HITBOX_H
#include "Point.h"
#include "Dimension.h"


class HitBox {

private:
    int x,y,width,height;
public:
    HitBox();
    HitBox(HitBox &hitBox);
    HitBox(int x, int y, int width, int height);
    HitBox(Point &point, int width, int height);
    HitBox(Point &point, Dimension &dimension);
    HitBox(int x, int y, Dimension &dimension);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    void setSize(int width, int height);
    void setSize(Dimension dimension);
    Dimension getSize();
    int getCenterX();
    int getCenterY();
    int getMinX();
    int getMaxX();
    int getMinY();
    int getMaxY();
    int outcode(double x, double y);
    void setBounds(HitBox &hitBox);
    void setBounds(int x, int y, int width, int height);
    Point getLocation();
    void setLocation(Point p);
    void setLocation(int x, int y);
    void move(int x, int y);
    void move(Point &point);
    bool contains(Point point, Dimension dimension);
    bool contains(int X, int Y, int W, int H);
    bool intersects(HitBox &hitBox);
    string toString();



};


#endif //FIRST_GAME_HITBOX_H
