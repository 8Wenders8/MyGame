#pragma once
/** Parent class for all possible States that the game can be in. */
#include "../Entities/Entity.h"

class State {
protected:
    /* Variables */
    std::stack<State*>* states;
    sf::RenderWindow *stateWindow;
    /* Passing supported keys, so they can be bound to another keys.*/
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;
    /* Mouse position variables */
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    /* Resources */
    std::vector<sf::Texture> textures;
    /* Protected Functions -- In future may be changed to access this in private with get/set. */
    virtual void initKeybinds() = 0;
public:
    State(sf::RenderWindow *stateWindow, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~State();
    /* Return if quit key/button has been pressed */
    const bool& getQuit() const;
    /* Functions */
    void endState() ;
    virtual void updateMousePositions();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

