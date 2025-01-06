#pragma once
#include <vector>
#include <SDL2/SDL_rect.h>
#include "../sdlcore/IRenderable.h"

namespace SDLCore {
    class SDLRenderer;
}

namespace Primitives
{
    class Circle : public SDLCore::IRenderable
    {
    public:
        /// If the position of a circle is static,
        /// the circle will be more efficient cause there is no need to recalculate the points
        Circle(int x, int y, int radius, SDL_Color color);

        void render(SDLCore::IRenderer *renderer, int x, int y) override;
        void render(SDLCore::IRenderer *renderer, int x, int y, int w, int h) override;
        void render(SDLCore::IRenderer *renderer, int x, int y, int r) override;

    private:
        friend class SDLCore::SDLRenderer;

        std::vector<SDL_Point> points;
        SDL_Color color;
        int prevX;
        int prevY;
        int prevRadius;

        void calculatePoints(int centerX, int centerY, int radius);
    };
}
