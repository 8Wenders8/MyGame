/*
 Wrapper for game.
*/
#pragma once
#include "States/GameState.h"

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

    //Private functions
    void initVariables();
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
