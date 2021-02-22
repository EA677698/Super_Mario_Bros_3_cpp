#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Tools/Dimension.h"
#include "../Elements/Manager.h"

using namespace sf;

Music player;
Manager game();

void scaling(){
    if(!(scaleX == (windowSize.width/1980.0)&&scaleY==(windowSize.height/1080.0))){
        scaleX = (windowSize.width/1920.0);
        scaleY = (windowSize.height/1080.0);
    }
}

int main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1920, 1080), "Super Mario Bros. 3", Style::Fullscreen, settings);
    window.setSize(Vector2u(1920,1080));
    windowSize = Dimension(1920,1080);
    scaling();
    player.openFromFile("D:\\streaming\\brb songs\\06 Corneria.flac");
    player.setLoop(true);
    player.play();
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }
        window.clear();
        //DRAW HERE
        window.display();
    }
    return 0;
}