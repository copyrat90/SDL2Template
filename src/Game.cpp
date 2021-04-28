#include "Game.hpp"


bool Game::Create()
{
    if (0 > SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_LogError(0, "SDL_Init() failed!\n%s", SDL_GetError());
        return false;
    }

    window_ = SDL_CreateWindow(
        "SDL2 Template",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, 0
    );
    if (!window_)
    {
        SDL_LogError(0, "SDL_CreateWindow() failed!\n%s", SDL_GetError());
        return false;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_)
    {
        SDL_LogError(0, "SDL_CreateRenderer() failed!\n%s", SDL_GetError());
        return false;
    }

    isReady_ = true;
    return true;
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Game::Run()
{
    if (!isReady_ && !Create())
        return;

    isRunning_ = true;
    Uint32 prevTimePoint = SDL_GetTicks();
    while (isRunning_)
    {
        HandleEvents();

        // capping frame rate
        if (SDL_GetTicks() - prevTimePoint < MS_PER_FRAME)
        {
            const Uint32 waitTime = MS_PER_FRAME - (SDL_GetTicks() - prevTimePoint);
            SDL_Delay(waitTime);
        }

        const Uint32 deltaTime = SDL_GetTicks() - prevTimePoint;
        prevTimePoint = SDL_GetTicks();

        Update(deltaTime);
        Render();
    }
}

void Game::HandleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_EventType::SDL_QUIT:
            isRunning_ = false;
            break;
        }
    }
}

void Game::Update(Uint32 deltaTime)
{

}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);

    SDL_RenderPresent(renderer_);
}
