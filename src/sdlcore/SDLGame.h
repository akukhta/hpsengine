#pragma once
#include "SDLRenderer.h"
#include "SDLEventHandler.h"

namespace SDLCore
{
    class SDLGame
    {
    private:
        using RendererPtr = std::unique_ptr<SDLRenderer>;
        using EventHandlerPtr = std::unique_ptr<SDLEventHandler>;

    public:
        SDLGame(RendererPtr renderer, EventHandlerPtr eventHandler);

        void init();
        void run();
        bool isRunning() const;

        void onGameQuit();
    private:
        RendererPtr renderer;
        EventHandlerPtr eventHandler;

        bool isRunning_ = false;
    };
}