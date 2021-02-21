//
// Created by Erick on 2/20/2021.
//

#include "Interactable.h"

Interactable::Interactable(Elements::Layer layer, Point location, bool collision) : Tile(layer, location, collision) {

}

void Interactable::tick() {
    Tile::tick();
}

void Interactable::executeOnTouch() {

}

void Interactable::executeOnAction() {

}

bool Interactable::isActivated() {
    return activated;
}

void Interactable::setActivated(bool activated) {
    Interactable::activated = activated;
}

int Interactable::getCurrentSprite() {
    return currentSprite;
}

void Interactable::setCurrentSprite(int sprite) {
    currentSprite = sprite;
}
