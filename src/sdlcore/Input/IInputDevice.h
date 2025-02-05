#pragma once
#include <SDL2/SDL_events.h>

namespace SDLCore
{
    class IInputDevice
    {
    public:
        IInputDevice() = default;
        IInputDevice(IInputDevice const&) = default;
        IInputDevice& operator=(IInputDevice const&) = default;
        IInputDevice(IInputDevice&&) = default;
        IInputDevice& operator=(IInputDevice&&) = default;
        virtual ~IInputDevice() = default;

        virtual void handleEvent(SDL_Event const& event) = 0;
    };
}