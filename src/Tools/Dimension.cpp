//
// Created by Erick on 10/27/2020.
//

#include "Dimension.h"

Dimension::Dimension() {
    width = 0; height = 0;
}

Dimension::Dimension(int width, int height) : width(width), height(height) {}

int Dimension::getWidth() const {
    return width;
}

void Dimension::setWidth(int width) {
    Dimension::width = width;
}

int Dimension::getHeight() const {
    return height;
}

void Dimension::setHeight(int height) {
    Dimension::height = height;
}

void Dimension::setDimension(Dimension dimension){
    height = dimension.getHeight();
    width = dimension.getWidth();
}
