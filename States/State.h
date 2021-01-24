#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<fstream>
#include<stack>
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {
private:
    sf::RenderWindow *StateWindow;
    std::vector<sf::Texture> textures;
    bool quit;

public:
    State(sf::RenderWindow *StateWindow);
    virtual ~State();
    virtual void checkForQuit();

    const bool& getQuit() const;

    virtual void endState() = 0;
    virtual void updateKeybinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

