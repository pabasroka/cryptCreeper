#include"Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
    //Random numbers 
    srand((unsigned)time(0));

    //Main object game
    Game game;

    //Loop
    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}