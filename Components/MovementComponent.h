#ifndef GAMEENG_MOVEMENTCOMPONENT_H
#define GAMEENG_MOVEMENTCOMPONENT_H

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

class MovementComponent {
private:
    /* Variables */
    sf::Sprite& sprite;
    float maxVelocity;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f deceleration;
    /* Initializer functions */

public:
    MovementComponent(sf::Sprite& sprite,float maxVelocity);
    virtual ~MovementComponent();

    /* Accessors */
    const sf::Vector2f& getVelocity() const;

    /* Functions */
    void move(const float dir_x, const float dir_y, const float& dt);
    void update(const float& dt);
};


#endif //GAMEENG_MOVEMENTCOMPONENT_H
