#pragma once
#include <vector>
#include <SDL2/SDL_rect.h>
#include "../RenderableComponent.h"

namespace SDLCore {
    class SDLRenderer;
}

namespace SDLCore::Primitives
{
    class CircleComponent : public RenderableComponent
    {
    public:
        /// If the position of a circle is static,
        /// the circle will be more efficient cause there is no need to recalculate the points
        CircleComponent(Math::IVector2D relativePosition, int radius, SDL_Color color, bool filled = false);

        void render(SDLCore::IRenderer *renderer) override;

        std::pair<int, int> getRenderableSize() const override;

    private:
        friend class SDLCore::SDLRenderer;
        std::vector<SDL_Point> points;
        SDL_Color color;

        int r;
        int prevX;
        int prevY;
        int prevRadius;
        bool filled;

    private:
        void calculatePoints(int centerX, int centerY, int radius);
    };
}
