#pragma once
#include "SDLRenderer.h"
#include "SDLEventHandler.h"
#include "Scene/Scene.h"
#include "Texture/TextureManager.h"

namespace SDLCore
{
    class SDLGame
    {
        using RendererPtr = std::unique_ptr<SDLRenderer>;
        using EventHandlerPtr = std::unique_ptr<SDLEventHandler>;

    public:
        SDLGame(RendererPtr renderer, EventHandlerPtr eventHandler);

        void init();
        void run();
        bool isRunning() const;

        void setFPSLock(int fps);
        void unlockFPS();

        void onGameQuit();
    private:

        void update();
        void handleEvents();
        void render();
        void delayGame(std::uint32_t ticks);
        RendererPtr renderer;
        EventHandlerPtr eventHandler;
        std::unique_ptr<TextureManager> textureManager;
        std::unique_ptr<Scene> scene;

        int fps;
        int delayTime;
        bool isRunning_ = false;
        bool fpsLockEnabled = false;
    };
}
