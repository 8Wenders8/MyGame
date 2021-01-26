#ifndef GAMEENG_ENTITY_H
#define GAMEENG_ENTITY_H
/** Class for creating entities in the game. */
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<fstream>
#include<stack>
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Entity {
private:
    void initVariables();
protected:
    /* Variables */
    sf::Texture* texture;
    sf::Sprite* sprite;
    float movementSpeed;
    /* Protected functions - might change to private and use get/set in the future. */

public:
    Entity();
    virtual ~Entity();
    /* Component functions */
    void createSprite(sf::Texture* texture);
    /* Functions */
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float dir_x, const float dir_y);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
#endif //GAMEENG_ENTITY_H
