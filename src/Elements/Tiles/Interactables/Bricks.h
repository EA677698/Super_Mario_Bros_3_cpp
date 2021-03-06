//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_BRICKS_H
#define SUPER_MARIO_BROS_3_C_BRICKS_H
#include "Interactable.h"
#include "../../Entities/Entity.h"
#include "../../../Tools/GeneralTools.cpp"
#include "../../../Main/Global.h"

class Bricks : public Interactable{

private:
    Global *global;
    sf::Clock executeTimer, timer;
    sf::Time elapsed;
    Entity containedEntity;
    bool breakable;
public:
    const Entity &getContainedEntity() const;
    bool isBreakable() const;
    Bricks(Layer layer, Point location, bool collision, Entity containedEntity, Global global);
    Bricks(Layer layer, Point location, bool collision, bool breakable, Global global);
    void tick();
    void executeOnTouch() override;
    sf::Sprite getSprite();
    string to_string();
};


#endif //SUPER_MARIO_BROS_3_C_BRICKS_H
