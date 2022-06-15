#include <iostream>
#include <SFML/Graphics.hpp>


int main(int argc, char** arvg) {

    sf::RenderWindow window( sf::VideoMode(1280, 720), "Sprite Animation");
    sf::Event e;


    while( window.isOpen() ) {
        while( window.pollEvent(e) )
            if( e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape)
                window.close();
    
    
        window.clear();
    
    
        window.display();
    }
    return 0;
}