#pragma once
#include "States/MainMenuState.h"

/* Wrapper for game. */
class Game
{
private:
    /* Variables */
    sf::RenderWindow* window;
    sf::Event sfEvent;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullscreen;

    sf::Clock dtClock;
    float dt; // deltaTime

    std::stack<State*> states;

    std::map<std::string, int> supportedKeys;

    /* Private functions */
    void initVariables();
    void initKeys();
    void initStates();
    void initWindow();
public:
    Game();
    virtual ~Game();

    /* Accessors */
    const bool getWindowIsOpen() const;

    /* Functions */
    void pollEvents();
    void endApplication();
    //Update
    void updateDeltaTime();
    void update();
    //Render
    void render();
};
