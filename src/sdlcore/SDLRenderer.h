#pragma once
#include <memory>
#include <SDL2/SDL.h>
#include <utility>

namespace SDLCore
{
    class SDLRenderer
    {
    public:
        explicit SDLRenderer(class SDLWindow* window);

        void setResolution(int width, int height);
        void setResolution(std::pair<int, int> resolution);
        std::pair<int, int> getResolution();

#ifndef _DEBUG
        SDL_Renderer* getRenderer()
        {
            return renderer.get();
        }
#endif
    private:
        std::pair<int, int> resolution;
        using RendererPtr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
        RendererPtr renderer{nullptr, &SDL_DestroyRenderer};

        void changeResolution();
    };
}