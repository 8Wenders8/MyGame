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

void MainMenuState::initFonts() {
    if(!this->font.loadFromFile("../Fonts/Dosis-Medium.ttf")){
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

/* Constructors - Destructors */
MainMenuState::MainMenuState(sf::RenderWindow *StateWindow, std::map<std::string, int> *supportedKeys) : State(StateWindow,supportedKeys) {
    this->initFonts();
    this->initKeybinds();
    this->background.setSize(sf::Vector2f(StateWindow->getSize().x, StateWindow->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
    this->gameStatenBTN = new Button(100, 100, 150, 50, &this->font, "New Game", sf::Color(70,70,70,200), sf::Color(150,150,150,255),sf::Color(20,20,20,200));
}

MainMenuState::~MainMenuState(){
    delete this->gameStatenBTN;
}

/* Functions */
void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();
}

void MainMenuState::endState() {
    std::cout<<"Quitting\n";
}

void MainMenuState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);
    this->gameStatenBTN->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->StateWindow;
    target->draw(this->background);
    this->gameStatenBTN->render(target);
}