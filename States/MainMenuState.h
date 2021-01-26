#ifndef GAMEENG_MAINMENUSTATE_H
#define GAMEENG_MAINMENUSTATE_H

#include "GameState.h"
#include "../Resources/Button.h"

class MainMenuState : public State {
private:
    /* Variables */
    sf::RectangleShape background;
    sf::Font font;
    std::map<std::string, Button*> buttons;
    /* Private functions */
    void initFonts();
    void initButtons();
    void initKeybinds();
public:
    MainMenuState(sf::RenderWindow *StateWindow,std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();
    /* Functions */
    void endState();
    void updateButtons();
    void updateInput(const float& dt);
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target= nullptr);
    void render(sf::RenderTarget* target= nullptr);
};


#endif //GAMEENG_MAINMENUSTATE_H
