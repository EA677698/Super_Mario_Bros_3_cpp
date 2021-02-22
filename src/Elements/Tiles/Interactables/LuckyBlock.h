//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_LUCKYBLOCK_H
#define SUPER_MARIO_BROS_3_C_LUCKYBLOCK_H
#include "Interactable.h"
#include "../../Entities/Entity.h"
#include "../../Entities/NotLiving/Coin.h"

class LuckyBlock : public Interactable {

private:
    Entity containedEntity;
    Clock timer,executeTimer;
    Time elapsed;

public:
    LuckyBlock(Layer layer, Point Location, bool collision, Coin *containedEntity);
    void tick();
    void executeOnTouch();
    string to_string();
    Sprite getSprite();
};


#endif //SUPER_MARIO_BROS_3_C_LUCKYBLOCK_H
