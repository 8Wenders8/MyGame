#include "Game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.bitsPerPixel=32;
    this->videoMode.width = 1920;
    this->videoMode.height = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1",sf::Style::Fullscreen);
    //this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}
//Accessors
const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}
//Functions
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
            case sf::Event::KeyPressed:
                if (this->sfEvent.key.code == sf::Keyboard::Escape)
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
    this->window->display();
}
