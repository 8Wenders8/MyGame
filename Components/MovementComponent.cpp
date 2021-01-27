#include "MovementComponent.h"

/* Constructors - Destructors */
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration)
: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration) {
    this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent() {

}
/* Accessors */
const sf::Vector2f &MovementComponent::getVelocity() const {
    return this->velocity;
}
/* Functions */
void MovementComponent::move(const float dir_x, const float dir_y, const float& dt) {
    /* Acceleration */
    this->velocity.x += this->acceleration * dir_x;
    this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float &dt) {
    /* Decelerates the sprite and controls the maximum velocity.
     * Moves the sprite. */
    if(this->velocity.x > 0.f){ /* Check for positive x  */
        /* Max velocity check */
        if(this->velocity.x > this->maxVelocity){
            this->velocity.x = this->maxVelocity; }
        /* Deceleration x positive */
        this->velocity.x -= this->deceleration;
        if(this->velocity.x < 0.f){
            this->velocity.x = 0; }
    }
    else if(this->velocity.x < 0.f){ /* Check for negative x */
        /* Max velocity check */
        if(this->velocity.x < -this->maxVelocity){
            this->velocity.x = -this->maxVelocity; }
        /* Deceleration x negative */
        this->velocity.x += this->deceleration;
        if(this->velocity.x > 0.f){
            this->velocity.x = 0; }
    }

    if(this->velocity.y > 0.f){ /* Check for positive x  */
        /* Max velocity check */
        if(this->velocity.y > this->maxVelocity){
            this->velocity.y = this->maxVelocity; }
        /* Deceleration y positive */
        this->velocity.y -= this->deceleration;
        if(this->velocity.y < 0.f){
            this->velocity.y = 0; }
    }
    else if(this->velocity.y < 0.f){ /* Check for negative x */
        /* Max velocity check */
        if(this->velocity.y < -this->maxVelocity){
            this->velocity.y = -this->maxVelocity; }
        /* Deceleration y negative */
        this->velocity.y += this->deceleration;
        if(this->velocity.y > 0.f){
            this->velocity.y = 0; }
    }
    /* Final move */
    this->sprite.move(this->velocity * dt);
}
