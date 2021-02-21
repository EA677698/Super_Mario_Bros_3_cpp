//
// Created by Erick on 10/27/2020.
//

#include "Point.h"
#include <cmath>

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(double x, double y) {
    Point::x = x;
    Point::y = y;
}

Point::Point(Point &point) {
    Point::x = point.getX();
    Point::y = point.getY();
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getX() const {
    return x;
}

void Point::setY(double y) {
    Point::y = y;
}

double Point::getY() const {
    return y;
}

void Point::move(double x, double y) {
    Point::x += x;
    Point::y += y;
}

void Point::setLocation(Point &point) {
    Point::x = point.getX();
    Point::y = point.getY();
}

void Point::setLocation(double x, double y) {
    Point::x = x;
    Point::y = y;
}

double Point::distance(double x, double y) {
    return sqrt(pow((x-Point::x),2)+pow((y-Point::y),2));
}

double Point::distance(Point &point) {
    return distance(point.getX(),point.getY());
}

string Point::toString() {
    return "x: "+to_string(Point::x)+", y: "+to_string(Point::y);
}
