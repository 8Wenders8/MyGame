#pragma once

#include "../Entities/Entity.h"

class State {
protected:
    sf::RenderWindow *StateWindow;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;
    /* Mouuse position variables */
    sf::Vector2u mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Resources
    std::vector<sf::Texture> textures;

    //Functions
    virtual void initKeybinds() = 0;
public:
    State(sf::RenderWindow *StateWindow, std::map<std::string, int>* supportedKeys);
    virtual ~State();
    virtual void checkForQuit();

    const bool& getQuit() const;

    virtual void endState() = 0;
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

