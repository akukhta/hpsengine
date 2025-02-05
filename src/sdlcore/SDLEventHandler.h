#pragma once
#include <SDL2/SDL.h>
#include <functional>
#include <memory>
#include <unordered_map>
#include "Input/IInputManager.h"

namespace SDLCore
{
    class SDLEventHandler
    {
    public:
        SDLEventHandler(std::unique_ptr<IInputManager> inputManager = nullptr);

        enum class EventType {QUIT = SDL_QUIT};

        void addEventHandler(EventType type, std::function<void()> handler);
        void handleEvents();
        IInputManager* getInputManager() const;
    private:
        void callHandler(EventType type);
        std::unordered_multimap<EventType, std::function<void()>> eventHandlers;
        std::unique_ptr<IInputManager> inputManager;
    };
}
