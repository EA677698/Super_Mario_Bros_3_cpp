//
// Created by Erick on 2/20/2021.
//

#include "Clip.h"

Clip::Clip(Elements::Layer layer, Point location, int middleBlocks, int layers) : Tool(layer, location,true,  middleBlocks, layers) {
    setTileName("Clip");
}
