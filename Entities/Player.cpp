#include "Player.h"
/* Initializer functions */
void Player::initVariables() {

}

void Player::initComponents() {
    this->createMovementComponent(800.f, 6.f, 4.f);
}

/* Constructors - Destructors */
Player::Player(float x, float y, sf::Texture& texture) {
    this->initVariables();
    this->initComponents();

    this->setTexture(texture);
    this->setPosition(x,y);
    this->sprite.setScale(0.09f, 0.09f); // REMOVE after
}

Player::~Player() {

}
