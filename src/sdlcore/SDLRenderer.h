#pragma once
#include <memory>
#include <SDL2/SDL.h>
#include <utility>
#include "IRenderer.h"

namespace SDLCore
{
    /// Class performs drawing to the associated window
    class SDLRenderer : public IRenderer
    {
    public:
        SDLRenderer(class SDLWindow* window);

        void setResolution(int width, int height);
        void setResolution(std::pair<int, int> resolution);
        std::pair<int, int> getResolution();

#ifndef _DEBUG
        SDL_Renderer* getRenderer()
        {
            return renderer.get();
        }
#endif

        void render();
        void startRendering() override;
        void finishRendering() override;

        virtual void render(SDLTexture* texture, int x, int y, int w, int h) override;

    private:
        std::pair<int, int> resolution;
        using RendererPtr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
        RendererPtr renderer{nullptr, &SDL_DestroyRenderer};

        void changeResolution();
    };
}
