#include "SDLInputManager.h"

#include <iostream>
#include <ostream>
#include <SDL.h>
#include <SDL2/SDL_gamecontroller.h>

void SDLCore::SDLInputManager::init()
{
    initGamepads();
}

void SDLCore::SDLInputManager::handleEvent(SDL_Event event)
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

        case SDL_JOYAXISMOTION:
        {
            auto gamepad = gamepads.find(event.jaxis.which);

            if(gamepad != gamepads.end())
            {
                gamepad->second->handleEvent(event);
            }

            break;
        }

        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
            mouse.handleEvent(event);
            break;
        }

        case SDL_KEYDOWN:
        case SDL_KEYUP:
        {
            keyboard.handleEvent(event);
            break;
        }

        default:
        {
            break;
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

std::unordered_map<int, std::unique_ptr<SDLCore::SDLGamepad>> SDLCore::SDLInputManager::findGamepads()
{
    size_t gamepadCount = SDL_NumJoysticks();
    std::unordered_map<int, std::unique_ptr<SDLCore::SDLGamepad>> gamepadsFound;

    for (size_t i = 0; i < gamepadCount; i++)
    {
        if (SDL_IsGameController(i))
        {
            auto gamePad = SDL_GameControllerOpen(i);

            if (gamePad)
            {
                gamepadsFound.insert(std::make_pair(i, std::make_unique<SDLGamepad>(gamePad)));
            }
        }
    }

    return gamepadsFound;
}

void SDLCore::SDLInputManager::removeGamepads()
{
    gamepads.clear();
}

void SDLCore::SDLInputManager::gamepadAdded(int gamepadId)
{
    gamepads.insert(std::make_pair(gamepadId,
        std::make_unique<SDLGamepad>(SDL_GameControllerOpen(gamepadId))));
}

void SDLCore::SDLInputManager::gamepadRemoved(int gamepadId)
{
    gamepads.erase(gamepadId);
}

