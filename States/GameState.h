#ifndef GAMEENG_GAMESTATE_H
#define GAMEENG_GAMESTATE_H

#include "State.h"

class GameState : public State{
private:

public:
    GameState(sf::RenderWindow *StateWindow);
    virtual ~GameState();

    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target= nullptr);
};


#endif //GAMEENG_GAMESTATE_H
