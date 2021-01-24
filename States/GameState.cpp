#include "GameState.h"

//Constructors / Destructors
GameState::GameState(sf::RenderWindow *StateWindow) : State(StateWindow)
{

}
GameState::~GameState()
{

}

void GameState::updateKeybinds(const float &dt) {
    this->checkForQuit();
}

void GameState::endState() {
    std::cout<<"Quitting\n";
}

void GameState::update(const float& dt) {
    this->updateKeybinds(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        std::cout<<"B\n";
}

void GameState::render(sf::RenderTarget* target) {

}
