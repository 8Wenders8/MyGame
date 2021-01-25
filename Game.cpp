#include "Game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    std::ifstream ifs("../Config/window.ini");
    std::string title = "None";
    sf::VideoMode window_bound(1920, 1080,32);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open()){
        std::getline(ifs, title);
        ifs >> window_bound.width >> window_bound.height >> window_bound.bitsPerPixel;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->videoMode.bitsPerPixel=32;
    this->videoMode.width = 1920;
    this->videoMode.height = 1080;
    this->window = new sf::RenderWindow(window_bound, title, sf::Style::Fullscreen);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys() {
    /* Read from supported keys file and bind them.*/
    /**DEBUG INFO: I had to use ../ before Config, doesn't make sense to me but works. In every file opening.*/
    std::ifstream ifs("../Config/supported_keys.ini");
    std::cout <<  ifs.is_open();

    if(ifs.is_open()){
        std::string key = "A";
        int key_value = 0;
        while(ifs >> key >> key_value){
            this->supportedKeys[key] = key_value;
        }
    }
    ifs.close();
}

void Game::initStates() {
    this->states.push(new GameState(this->window, &this->supportedKeys));
}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}
//Accessors
const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}

//Functions


void Game::endApplication() {
    std::cout<<"Ending application\n";
}

void Game::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->sfEvent))
    {
        switch (this->sfEvent.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
        }
    }
}

void Game::updateDeltaTime()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
    this->pollEvents();

    if(!this->states.empty()){
        this->states.top()->update(this->dt);
        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else{
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    /**
        - clear old frame
        - render objects
        - display frame in window
        Renders the game objects.
    */
    this->window->clear();

    //Render items
    if(!this->states.empty()){
        this->states.top()->render(this->window);
    }

    this->window->display();
}

