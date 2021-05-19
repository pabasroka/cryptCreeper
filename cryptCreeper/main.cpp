#include"Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand((unsigned)time(0));

    Game game;

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}