#include "SDLEventHandler.h"
#include <SDL2/SDL.h>

void SDLCore::SDLEventHandler::addEventHandler(EventType type, std::function<void()> handler)
{
    eventHandlers.insert({type, std::move(handler)});
}

void SDLCore::SDLEventHandler::handleEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
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
}

void SDLCore::SDLEventHandler::callHandler(EventType type)
{
    auto range = eventHandlers.equal_range(type);

    for (auto it = range.first; it != range.second; ++it)
    {
        it->second();
    }
}
