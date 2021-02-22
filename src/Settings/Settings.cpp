//
// Created by Erick on 2/20/2021.
//
#include "../Main/Main.cpp"

bool debug = false;
bool hitBoxes = false;
bool crt = false;
bool fps = false;
bool muted = false;
int fpsCap = 100000;
int tpsCap = 100000;

void tick(){
    if(!debug){
        if(.getSelectedEntity()!=null){
            Main.game.getManager().getSelectedEntity().setSelected(false);
            Main.game.getManager().getSelectedEntity().setDirection(Main.game.getManager().getPreviousDirection());
            Main.game.getManager().setSelectedEntity(null);
        }
        if(Main.game.getManager().getSelectedTile()!=null){
            Main.game.getManager().setSelectedTile(null);
        }
    }
}