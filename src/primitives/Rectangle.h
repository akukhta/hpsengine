#pragma once
#include "../sdlcore/IRenderable.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <utility>

namespace SDLCore {
    class SDLRenderer;
}

namespace Primitives
{
    class Rectangle : public SDLCore::IRenderable
    {
    public:
        Rectangle(int width, int height, SDL_Color color, bool fill = true);

        void render(SDLCore::IRenderer *renderer, int x, int y) override;
        void render(SDLCore::IRenderer *renderer, int x, int y, int w, int h) override;

    private:
        friend class SDLCore::SDLRenderer;
        std::pair<int, int> size;
        SDL_Color color;
        SDL_Rect srcRect;
        bool fill;
    };
}
