//
// Created by Erick on 2/20/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_ELEMENTS_H
#define SUPER_MARIO_BROS_3_C_ELEMENTS_H
#include "../Tools/Point.h"
#include "../Main/Global.h"

class Elements {

public:
    enum Layer{FRONT_LAYER,MIDDLE_LAYER,BACK_LAYER, NONE};

protected:
    Global global;
    Layer layer;
    Point location;
    bool unloaded;

public:
    Elements(Layer layer, Point &location, Global global);
    void reloadLayer();
    void removeFromLayer();
    void changeLayer(Layer layer);
    Layer getLayer();
    bool isUnloaded();
    void setUnloaded(bool isLoaded);
    Point getLocation();
    void setLocation(Point &location);
    void setLocation(const int x, const int y);
    void addX(int x);
    void addY(int y);

};


#endif //SUPER_MARIO_BROS_3_C_ELEMENTS_H
