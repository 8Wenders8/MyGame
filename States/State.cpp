#include "State.h"



//Constructors / Destructors
State::State(sf::RenderWindow *StateWindow)
{
    this->StateWindow = StateWindow;
    this->quit = false;
}
State::~State()
{

}

void State::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->quit = true;
    }
}

const bool &State::getQuit() const {
    return this->quit;
}
