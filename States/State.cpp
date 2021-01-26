#include "State.h"
/* Constructors - Destructors */
State::State(sf::RenderWindow *stateWindow, std::map<std::string, int>*  supportedKeys, std::stack<State*>* states)
{
    this->stateWindow = stateWindow;
    this->states = states;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}
State::~State()
{

}
/* Functions */
void State::endState() {
    this->quit = true;
}

const bool &State::getQuit() const {
    return this->quit;
}

void State::updateMousePositions() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->stateWindow);
    this->mousePosView = this->stateWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->stateWindow));
}

