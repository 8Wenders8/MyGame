#include "Entity.h"

/* Private functions */
void Entity::initVariables() {
    this->movementComponent = nullptr;
}

/* Constructors - Destructors */
Entity::Entity() {
    this->initVariables();
}

Entity::~Entity() {
    delete this->movementComponent;
}
/* Component functions */

void Entity::setTexture(sf::Texture& texture) {
    this->sprite.setTexture(texture);
}
void Entity::createMovementComponent(const float maxVelocity) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
}

/* Functions */
void Entity::setPosition(const float x, const float y) {
    this->sprite.setPosition(x,y);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
    if(this->movementComponent){
        /* Sets velocity */
        this->movementComponent->move(dir_x, dir_y, dt);
    }
}

void Entity::update(const float &dt) {

}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
}
