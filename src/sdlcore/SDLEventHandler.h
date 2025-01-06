#pragma once
#include <SDL2/SDL.h>
#include <functional>
#include <unordered_map>

namespace SDLCore
{
    class SDLEventHandler
    {
    public:
        enum class EventType {QUIT = SDL_QUIT};

        void addEventHandler(EventType type, std::function<void()> handler);
        void handleEvents();

    private:
        void callHandler(EventType type);
        std::unordered_multimap<EventType, std::function<void()>> eventHandlers;
    };
}
