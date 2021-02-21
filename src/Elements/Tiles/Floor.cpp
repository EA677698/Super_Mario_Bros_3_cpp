//
// Created by Erick on 2/20/2021.
//

#include "Floor.h"

Floor::Floor(Elements::Layer layer, Point location, bool collision, int middleBlocks, int layers) : Tile(layer, location, collision) {
    this->middleBlocks = middleBlocks;
    this->layers = layers;
    this->setTileName("Platform");
    this->setWidth(120+(middleBlocks*60));
    setHitBox(HitBox(0, 0, getWidth(), getHeight()));
    calculateTileLayers();
}

void Floor::tick() {
    Tile::tick();
    if(Main.game.getManager().getSelectedTile()==this){
        changeHeight();
        changeLength();
    }
}

void Floor::changeLength() {
    elapsed = timerX.getElapsedTime();
    if(Keyboard::isKeyPressed(Keyboard::LShift)&&elapsed.asMilliseconds()>100){
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            middleBlocks++;
        } else if(middleBlocks>=1&&Keyboard::isKeyPressed(Keyboard::Left)){
            middleBlocks--;
        }
        timerX.restart();
        this->setWidth(120+(middleBlocks*60));
        calculateTileLayers();
    }
}

void Floor::changeHeight() {
    elapsed = timerY.getElapsedTime();
    if(Keyboard::isKeyPressed(Keyboard::LShift)&&elapsed.asMilliseconds()>100){
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            layers++;
        } else if(layers>=1&&Keyboard::isKeyPressed(Keyboard::Up)){
            layers--;
        }
        timerY.restart();
        this->setHeight(60+(layers*60));
        calculateTileLayers();
    }
}

Sprite Floor::getSprite() {
    return Sprite();
}

void Floor::calculateTileLayers() {
    Image[][] tile = new Image[1+layers][2+middleBlocks];
    tile[0][0] = Main.game.getSpritesLoader().getFloor()[0];
    for(int i = 1; i<tile[0].length-1; i++){
        tile[0][i] = Main.game.getSpritesLoader().getFloor()[1];
    }
    tile[0][tile[0].length-1] = Main.game.getSpritesLoader().getFloor()[2];
    for(int i = 1; i<tile.length; i++){
        for(int e = 0; e<tile[0].length; e++){
            if(e==0){
                tile[i][e] = Main.game.getSpritesLoader().getFloor()[3];
            } else if(e==tile[0].length-1){
                tile[i][e] = Main.game.getSpritesLoader().getFloor()[5];
            } else {
                tile[i][e] = Main.game.getSpritesLoader().getFloor()[4];
            }
        }
    }
    Main.game.getManager().getTileLayouts().put(getUUID(),tile);
}
