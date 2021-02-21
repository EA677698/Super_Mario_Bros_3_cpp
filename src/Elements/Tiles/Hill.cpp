//
// Created by Erick on 2/20/2021.
//

#include "Hill.h"

int Hill::getType() const {
    return type;
}

void Hill::setType(int type) {
    Hill::type = type;
}

int Hill::getBlocks() const {
    return blocks;
}

void Hill::setBlocks(int blocks) {
    Hill::blocks = blocks;
}

Hill::Hill(Elements::Layer layer, Point location, bool collision, int type, int blocks) : Tile(layer, location, collision) {
    if(blocks%2==1){
        blocks++;
    }
    this->type = type;
    this->blocks = blocks;
    setTileName("Hill");
    this->setWidth(120);
    this->setHeight(((blocks/2)+1)*60);
    calculateTileLayers();
}

void Hill::tick() {
    Tile::tick();
    if(Main.game.getManager().getSelectedTile()==this){
        changeHeight();
        changeLength();
    }
}

void Hill::changeHeight() {
    elapsed = timer.getElapsedTime();
    if(Keyboard::isKeyPressed(Keyboard::LShift)&&elapsed.asMilliseconds()>100){
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            blocks+=2;
        } else if(blocks>=2&&Keyboard::isKeyPressed(Keyboard::Up)){
            blocks-=2;
        }
        timer.restart();
        this->setHeight(((blocks/2)+1)*60);
        calculateTileLayers();
    }
}

void Hill::calculateTileLayers() {
    Image[][] tile = new Image[(2+blocks)/2][2];
    tile[0][0] = getTypeTextures()[2];
    tile[0][1] = getTypeTextures()[3];
    for(int i = 1; i<tile.length; i++){
        tile[i][0] = getTypeTextures()[0];
        tile[i][1] = getTypeTextures()[1];
    }
    Main.game.getManager().getTileLayouts().put(getUUID(),tile);
}
