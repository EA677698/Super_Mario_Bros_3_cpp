//
// Created by Erick on 2/21/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_MANAGER_H
#define SUPER_MARIO_BROS_3_C_MANAGER_H
#include <vector>
#include <map>
#include "Entities/Entity.h"
#include "Tiles/Tile.h"
#include "Entities/Mario/Player.h"
#include "../Level/Level.h"
using namespace std;

class Manager {

private:
    vector<Tile*> tiles;
    Player *mario;
//map<UUID, >
    Level *level;
    HitBox screen;
    Clock timer1, hitTimer, debugScroll;
    Time elapsed;
    Entity *selectedEntity;
    Tile *selectedTile;
    int previousDirection;
    vector<Entity*> ents;
    Global global;


public:


    void setPreviousDirection(int previousDirection);

    const vector<Tile *> &getTiles() const;

    const HitBox &getScreen() const;

    int getPreviousDirection() const;

    vector<Entity *> &getEnts();

    Entity *getSelectedEntity() const;

    void setSelectedEntity(Entity *selectedEntity);

    Tile *getSelectedTile() const;

    void setSelectedTile(Tile *selectedTile);

    Player *getMario() const;

    void setMario(Player *mario);

    Level *getLevel() const;

    void setLevel(Level *level);
    Manager(Global global);
    bool commandInput(string input);
    bool addStats(string stat);
    bool freezeElements(string element);
    void resetEntities();
    void resetTiles();
    void select();
    void freeEntity();
    void culling();
    void tick();
    void marioCheck();
    bool removeElement(string element);
    bool spawnElement(string element);
    void deleteSelected();
    void sideScroll();
    void collision();
    Player* getPlayer();
    void setPlayer(Player &mario);
};


#endif //SUPER_MARIO_BROS_3_C_MANAGER_H
