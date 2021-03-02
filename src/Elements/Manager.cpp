//
// Created by Erick on 2/21/2021.
//

#include "Manager.h"
#include "Tiles/BigBlocks.h"
#include "Tiles/Clouds.h"
#include "Tiles/Interactables/Pipes.h"
#include "Entities/Enemies/HammerBro.h"
#include "Tiles/Hill.h"
#include "Tiles/Interactables/Bricks.h"
#include "Tiles/WoodenBlock.h"
#include "Tiles/Floor.h"
#include "Tiles/Interactables/LuckyBlock.h"
#include "Entities/NotLiving/GreenMushroom.h"
#include "Entities/NotLiving/RedMushroom.h"
#include "Entities/Enemies/KoopaTroopa.h"
#include "Entities/Enemies/Goomba.h"
#include "Entities/NotLiving/Fireball.h"
#include "Tiles/Shrub.h"
#include "../Main/Global.cpp"
#include "../Settings/Settings.cpp"
#include "../Tools/Clip.h"
#include "../Tools/GeneralTools.cpp"
#include "../Tools/Trigger.h"

Manager::Manager() {}

bool Manager::commandInput(string input) {
    if(contains(input," ")) {
        string end = input.substr(input.find(" ") + 1);
        string commands[] = {"spawn","remove","add","freeze","background","save","load","bgm"};
        int ret = string_match(input.substr(0, input.find(" ")-1), commands, 8);
        switch (ret) {
            case 1:
                return spawnElement(end);
            case 2:
                return removeElement(end);
            case 3:
                return addStats(end);
            case 4:
                return freezeElements(end);
            case 5:
                try {
                    level->background = string_to_background(toUpper(end));
                } catch (int e) {
                    cout<<"An error has occured: "<<e<<endl;
                }
                return true;
            case 6:
//                Saver.world = stoi(end.substr(0,end.find(" ")));
//                Saver.level = stoi(end.substr(end.find(" ")+1));
//                Saver.createLevel();
                return true;
            case 7:
//                Loader.loadLevel(end);
                return true;
            case 8:
                level->bgm = toUpper(end);
                return true;
        }
    } else {
        string commands[] = {"debug","fps","hitbox","crt","quit","unload","mute"};
        int ret = string_match(input, commands,7);
        switch (ret){
            case 0:
                debug = !debug;
                return true;
            case 1:
                fps = !fps;
                return true;
            case 2:
                hitBoxes = !hitBoxes;
                return true;
            case 3:
                crt = !crt;
                return true;
            case 4:
                exit(0);
                return true;
            case 5:
                ents.clear();
                tiles.clear();
                level = new Level(Level::AQUA_BACKGROUND, "C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\BGM\\grassland.wav");
                return true;
            case 6:
                muted = !muted;
        }
    }
    return false;
}

bool Manager::addStats(string stat) {
    int end = stoi(stat.substr(stat.find(" ")-1));
    string commands[] = {"score","money","lives"};
    int ret = string_match(stat.substr(0,stat.find(" ")), commands, 3);
    switch (ret){
        case 0:
            Global::score += end;
            return true;
        case 1:
            Global::money += end;
            return true;
        case 2:
            Global::lives += end;
            return true;
    }
    return false;
}

bool Manager::freezeElements(string element) {
    string entities[] = {"all","goomba","enemies","koopatroopa","fireball","hammerbro"};
    int ret = string_match(element,entities,6);
    switch (ret){
        case 0:
            for(Entity *entity: ents){
                entity->setAllowedMoving(!entity->isAllowedMoving());
            }
            return true;
        case 1:
            for(Entity *entity: ents){
                if(Goomba* ent = dynamic_cast<Goomba*>(entity)){
                    entity->setAllowedMoving(!entity->isAllowedMoving());
                }
            }
            return true;
        case 2:
            for(Entity *entity: ents){
                if(Enemy* ent = dynamic_cast<Enemy*>(entity)){
                    entity->setAllowedMoving(!entity->isAllowedMoving());
                }
            }
            return true;
        case 3:
            for(Entity *entity: ents){
                if(KoopaTroopa* ent = dynamic_cast<KoopaTroopa*>(entity)){
                    entity->setAllowedMoving(!entity->isAllowedMoving());
                }
            }
            return true;
        case 4:
            for(Entity *entity: ents){
                if(Fireball* ent = dynamic_cast<Fireball*>(entity)){
                    entity->setAllowedMoving(!entity->isAllowedMoving());
                }
            }
            return true;
        case 5:
            for(Entity *entity: ents){
                if(HammerBro* ent = dynamic_cast<HammerBro*>(entity)){
                    entity->setAllowedMoving(!entity->isAllowedMoving());
                }
            }
            return true;
    }
    return false;
}

