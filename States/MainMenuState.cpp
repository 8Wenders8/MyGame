#include "MainMenuState.h"

/* Private functions */
void MainMenuState::initKeybinds() {
    std::ifstream keys_file("../Config/gamestate_keybinds.ini");

    if(keys_file.is_open()){
        std::string key = "";
        std::string key2 = "";
        while(keys_file >> key >> key2){
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    keys_file.close();
}

/* Constructors - Destructors */
MainMenuState::MainMenuState(sf::RenderWindow *StateWindow, std::map<std::string, int> *supportedKeys) : State(StateWindow,supportedKeys) {
    this->initKeybinds();
}

MainMenuState::~MainMenuState(){

}

/* Functions */
void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();
}

void MainMenuState::endState() {
    std::cout<<"Quitting\n";
}

void MainMenuState::update(const float& dt) {
    this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->StateWindow;
}