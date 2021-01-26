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

protected:
    /* Protected functions - might change to private and use get/set in the future. */
    sf::RectangleShape shape;
    float movementSpeed;
public:
    Entity();
    virtual ~Entity();

    /* Functions */
    virtual void move(const float& dt, const float dir_x, const float dir_y);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
#endif //GAMEENG_ENTITY_H
