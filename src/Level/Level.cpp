//
// Created by Erick on 2/20/2021.
//

#include "Level.h"

Level::Level(Level::Background background) : Elements(NONE, Point(0,0)){

}

Level::Background Level::getBackground() {
    return Level::BLUE_BACKGROUND;
}

string Level::background_value_of(Level::Background background) {
    return std::__cxx11::string();
}

void Level::setBackground(Level::Background background) {

}
