//
// Created by Erick on 2/20/2021.
//

#include "Trigger.h"

Trigger::Trigger(Elements::Layer layer, Point location, int middleBlocks, int layers, string command, int activations) : Tool(layer, location, false, middleBlocks, layers) {
    setTileName("Trigger");
    MAX_ACTIVATIONS = activations;
    Trigger::command = command;
}

void Trigger::tick() {
    Tool::tick();
    if(MAX_ACTIVATIONS!=0&&activations>=MAX_ACTIVATIONS){
        Main.game.getManager().getTiles().remove(this);
    }
    elapsed = timer.getElapsedTime();
    if(elapsed.asMilliseconds()>80){
        if(Main.game.getManager().getPlayer()!=NULL&&Main.game.getManager().getPlayer().getHitBox().intersects(getHitBox())){
            if(!stillInContact){
                Main.game.getManager().commandInput(tolower(command));
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
    return string;
}
