//
// Created by Erick on 2/20/2021.
//

#include "Trigger.h"

Trigger::Trigger(Elements::Layer layer, Point location, int middleBlocks, int layers, string command, int activations, Global global) : Tool(layer, location, false, middleBlocks, layers, global) {
    setTileName("Trigger");
    MAX_ACTIVATIONS = activations;
    Trigger::command = command;
}

void Trigger::tick() {
    Tool::tick();
    if(MAX_ACTIVATIONS!=0&&activations>=MAX_ACTIVATIONS){
        vecRemove(this, global->manager->getTiles());
    }
    elapsed = timer.getElapsedTime();
    if(elapsed.asMilliseconds()>80){
        if(global->manager->getPlayer()!=NULL&&global->manager->getPlayer()->getHitBox().intersects(getHitBox())){
            if(!stillInContact){
                global->manager->commandInput(toLower(command));
                activations++;
                stillInContact = true;
            }
        } else {
            stillInContact = false;
        }
        timer.restart();
    }
}

string Trigger::to_string() {
    return "";
}
