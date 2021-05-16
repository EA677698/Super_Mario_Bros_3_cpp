//
// Created by Erick on 2/20/2021.
//

#include "Level.h"

Level::Level(Level::Background background, string BGM, Global global) : Elements(NONE, location, global){
    Level::background = background;
    bgm = BGM;
}


Level::Background string_to_background(string input) {
    string words[] = {"AQUA_BACKGROUND","BLUE_BACKGROUND","PINK_BACKGROUND","BLACK_BACKGROUND","ICE_BACKGROUND",
                      "CARAMEL_BACKGROUND","PORTAGE_BACKGROUND"};
    int ret = string_match(input,words,7);
    switch (ret) {
        case 0: return Level::AQUA_BACKGROUND;
        case 1: return Level::BLUE_BACKGROUND;
        case 2: return Level::PINK_BACKGROUND;
        case 3: return Level::BLACK_BACKGROUND;
        case 4: return Level::ICE_BACKGROUND;
        case 5: return Level::CARAMEL_BACKGROUND;
        case 6: return Level::PORTAGE_BACKGROUND;
    }
}
