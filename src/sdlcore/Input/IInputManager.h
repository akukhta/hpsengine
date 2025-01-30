#pragma once
#include <SDL2/SDL_events.h>

namespace SDLCore
{
    class IInputManager
    {
    public:
        IInputManager() = default;
        IInputManager(IInputManager const&) = default;
        IInputManager& operator=(IInputManager const&) = default;
        IInputManager(IInputManager&&) = default;
        IInputManager& operator=(IInputManager&&) = default;
        virtual ~IInputManager() = default;

        virtual void handleEvent(SDL_Event event) = 0;
        virtual void init() = 0;
    };
}