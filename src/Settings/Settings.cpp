//
// Created by Erick on 2/20/2021.
//


#include "../Main/Global.h"

bool debug = false;
bool hitBoxes = false;
bool crt = false;
bool fps = false;
bool muted = false;
int fpsCap = 100000;
int tpsCap = 100000;

void tick(Global global){
    if(!debug){
        if(global.manager->getSelectedEntity()!= nullptr){
            global.manager->getSelectedEntity()->setSelected(false);
            global.manager->getSelectedEntity()->setDirection(global.manager->getPreviousDirection());
            global.manager->setSelectedEntity(nullptr);
        }
        if(global.manager->getSelectedTile()!= nullptr){
            global.manager->setSelectedTile(nullptr);
        }
    }
}
