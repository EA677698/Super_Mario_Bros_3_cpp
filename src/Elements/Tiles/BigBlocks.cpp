//
// Created by Erick on 2/20/2021.
//

#include "BigBlocks.h"
int BigBlocks::getType() const {
    return type;
}

void BigBlocks::setType(int type) {
    BigBlocks::type = type;
}

int BigBlocks::getExtraYLayers() const {
    return extraYLayers;
}

void BigBlocks::setExtraYLayers(int extraYLayers) {
    BigBlocks::extraYLayers = extraYLayers;
}

int BigBlocks::getExtraXLayers() const {
    return extraXLayers;
}

void BigBlocks::setExtraXLayers(int extraXLayers) {
    BigBlocks::extraXLayers = extraXLayers;
}

BigBlocks::BigBlocks(Elements::Layer layer, Point location, bool collision, int type, int rows, int columns, Global global) : Tile(layer, location, collision, global){
    this->type = type;
    extraYLayers = columns;
    extraXLayers = rows;
    setTileName("BigBlock");
    calculateTileLayers();
}

void BigBlocks::tick() {
    Tile::tick();
}

void BigBlocks::changeLength() {
    elapsed = timerX.getElapsedTime();
    if(SHIFT&&elapsed.asMilliseconds()>100){
        if(RIGHT){
            extraYLayers++;
        } else if(LEFT&&extraYLayers>-1){
            extraYLayers--;
        }
        setWidth(180+(60*extraYLayers));
        calculateTileLayers();
        timerX.restart();
    }
}

void BigBlocks::changeHeight() {
    elapsed = timerY.getElapsedTime();
    if(SHIFT&&elapsed.asMilliseconds()>100){
        if(DOWN){
            extraXLayers++;
        } else if(UP){
            if(extraXLayers>-1){
                extraXLayers--;
            }
        }
        setHeight(180+(60*extraXLayers));
        calculateTileLayers();
        timerY.restart();
    }
}

Sprite BigBlocks::getTypeTextures() {
    return Sprite();
}

//void BigBlocks::calculateTileLayers() {
//    Image[][] ret = new Image[3+extraXLayers][3];
//    int index = 1;
//    ret[0] = new Image[]{getTypeTextures()[0], getTypeTextures()[1], getTypeTextures()[2]};
//    for(int i = 0; i<extraXLayers+1; i++){
//        ret[index] = new Image[]{getTypeTextures()[3], getTypeTextures()[4], getTypeTextures()[5]};
//        index++;
//    }
//    ret[ret.length-1] = new Image[]{getTypeTextures()[6], getTypeTextures()[7], getTypeTextures()[8]};
//    Image[][] tile = new Image[ret.length][ret[0].length+extraYLayers];
//    for(int i = 0; i<ret.length; i++){
//        for(int e = tile[0].length-1; e>-1; e--){
//            if(e == tile[0].length-1){
//                tile[i][tile[0].length-1] = ret[i][ret[0].length-1];
//            } else {
//                tile[i][e] = ret[i][1];
//            }
//            if(e == 0){
//                tile[i][e] = ret[i][0];
//            }
//        }
//    }
//    Main.game.getManager().getTileLayouts().put(getUUID(),tile);
//}

void BigBlocks::to_string() {

}
