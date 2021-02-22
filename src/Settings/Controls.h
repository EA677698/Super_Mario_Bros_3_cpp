//
// Created by Erick on 2/21/2021.
//

#ifndef SUPER_MARIO_BROS_3_C_CONTROLS_H
#define SUPER_MARIO_BROS_3_C_CONTROLS_H
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

Clock timer;
bool JUMP,LEFT,RIGHT,DOWN,UP,CONTROL, ALT,SHIFT,SLASH,SELECT,SIX,CONSOLE,DELETE;

void updateControls(){
    DELETE = Keyboard::isKeyPressed(Keyboard::BackSpace);
    JUMP = Keyboard::isKeyPressed(Keyboard::C);
    UP = Keyboard::isKeyPressed(Keyboard::Up);
    LEFT = Keyboard::isKeyPressed(Keyboard::Left);
    RIGHT = Keyboard::isKeyPressed(Keyboard::Right);
    DOWN = Keyboard::isKeyPressed(Keyboard::Down);
    CONTROL = Keyboard::isKeyPressed(Keyboard::LControl);
    ALT = Keyboard::isKeyPressed(Keyboard::X);
    SHIFT = Keyboard::isKeyPressed(Keyboard::LShift);
    SLASH = Keyboard::isKeyPressed(Keyboard::Slash);
    SELECT = Keyboard::isKeyPressed(Keyboard::Enter);
    SIX = Keyboard::isKeyPressed(Keyboard::F);
    if(timer.getElapsedTime().asMilliseconds()>100){
        if(SLASH){
            CONSOLE = !CONSOLE;
        }
        timer.restart();
    }
}


#endif //SUPER_MARIO_BROS_3_C_CONTROLS_H


