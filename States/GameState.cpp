#include "GameState.h"
//Private functions
void GameState::initKeybinds() {
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

void GameState::initTextures() {
    if(!this->textures["PLAYER_IDLE"].loadFromFile("../Assets/Images/Sprites/Player/test.png")){
        throw("ERROR::GAMESTATE::FAILED TO LOAD PLAYER IDLE TEXTURE"); }
}
void GameState::initPlayers() {
    this->player = new Player(50, 50, this->textures["PLAYER_IDLE"]);
}


//Constructors / Destructors
GameState::GameState(sf::RenderWindow *stateWindow, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(stateWindow, supportedKeys, states)
{
    this->initKeybinds();
    this->initTextures();
    this->initPlayers();
}
GameState::~GameState()
{
    delete this->player;
}

void GameState::updateInput(const float &dt) {
    /* Update player input */
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        this->endState();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player->move(dt,-1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player->move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player->move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player->move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);
    this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->stateWindow;

    this->player->render(this->stateWindow);
}
