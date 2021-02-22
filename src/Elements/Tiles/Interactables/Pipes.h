//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_PIPES_H
#define SUPER_MARIO_BROS_3_C_PIPES_H
#include "Interactable.h"
#include "../Adjustables.h"
#include "../LayeredTile.h"
#include "../../../Settings/Controls.h"

class Pipes : public Interactable, public Adjustables, public LayeredTile {

private:
    int blocks;
    Pipes* connectionPipe = NULL;
    Clock timer;
    Time elapsed;

public:
    Pipes(Layer layer, Point location, bool collision, int blocks);
    void tick();
    void connectToPipe(Pipes pipe);
    void executeOnAction();
    Sprite getSprites();
    void calculateTileLayers();
    void changeHeight();
    string to_string();

};


#endif //SUPER_MARIO_BROS_3_C_PIPES_H
