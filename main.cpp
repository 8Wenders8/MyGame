#include <iostream>
#include "Game.h"

int main()
{
    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init Game engine
    Game game;

    //Game loop
    while (game.getWindowIsOpen())
    {
        /**Update the time that is takes to update and render one frame. */
        game.updateDeltaTime();
        //Update
        game.update();
        //Render
        game.render();
    }
    return 0;
}