#include "State.h"



//Constructors / Destructors
State::State(sf::RenderWindow *StateWindow, std::map<std::string, int>*  supportedKeys)
{
    this->StateWindow = StateWindow;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}
State::~State()
{

}

void State::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))){
        this->quit = true;
    }
}

const bool &State::getQuit() const {
    return this->quit;
}