void Manager::resetEntities() {
    for(Entity *ent: ents){
        ent->removeFromLayer();
    }
    ents.erase(ents.begin(),ents.end());
}

void Manager::resetTiles() {
    for(Tile *tile: tiles){
        tile->removeFromLayer();
    }
    tiles.erase(tiles.begin(),tiles.end());
}

void Manager::select() {
    for(Entity *ent: ents){
        if(ent->getHitBox().intersects(mouseHitBox)){
            if(selectedEntity!= nullptr){
                selectedEntity->setDirection(previousDirection);
                selectedEntity->setSelected(false);
            }
            selectedEntity = ent;
            selectedEntity->setSelected(true);
            selectedTile = nullptr;
            previousDirection = selectedEntity->getDirection();
            selectedEntity->setDirection(0);
            return;
        }
    }
    for(Tile *tile: tiles){
        if(tile->getHitBox().intersects(mouseHitBox)){
            selectedTile = tile;
            if(selectedEntity!= nullptr){
                selectedEntity->setDirection(previousDirection);
                selectedEntity->setSelected(false);
                return;
            }
        }
    }
}

void Manager::freeEntity() {
    if(selectedEntity!= nullptr){
        elapsed = timer1.getElapsedTime();
        if(elapsed.asMilliseconds()>100){
            if(SIX&&selectedEntity->getDirection()==0){
                selectedEntity->setDirection(previousDirection);
            } else{
                if(SIX&&selectedEntity->getDirection()!=0){
                    selectedEntity->setDirection(0);
                }
            }
            timer1.restart();
        }
    }
}

void Manager::culling() {
    //Checks to see if the element is within the screen's boundaries otherwise it unloads it
    for(Entity *entity: ents){
        //entity.setUnloaded(!screen.intersects(entity.getHitBox()) && !screen.contains(entity.getHitBox()));
        entity->setUnloaded((entity->getHitBox().getMinX()<0&&entity->getHitBox().getMaxX()<0)||
                           (entity->getHitBox().getMinX()>1920&&entity->getHitBox().getMaxX()>1920)||(entity->getHitBox().getMinY()>840&&entity->getHitBox().getMaxY()>840)||
                           (entity->getHitBox().getMinY()<0&&entity->getHitBox().getMaxY()<0));
    }
    for(Tile *tile: tiles){
        tile->setUnloaded((tile->getHitBox().getMinX()<0&&tile->getHitBox().getMaxX()<0)||
                         (tile->getHitBox().getMinX()>1920&&tile->getHitBox().getMaxX()>1920)||(tile->getHitBox().getMinY()>840&&tile->getHitBox().getMaxY()>840)||
                         (tile->getHitBox().getMinY()<0&&tile->getHitBox().getMaxY()<0));
        //tile.setUnloaded(!screen.intersects(tile.getHitBox()) && !screen.contains(tile.getHitBox()));
    }
}

void Manager::tick() {
    if(debug){
        freeEntity();
    }
    sideScroll();
    collision();
    culling();
    if(debug&&!CONSOLE){
        deleteSelected();
    }
}

void Manager::marioCheck() {
    if(mario!= nullptr){
        mario->removeFromLayer();
        vecRemove(mario,ents);
        mario = nullptr;
    }
}

bool Manager::removeElement(string element) {
    if(element=="entities"){
        resetEntities();
        return true;
    } else if(element=="tiles"){
        resetTiles();
        return true;
    }
    return false;
}

