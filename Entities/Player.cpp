#include "Player.h"
/* Initializer functions */
void Player::initVariables() {

}

void Player::initComponents() {
    //this->createSprite(texture);
}

/* Constructors - Destructors */
Player::Player(float x, float y, sf::Texture *texture) {
    this->initVariables();
    this->initComponents();

    this->createSprite(texture);
    this->setPosition(x,y);
    this->sprite->setScale(0.09f, 0.09f); // REMOVE after
}

Player::~Player() {

}

