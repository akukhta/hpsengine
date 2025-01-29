#include "SDLEventHandler.h"
#include <SDL2/SDL.h>

SDLCore::SDLEventHandler::SDLEventHandler(std::unique_ptr<IInputManager> inputManager)
    : inputManager(std::move(inputManager))
{
    if (this->inputManager)
    {
        this->inputManager->init();
    }
}

void SDLCore::SDLEventHandler::addEventHandler(EventType type, std::function<void()> handler)
{
    eventHandlers.insert({type, std::move(handler)});
}

void SDLCore::SDLEventHandler::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                callHandler(EventType::QUIT);
                break;
            }
            default:
                break;
        }
    }

    if (inputManager) [[likely]]
    {
        inputManager->update(0);
    }
}

void SDLCore::SDLEventHandler::callHandler(EventType type)
{
    auto const &[begin, end] = eventHandlers.equal_range(type);

    for (auto it = begin; it != end; ++it)
    {
        it->second();
    }
}