bool Manager::spawnElement(string element) {
    String temp;
    Point location(Global::windowSize.width/2,Global::windowSize.height/2);
    if(contains(element," ")){
        temp = element.substr(0, element.find(" "));
    } else {
        temp = element;
    }
    string entities[] = {"mario","goomba","koopatroopa","redmushroom","greenmushroom","coin","floor","woodenblock","luckyblock"
            ,"hill1","hill2","brick","firehammerbro","pipe","cloud1","bg","bp","bb","bw","shrub","clip","trigger"};
    int ret = string_match(temp, entities ,22);
    switch (ret){
        case 0:
            marioCheck();
            ents.push_back(new Player(Elements::MIDDLE_LAYER, location,60,60, true));
            return true;
        case 1:
            ents.push_back(new Goomba(Elements::MIDDLE_LAYER, location,60,60,1, true));
            return true;
        case 2:
            ents.push_back(new KoopaTroopa(Elements::MIDDLE_LAYER, location,60,98,1, true));
            return true;
        case 3:
            ents.push_back(new RedMushroom(Elements::MIDDLE_LAYER, location,60,60,1,true));
            return true;
        case 4:
            ents.push_back(new GreenMushroom(Elements::MIDDLE_LAYER, location,60,60,1,true));
            return true;
        case 5:
            ents.push_back(new Coin(Elements::MIDDLE_LAYER, &location,60,60,0,true,global));
            return true;
        case 6:
            tiles.push_back(new Floor(Elements::MIDDLE_LAYER, location,true,8,1));
            return true;
        case 7:
            tiles.push_back(new WoodenBlock(Elements::MIDDLE_LAYER, location,true));
            return true;
        case 8:
            tiles.push_back(new LuckyBlock(Elements::MIDDLE_LAYER, location,true, new Coin(Elements::NONE, new Point(0,0),70,80,0,true,global)));
            return true;
        case 9:
            tiles.push_back(new Hill(Elements::BACK_LAYER, location,false,2,8));
            return true;
        case 10:
            tiles.push_back(new Hill(Elements::BACK_LAYER, location,false,1,8));
            return true;
        case 11:
            tiles.push_back(new Bricks(Elements::MIDDLE_LAYER, location,true,true));
            return true;
        case 12:
            ents.push_back(new HammerBro(Elements::MIDDLE_LAYER, location,60,98,-1,true,3));
            return true;
        case 13:
            tiles.push_back(new Pipes(Elements::MIDDLE_LAYER, location,true,4));
            return true;
        case 14:
            tiles.push_back(new Clouds(Elements::BACK_LAYER, location, false ,1));
            return true;
        case 15:
            tiles.push_back(new BigBlocks(Elements::BACK_LAYER, location,true,0,0,0));
            return true;
        case 16:
            tiles.push_back(new BigBlocks(Elements::BACK_LAYER, location,true,2,0,0));
            return true;
        case 17:
            tiles.push_back(new BigBlocks(Elements::BACK_LAYER, location,true,1,0,0));
            return true;
        case 18:
            tiles.push_back(new BigBlocks(Elements::BACK_LAYER, location,true,3,0,0));
            return true;
        case 19:
            tiles.push_back(new Shrub(Elements::BACK_LAYER,location,false));
            return true;
        case 20:
            tiles.push_back(new Clip(Elements::FRONT_LAYER, location,0,1));
            return true;
        case 21:
            String command = element.substr(element.find(" ")+1, element.find_last_of(" "));
            int activations = stoi(element.substr(element.find_last_of(" ")+1));
            tiles.push_back(new Trigger(Elements::FRONT_LAYER, location, 0,1, command, activations));
            return true;
    }
    return false;
}

void Manager::deleteSelected() {
    if(selectedEntity!= nullptr){
        if(DELETE){
            if(selectedEntity==mario){
                marioCheck();
            }
            selectedEntity->removeFromLayer();
            vecRemove(selectedEntity,ents);
            selectedEntity = nullptr;
        }
    }
    if(selectedTile!= nullptr){
        if(DELETE){
            selectedTile->removeFromLayer();
            vecRemove(selectedTile,tiles);
            selectedTile = nullptr;
        }
    }
}

void Manager::sideScroll() {
    if(debug&&!SHIFT){
        elapsed = debugScroll.getElapsedTime();
        if(elapsed.asMilliseconds()>70){
            if(Keyboard::isKeyPressed(Keyboard::Right)){
                for(Entity *ent: ents){
                    if(ent!=mario){
                        ent->addX(-60);
                    }
                }
                for(Tile *tile : tiles){
                    tile->addX(-60);
                }
            } else if(Keyboard::isKeyPressed(Keyboard::Left)){
                for(Entity *ent: ents){
                    if(ent!=mario){
                        ent->addX(60);
                    }
                }
                for(Tile *tile : tiles){
                    tile->addX(60);
                }
            }
            debugScroll.restart();
        }
        return;
    }
    if(mario == nullptr){
        for(Entity *ent: ents){
            if(Player* ent = dynamic_cast<Player*>(ent)){
                mario = ent;
            }
        }
    }
    if(mario == nullptr){
        return;
    }
    if(!mario->isDead()){
        if(mario->isMiddleH()&&JUMP){
            for(Entity *ent: ents){
                if(ent!=mario){
                    ent->addY(5);
                }
            }
            for(Tile *tile : tiles){
                tile->addY(5);
            }
        } else {
            if(mario->isStartH()){
                for(Entity *ent: ents){
                    if(ent!=mario){
                        ent->addY(-5);
                    }
                }
                for(Tile *tile : tiles){
                    tile->addY(-5);
                }
            }
        }
        if(mario->isMiddle()){
            for(Entity *ent: ents){
                if(ent!=mario){
                    ent->addX((int)(-1*mario->getXVelocity()));
                }
            }
            for(Tile *tile : tiles){
                tile->addX((int)(-1*mario->getXVelocity()));
            }
        } else {
            if(mario->isStart()){
                for(Entity *ent: ents){
                    if(ent!=mario){
                        ent->addX((int)mario->getXVelocity());
                    }
                }
                for(Tile *tile : tiles){
                    tile->addX((int)mario->getXVelocity());
                }
            }
        }
    }
}

