#pragma once
#include "../../IRenderable.h"
#include "../RenderableComponent.h"
#include <SDL2/SDL_pixels.h>

namespace SDLCore {
    class SDLRenderer;
    class GameObject;
}

namespace SDLCore::Primitives
{
    class RectangleComponent : public RenderableComponent
    {
    public:
        RectangleComponent(SDLCore::Math::IVector2D pos, int width, int height, SDL_Color color, bool fill = true);
        RectangleComponent(Math::Rectangle box, SDL_Color color, bool fill = false);

        void render(SDLCore::IRenderer *renderer) override;

        Math::Rectangle getBoundingBox() const override;

    protected:
        int width;
        int height;

    private:
        friend class SDLCore::SDLRenderer;

        SDL_Color color;
        bool fill;
    };
}
