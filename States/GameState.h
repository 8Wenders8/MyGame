#ifndef GAMEENG_GAMESTATE_H
#define GAMEENG_GAMESTATE_H
/** With this state you access gameplay. */
#include "State.h"

class GameState : public State{
private:
    Entity player; // TEMPORARY
    /* Private Functions */
    void initKeybinds();
public:
    GameState(sf::RenderWindow *StateWindow,std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();
    /* Functions */
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target= nullptr);
};
#endif //GAMEENG_GAMESTATE_H
