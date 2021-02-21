//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_TRIGGER_H
#define SUPER_MARIO_BROS_3_C_TRIGGER_H
#include "Tool.h"

class Trigger : public Tool {

private:
    string command;
    int MAX_ACTIVATIONS;
    int activations = 0;
    bool stillInContact;
    Clock timer;
    Time elapsed;

public:

    Trigger(Layer layer, Point location, int middleBlocks, int layers, string command, int activations);

    void tick();

    string to_string();

};


#endif //SUPER_MARIO_BROS_3_C_TRIGGER_H
