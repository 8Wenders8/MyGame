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

    sf::Color textIdleColor;
    sf::Color textHoverColor;
    sf::Color textActiveColor;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height,
           sf::Font *font, std::string text, unsigned char_size,
           sf::Color text_idle_color, sf::Color text_hover_color ,sf::Color text_active_color,
           sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
    virtual ~Button();

    /* Accessors */
    const bool isPressed() const;

    /* Functions */
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);
};


#endif //GAMEENG_BUTTON_H
