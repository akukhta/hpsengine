#pragma once
#include "SDLRenderer.h"
#include "SDLEventHandler.h"
#include "Scene/Scene.h"
#include "Texture/TextureManager.h"

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

        void update();
        void handleEvents();
        void render();

        RendererPtr renderer;
        EventHandlerPtr eventHandler;
        std::unique_ptr<TextureManager> textureManager;

        bool isRunning_ = false;

        std::unique_ptr<Scene> scene;
    };
}
