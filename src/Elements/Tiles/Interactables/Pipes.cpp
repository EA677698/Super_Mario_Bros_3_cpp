//
// Created by Erick on 2/20/2021.
//

#include "Pipes.h"

Pipes::Pipes(Elements::Layer layer, Point location, bool collision, int blocks) : Interactable(layer,location,collision) {
    this->blocks = blocks;
    setTileName("Pipe");
    this->setWidth(120);
    this->setHeight(((blocks/2)+1)*60);
    calculateTileLayers();
}

void Pipes::tick() {
    Interactable::tick();
    executeOnAction();
    if(Main.game.getManager().getSelectedTile()==this){
        changeHeight();
    }
}

void Pipes::connectToPipe(Pipes pipe) {

}

void Pipes::executeOnAction() {
    if(connectionPipe!=NULL){
        if(Main.game.getManager().getPlayer().getHitBox().intersects(this->getHitBox())){
            if(Main.game.getManager().getPlayer().getLocation().y<this->getLocation().y){
                if(DOWN){
                    Main.game.getManager().getPlayer().setLocation(new Point(connectionPipe.getLocation().x,connectionPipe.getLocation().y));
                }
            }
        }
    }
}

Sprite Pipes::getSprites() {
    if (!Main.game.getManager().getTileLayouts().containsKey(getUUID())) {
        calculateTileLayers();
    }
    return Main.game.getManager().getTileLayouts().get(getUUID());
}

void Pipes::calculateTileLayers() {
    Image[][] tile = new Image[(2+blocks)/2][2];
    tile[0][0] = Main.game.getSpritesLoader().getPipes()[0];
    tile[0][1] = Main.game.getSpritesLoader().getPipes()[1];
    for(int i = 1; i<tile.length; i++){
        tile[i][0] = Main.game.getSpritesLoader().getPipes()[2];
        tile[i][1] = Main.game.getSpritesLoader().getPipes()[3];
    }
    Main.game.getManager().getTileLayouts().put(getUUID(),tile);
}

void Pipes::changeHeight() {
    elapsed = timer.getElapsedTime();
    if(SHIFT&&elapsed.asMilliseconds()>100){
        if(DOWN){
            blocks+=2;
        } else if(blocks>=2&&UP){
            blocks-=2;
        }
        timer.restart();
        this->setHeight(((blocks/2)+1)*60);
        calculateTileLayers();
    }
}

string Pipes::to_string() {
    return blocks+",";
}
