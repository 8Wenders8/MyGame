#ifndef GAMEENG_MAINMENUSTATE_H
#define GAMEENG_MAINMENUSTATE_H

#include "GameState.h"
#include "../Resources/Button.h"

class MainMenuState : public State {
private:
    //Functions
    void initKeybinds();
public:
    MainMenuState(sf::RenderWindow *StateWindow,std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target= nullptr);
};


#endif //GAMEENG_MAINMENUSTATE_H
