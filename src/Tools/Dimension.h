//
// Created by Erick on 10/27/2020.
//

#ifndef FIRST_GAME_DIMENSION_H
#define FIRST_GAME_DIMENSION_H


class Dimension {

public:
    int width, height;
    Dimension();
    Dimension(int width, int height);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    void setDimension(Dimension dimension);

};


#endif //FIRST_GAME_DIMENSION_H
