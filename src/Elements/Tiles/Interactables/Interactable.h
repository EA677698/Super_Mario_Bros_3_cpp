//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_INTERACTABLE_H
#define SUPER_MARIO_BROS_3_C_INTERACTABLE_H
#include "../Tile.h"

class Interactable : public Tile{

private:
    bool activated;
    int currentSprite;

public:
    Interactable(Layer layer, Point location, bool collision);
    void tick();
    virtual void executeOnTouch();
    virtual void executeOnAction();
    bool isActivated();
    void setActivated(bool activated);
    int getCurrentSprite();
    void setCurrentSprite(int sprite);
};


#endif //SUPER_MARIO_BROS_3_C_INTERACTABLE_H
