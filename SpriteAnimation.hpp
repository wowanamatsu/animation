#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animate {

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect rectSourceSprite;
    sf::Clock clock;

    /* 
        sW              = source width
        sH              = source height
        sliceWidth      = width
        sliceHeight     = altura do quado recortado do sprite
    */
    int sW, sH, sliceWidth, sliceHeight;

public:

    Animate( std::string file_name, int _sW=0, int _sH=0, int _sliceWidth=16, int _sliceHeight=16 ) {
        rectSourceSprite = sf::IntRect( _sW, _sH, _sliceWidth, _sliceHeight );
        sW = _sW;
        sH = _sH;
        sliceWidth = _sliceWidth;
        sliceHeight = _sliceHeight;
        texture.loadFromFile( file_name );
        sprite.setTexture( texture );
        sprite.setTextureRect( rectSourceSprite );
    }

    void setScale( float x, float y ) {
        sprite.setScale( x, y );
    }

    void render( sf::RenderWindow& window ) {
        update();
        window.draw( sprite );
    }

    void update() {
        if( clock.getElapsedTime().asSeconds() > .2f) {
            if( rectSourceSprite.left == width()-sliceWidth ) {
                rectSourceSprite.left = 0;
            } else {
                rectSourceSprite.left += sliceWidth;
            }

            sprite.setTextureRect( rectSourceSprite );
            clock.restart();
        }
    }
    
    int width() { return texture.getSize().x; }
    int height() { return texture.getSize().y; }

};