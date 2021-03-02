//
// Created by Erick on 2/20/2021.
//

#include "Tool.h"

Tool::Tool(Elements::Layer layer, Point location, bool collision, int middleBlocks, int layers) : Tile(layer, location, collision){
    Tool::layers = layers;
    Tool::middleBlocks = middleBlocks;
    setWidth(60+(middleBlocks*60));
    hitBox.setBounds(Tile::width, Tile::height, 0,0);
}

void Tool::tick() {
    Tile::tick();
}

void Tool::changeLength() {
    Adjustables::changeLength();
}

void Tool::changeHeight() {
    Adjustables::changeHeight();
}

void Tool::calculateTileLayers() {
    LayeredTile::calculateTileLayers();
}
