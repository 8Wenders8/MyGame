#ifndef GAMEENG_BUTTON_H
#define GAMEENG_BUTTON_H

/** Button class to control the game functions. */

#include<iostream>
#include<ctime>
#include<sstream>
#include<fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button {
private:
    /* Variables */
    short unsigned buttonState;

    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height, sf::Font *font, std::string text,  sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    virtual ~Button();

    /* Accessors */
    const bool isPressed() const;

    /* Functions */
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);
};


#endif //GAMEENG_BUTTON_H
