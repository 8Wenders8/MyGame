/*
 Wrapper for game.
*/
#pragma once
#include "State.h"

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt; // deltaTime

    //Private functions
    void initVariables();
    void initWindow();
public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool getWindowIsOpen() const;

    //Functions
    void pollEvents();
    void updateDeltaTime();
    void update();
    void render();
};
