//
// Created by Erick on 2/25/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_GLOBAL_H
#define SUPER_MARIO_BROS_3_C_GLOBAL_H
#include "../Tools/Dimension.h"
#include "../Elements/Entities/Mario/Player.h"
#include "../Elements/Manager.h"
#include <SFML/Audio.hpp>
#include <vector>

class Global{

public:
    static int score, money, lives, time;
    static Music player;
    static SoundBuffer buffer;
    static Sound sound;
    enum Cards{STAR_CARD,FLOWER_CARD,MUSHROOM_CARD,EMPTY_CARD};
    Cards cards[3];
    bool active[7];
    double scaleX, scaleY;
    static Dimension windowSize;
    void HUDCheck();
    void addCard(Cards card);
    Manager *manager;
    void scaling();
    void playSound(string path);
    Global();
};

#endif //SUPER_MARIO_BROS_3_C_GLOBAL_H
