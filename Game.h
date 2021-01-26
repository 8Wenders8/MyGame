/*
 Wrapper for game.
*/
#pragma once
#include "States/MainMenuState.h"

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt; // deltaTime

    std::stack<State*> states;

    std::map<std::string, int> supportedKeys;

    //Private functions
    void initVariables();
    void initKeys();
    void initStates();
    void initWindow();
public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool getWindowIsOpen() const;

    //Functions
    void pollEvents();
    void endApplication();
    //Update
    void updateDeltaTime();
    void update();

    //Render
    void render();
};
