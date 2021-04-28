#include "Game.hpp"


int SDL_main(int argc, char** argv)
{
    Game game;

    if (game.Create())
        game.Run();
    game.Destroy();

    return 0;
}
