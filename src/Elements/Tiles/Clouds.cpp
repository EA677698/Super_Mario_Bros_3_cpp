//
// Created by Erick on 2/20/2021.
//

#include "Clouds.h"

Clouds::Clouds(Elements::Layer layer, Point location, bool collision, int type, Global global) : Tile(layer, location, collision, global) {
    Clouds::type = type;
}

Sprite Clouds::getSprites() {
    return Sprite();
}

//void Clouds::calculateTileLayers() {
//    Image[][] tile = new Image[2][3];
//    int index = 0;
//    for(int i = 0; i<tile.length; i++){
//        for(int e = 0; e<tile[0].length; e++){
//            tile[i][e] = Main.game.getSpritesLoader().getClouds()[index];
//            index++;
//        }
//    }
//    Main.game.getManager().getTileLayouts().put(getUUID(),tile);
//}
