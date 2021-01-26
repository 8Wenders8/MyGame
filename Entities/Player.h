#ifndef GAMEENG_PLAYER_H
#define GAMEENG_PLAYER_H

#include "Entity.h"
/* Player entity */

class Player : public Entity {
private:
    /* Variables */
    /* Initializer functions */
    void initVariables();
    void initComponents();
public:
    Player(float x, float y, sf::Texture *texture);
    virtual ~Player();
    /* Functions */
};
#endif //GAMEENG_PLAYER_H
