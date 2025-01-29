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
            case SDL_CONTROLLERDEVICEADDED:
            {
                std::cout << "Controller added" << std::endl;
                gamepadAdded(event.cdevice.which);
                break;
            }

            case SDL_CONTROLLERDEVICEREMOVED:
            {
                std::cout << "Controller removed" << std::endl;
                gamepadRemoved(event.cdevice.which);
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

std::unordered_map<int, SDL_GameController*> SDLCore::SDLInputManager::findGamepads()
{
    size_t gamepadCount = SDL_NumJoysticks();
    std::unordered_map<int, SDL_GameController*> gamepadsFound;

    for (size_t i = 0; i < gamepadCount; i++)
    {
        if (SDL_IsGameController(i))
        {
            auto gamePad = SDL_GameControllerOpen(i);

            if (gamePad)
            {
                gamepadsFound.insert(std::make_pair(i, gamePad));
            }
        }
    }

    return gamepadsFound;
}

void SDLCore::SDLInputManager::removeGamepads()
{
    for (auto &gamepad : gamepads)
    {
        SDL_GameControllerClose(gamepad.second);
    }

    gamepads.clear();
}

void SDLCore::SDLInputManager::gamepadAdded(int gamepadId)
{
    gamepads.insert(std::make_pair(gamepadId, SDL_GameControllerOpen(gamepadId)));
}

void SDLCore::SDLInputManager::gamepadRemoved(int gamepadId)
{
    SDL_GameControllerClose(gamepads[gamepadId]);
    gamepads.erase(gamepadId);
}

