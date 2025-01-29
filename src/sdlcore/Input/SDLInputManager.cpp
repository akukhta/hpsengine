#include "SDLInputManager.h"

#include <iostream>
#include <ostream>
#include <SDL.h>
#include <SDL2/SDL_gamecontroller.h>

void SDLCore::SDLInputManager::init()
{
    initGamepads();
}

void SDLCore::SDLInputManager::update(double deltaTime)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
            {
                std::cout << "Quitting..." << std::endl;
                break;
            }

            case SDL_CONTROLLERDEVICEADDED:
            {
                std::cout << "Controller added" << std::endl;
                break;
            }

            case SDL_CONTROLLERDEVICEREMOVED:
            {
                std::cout << "Controller removed" << std::endl;
                break;
            }
        }
    }
}

void SDLCore::SDLInputManager::initGamepads()
{
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0)
    {
        SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    }

    gamepads = findGamepads();
    SDL_JoystickEventState(SDL_ENABLE);
}

std::deque<SDL_GameController *> SDLCore::SDLInputManager::findGamepads()
{
    size_t gamepadCount = SDL_NumJoysticks();
    std::deque<SDL_GameController *> gamepadsFound;

    for (size_t i = 0; i < gamepadCount; i++)
    {
        if (SDL_IsGameController(i))
        {
            auto gamePad = SDL_GameControllerOpen(i);

            if (gamePad)
            {
                gamepadsFound.push_back(SDL_GameControllerOpen(i));
            }
        }
    }

    return gamepadsFound;
}

void SDLCore::SDLInputManager::removeGamepads()
{
    for (auto &gamepad : gamepads)
    {
        SDL_GameControllerClose(gamepad);
    }

    gamepads.clear();
}
