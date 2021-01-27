#include "MainMenuState.h"

/* Private - Initializer functions */
void MainMenuState::initVariables() {

}

void MainMenuState::initBackgrounds() {
    this->background.setSize(sf::Vector2f(static_cast<float>(this->stateWindow->getSize().x), static_cast<float>(this->stateWindow->getSize().y)));
    if(!this->backgroundTexture.loadFromFile("../Assets/Images/Backgrounds/lofi2.jpg")){
        throw("ERROR::MAINMENUSTATE::FAILED TO LOAD BACKGROUND");
    }
    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts() {
    if(!this->font.loadFromFile("../Fonts/Dosis-Medium.ttf")){
        throw("ERROR::MAINMENUSTATE::FAILED TO LOAD FONT");
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
            (120.f, 580.f, 150.f, 50.f, &this->font, "New Game", 30,
             sf::Color(170,170,170,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
             sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0)
             );

    this->buttons["SETTINGS_STATE"] = new Button
            (120.f, 680.f, 150.f, 50.f, &this->font, "Settings", 30,
             sf::Color(170,170,170,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
             sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0)
            );

    this->buttons["EDITOR_STATE"] = new Button
            (120.f, 780.f, 150.f, 50.f, &this->font, "Editor", 30,
             sf::Color(170,170,170,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
             sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0)
            );

    this->buttons["EXIT_STATE"] = new Button
            (120.f, 880.f, 150.f, 50.f, &this->font, "Quit", 30,
             sf::Color(170,170,170,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
             sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0)
            );
}
/* Constructors - Destructors */
MainMenuState::MainMenuState(sf::RenderWindow *stateWindow, std::map<std::string, int> *supportedKeys, std::stack<State*>* states) : State(stateWindow, supportedKeys, states) {
    this->initVariables();
    this->initBackgrounds();
    this->initFonts();
    this->initButtons();
    this->initKeybinds();
}

MainMenuState::~MainMenuState(){
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
        delete it->second;
    }
}

/* Functions */
void MainMenuState::updateInput(const float &dt) {

}
void MainMenuState::updateButtons() {
    /* Updates all the buttons in the state and handles their functionality */
    for(auto &it : this->buttons){
        it.second->update(this->mousePosView);
    }
    /* New game */
    if(this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->stateWindow, this->supportedKeys, this->states));
    }

    /* Quit the game */
    if(this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
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
        target = this->stateWindow;
    target->draw(this->background);
    this->renderButtons(target);

    /* Just for debugging, remove later //TODO */
    /*sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 30);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << ", " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);*/
}
