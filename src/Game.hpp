#pragma once

#include <SDL.h>


class Game
{
public:
    ~Game() { Destroy(); }

    bool Create();
    void Destroy();

    void Run();

private:
    void HandleEvents();
    void Update(Uint32 deltaTime);
    void Render();

    static constexpr Uint32 FPS = 60;
    static constexpr Uint32 MS_PER_FRAME = 1000 / FPS;

    bool isReady_ = false;
    bool isRunning_ = false;

    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
};
