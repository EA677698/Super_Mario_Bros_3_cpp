//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_LEVEL_H
#define SUPER_MARIO_BROS_3_C_LEVEL_H
#include "../Elements/Elements.h"
#include <SFML/Graphics.hpp>
#include "../Tools/GeneralTools.cpp"


class Level : public Elements{

public:

    enum Background{AQUA_BACKGROUND,BLUE_BACKGROUND,PINK_BACKGROUND,BLACK_BACKGROUND,ICE_BACKGROUND,CARAMEL_BACKGROUND,PORTAGE_BACKGROUND};
    Level(Background background);
    Background getBackground();
    //Sprite getBackgroundSprite();
    void changeBGM();
    void setBackground(Background background);



};
Level::Background string_to_background(string input);


#endif //SUPER_MARIO_BROS_3_C_LEVEL_H