void Manager::collision() {
    for(Entity *ent : ents){
        if(ent->isCollision()&&!ent->isUnloaded()){
            if(mario!= nullptr){
                if(Enemy* entity = dynamic_cast<Enemy*>(ent)){
                    elapsed = hitTimer.getElapsedTime();
                    if(elapsed.asMilliseconds()>2000){
                        // If an enemy hits mario from his sides
                        int side = ent->getHitBox().outcode(mario->getHitBox().getCenterX(),mario->getHitBox().getCenterY());
                        if(mario->getHitBox().intersects(ent->getHitBox())){
                            if(side==1||side==4){
                                switch (mario->getPower()){
                                    case Player::SMALL: mario->setDead(true);
                                        global.player.stop();
                                        global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\1down.wav");
                                        break;
                                    case Player::BIG: mario->setPower(mario->SMALL);
                                        global.playSound("C:\\Users\\Erick\\Desktop\\Super_Mario_Bros_3_c++\\sounds\\SFX\\pipe.wav");
                                        break;
                                    default: mario->setPower(mario->BIG);
                                }
                                hitTimer.restart();
                            } else {
                                if(side==2){
                                    ent->death();
                                }
                            }
                        }
                    }
                    //Activates Non Living Entity Special Action towards Mario
                } else if(NonLiving* entity = dynamic_cast<NonLiving*>(ent)){
                    if(ent->getHitBox().intersects(mario->getHitBox())){
                        entity->executeUponTouch(*mario);
                    }
                }
            }
            //If two entities collide
            for(Entity *ent2: ents){
                if(ent!=ent2) {
                    if (ent2->isCollision() && !ent2->isUnloaded()) {
                        if (Enemy* ent = dynamic_cast<Enemy*>(ent)) {
                            if(Enemy* ent2 = dynamic_cast<Enemy*>(ent2)) {
                                if (ent->getHitBox().intersects(ent2->getHitBox())) {
                                    ent->setDirection(ent->getDirection() * -1);
                                    ent2->setDirection(ent2->getDirection() * -1);
                                }
                            }
                        }
                    }
                }
            }
            for(Tile *tile : tiles){
                if(tile->isCollision()&&!tile->isUnloaded()){
                    if(tile->getHitBox().intersects(ent->getHitBox())){
                        //If an entity hits something from his sides while moving
                        int side = tile->getHitBox().outcode(ent->getHitBox().getCenterX(),ent->getHitBox().getCenterY());
                        if(BigBlocks* temp = dynamic_cast<BigBlocks*>(tile)){
                            if(side==8||side==9||side==12) {
                                if(Player* ent = dynamic_cast<Player*>(ent)){
                                    ent->setYVelocity(0);
                                    ent->setHasGravity(true);
                                }
                            }
                        } else if(side==1||side==4||side==9||side==12){
                            if (ent->isFacingTile(tile)) {
                                if (Player *ent = dynamic_cast<Player *>(ent)) {
                                    if (ent->getDirection() == 1) {
                                        mario->setXVelocity(0);
                                        RIGHT = false;
                                    } else {
                                        mario->setXVelocity(0);
                                        LEFT = false;
                                    }
                                } else {
                                    ent->setDirection(ent->getDirection() * -1);
                                }
                            } //If Mario Hits something above him while jumping
                        }
                    }
                }
            }
        }
    }
}

Entity *Manager::getSelectedEntity() const {
    return selectedEntity;
}

void Manager::setSelectedEntity(Entity *selectedEntity) {
    Manager::selectedEntity = selectedEntity;
}

Tile *Manager::getSelectedTile() const {
    return selectedTile;
}

void Manager::setSelectedTile(Tile *selectedTile) {
    Manager::selectedTile = selectedTile;
}

Player *Manager::getMario() const {
    return mario;
}

void Manager::setMario(Player *mario) {
    Manager::mario = mario;
}

Level *Manager::getLevel() const {
    return level;
}

void Manager::setLevel(Level *level) {
    Manager::level = level;
}

const vector<Tile *> &Manager::getTiles() const {
    return tiles;
}

const HitBox &Manager::getScreen() const {
    return screen;
}

int Manager::getPreviousDirection() const {
    return previousDirection;
}

const vector<Entity *> &Manager::getEnts() const {
    return ents;
}

void Manager::setPreviousDirection(int previousDirection) {
    Manager::previousDirection = previousDirection;
}

void Manager::setPlayer(Player &mario) {
    Manager::mario = &mario;
}

Player* Manager::getPlayer() {
    return mario;
}
