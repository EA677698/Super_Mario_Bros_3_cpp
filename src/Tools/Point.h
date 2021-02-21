//
// Created by Erick on 10/27/2020.
//

#ifndef FIRST_GAME_POINT_H
#define FIRST_GAME_POINT_H
#include <iostream>
using namespace std;


class Point {

public:
    double x,y;
    Point();
    Point(double x, double y);
    Point(Point &point);
    void setX(double x);
    double getX() const;
    void setY(double y);
    double getY() const;
    void move(double x, double y);
    void setLocation(double x, double y);
    void setLocation(Point &point);
    double distance(Point &point);
    double distance(double x, double y);
    string toString();

};


#endif //FIRST_GAME_POINT_H
