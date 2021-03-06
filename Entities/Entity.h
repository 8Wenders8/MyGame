#ifndef GAMEENG_ENTITY_H
#define GAMEENG_ENTITY_H
/** Class for creating entities in the game. */
#include "../Components/MovementComponent.h"


class Entity {
private:
    void initVariables();
protected:
    /* Variables */
    sf::Texture* texture;
    sf::Sprite* sprite;
    MovementComponent* movementComponent;
    /* Protected functions - might change to private and use get/set in the future. */

public:
    Entity();
    virtual ~Entity();
    /* Component functions */
    void createSprite(sf::Texture* texture);
    void createMovementComponent(const float maxVelocity);
    /* Functions */
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float dir_x, const float dir_y);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
#endif //GAMEENG_ENTITY_H
