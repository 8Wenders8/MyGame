#include "GameState.h"
//Private functions
void GameState::initKeybinds() {
    this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow *StateWindow, std::map<std::string, int>* supportedKeys) : State(StateWindow, supportedKeys)
{
    this->initKeybinds();
}
GameState::~GameState()
{

}

void GameState::updateInput(const float &dt) {
    this->checkForQuit();

    //Update player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt,-1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
}

void GameState::endState() {
    std::cout<<"Quitting\n";
}

void GameState::update(const float& dt) {
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->StateWindow;

    this->player.render(this->StateWindow);
}
