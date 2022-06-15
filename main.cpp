#include <iostream>
#include "SpriteAnimation.hpp"


int main(int argc, char** arvg) {

    sf::RenderWindow window( sf::VideoMode(1280, 720), "Sprite Animation");
    window.setFramerateLimit(60);
    sf::Event e;

    Animate sp("./mage.png", 0, 0, 16, 16);
    sp.setScale(10, 10);


    while( window.isOpen() ) {
        while( window.pollEvent(e) )
            if( e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape)
                window.close();
    
    
        window.clear();
    
        sp.render( window );
    
        window.display();
    }
    return 0;
}