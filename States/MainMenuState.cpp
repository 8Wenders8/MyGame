#include "MainMenuState.h"

/* Private functions */
void MainMenuState::initFonts() {
    if(!this->font.loadFromFile("../Fonts/Dosis-Medium.ttf")){
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds() {
    std::ifstream keys_file("../Config/mainmenustate_keybinds.ini");

    if(keys_file.is_open()){
        std::string key = "";
        std::string key2 = "";
        while(keys_file >> key >> key2){
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    keys_file.close();
}

void MainMenuState::initButtons() {
    this->buttons["GAME_STATE"] = new Button
            (100, 100, 150, 50,&this->font, "New Game",
             sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200)
             );

    this->buttons["EXIT_STATE"] = new Button
            (100, 300, 150, 50,&this->font, "Quit",
             sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200)
            );
}
/* Constructors - Destructors */
MainMenuState::MainMenuState(sf::RenderWindow *StateWindow, std::map<std::string, int> *supportedKeys, std::stack<State*>* states) : State(StateWindow,supportedKeys, states) {
    this->initFonts();
    this->initButtons();
    this->initKeybinds();
    this->background.setSize(sf::Vector2f(StateWindow->getSize().x, StateWindow->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState(){
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
        delete it->second;
    }
}

/* Functions */
void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();
}

void MainMenuState::endState() {
    std::cout<<"Ending MainMenuState\n";
}

void MainMenuState::updateButtons() {
    /* Updates all the buttons in the state and handles their functionality */
    for(auto &it : this->buttons){
        it.second->update(this->mousePosView);
    }
    /* New game */
    if(this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->StateWindow, this->supportedKeys, this->states));
    }

    /* Quit the game */
    if(this->buttons["EXIT_STATE"]->isPressed()){
        this->quit = true;
    }

}

void MainMenuState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target) {
    for(auto &it : this->buttons){
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->StateWindow;
    target->draw(this->background);
    this->renderButtons(target);
}