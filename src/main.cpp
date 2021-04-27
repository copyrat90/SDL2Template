#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


int SDL_main(int argc, char** argv)
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        SDL_LogError(0, "SDL_Init() failed!\n%s", SDL_GetError());
        return -1;
    }
    if (0 == IMG_Init(IMG_INIT_PNG))
    {
        SDL_LogError(0, "IMG_Init() failed!\n%s", SDL_GetError());
        return -1;
    }
    if (-1 == TTF_Init())
    {
        SDL_LogError(0, "TTF_Init() failed!\n%s", SDL_GetError());
        return -1;
    }
    if (0 == Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG))
    {
        SDL_LogError(0, "Mix_Init() failed!\n%s", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL2Template", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, 0
    );
    if (!window)
    {
        SDL_LogError(0, "SDL_CreateWindow() failed!\n%s", SDL_GetError());
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED
    );
    if (!renderer)
    {
        SDL_LogError(0, "SDL_CreateRenderer() failed!\n", SDL_GetError());
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Log("Yay! SDL2 and its extensions are initialized correctly!");

    SDL_Delay(3000);

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}