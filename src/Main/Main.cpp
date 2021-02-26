#include <SFML/Graphics.hpp>
#include "Global.cpp"

using namespace sf;

Global global;

int main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1920, 1080), "Super Mario Bros. 3", Style::Fullscreen, settings);
    window.setSize(Vector2u(1920,1080));
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