//
// Created by Erick on 2/20/2021.
//

#include "Elements.h"

Elements::Elements(Layer layer, Point &location, Global global) {
    Elements::layer = layer;
    Elements::location = location;
    switch (layer){
        case BACK_LAYER:
            break;
        case MIDDLE_LAYER:
            break;
        case FRONT_LAYER:
            break;
    }
    Elements::global = global;
}

void Elements::reloadLayer() {
    switch (layer){
        case BACK_LAYER:
            break;
        case MIDDLE_LAYER:
            break;
        case FRONT_LAYER:
            break;
    }
}

void Elements::removeFromLayer() {
    switch (layer){
        case BACK_LAYER:
            break;
        case MIDDLE_LAYER:
            break;
        case FRONT_LAYER:
            break;
    }
}

void Elements::changeLayer(Layer layer) {
    switch (Elements::layer){
        case BACK_LAYER:
            break;
        case MIDDLE_LAYER:
            break;
        case FRONT_LAYER:
            break;
    }
    Elements::layer = layer;
    switch (layer){
        case BACK_LAYER:
            break;
        case MIDDLE_LAYER:
            break;
        case FRONT_LAYER:
            break;
    }
}

Elements::Layer Elements::getLayer() {
    return Elements::layer;
}

bool Elements::isUnloaded() {
    return unloaded;
}

void Elements::setUnloaded(bool isLoaded) {
    unloaded = isLoaded;
}

Point Elements::getLocation() {
    return location;
}

void Elements::setLocation(Point &location) {
    Elements::location = location;
}

void Elements::addX(int x) {
    Elements::location.x += x;
}

void Elements::addY(int y) {
    Elements::location.y += y;
}

void Elements::setLocation(const int x, const int y) {
    Elements::location.setLocation(x,y);
}
