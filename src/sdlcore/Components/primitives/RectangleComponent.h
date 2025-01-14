#pragma once
#include "../../IRenderable.h"
#include "../../Math/Rectangle.h"
#include "../../Math/Vector2D.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>

namespace SDLCore {
    class SDLRenderer;
    class GameObject;
}

namespace SDLCore::Primitives
{
    class RectangleComponent : public SDLCore::IRenderable
    {
    public:
        RectangleComponent(SDLCore::Math::IVector2D pos, int width, int height, SDL_Color color, bool fill = true);

        void setParent(GameObject *parent);
        GameObject* getParent() const;
        Math::IVector2D const& getRelativePosition() const;

        void render(SDLCore::IRenderer *renderer) override;

    private:
        friend class SDLCore::SDLRenderer;

        GameObject* parent{nullptr};
        Math::IVector2D relativePosition;
        int width;
        int height;
        SDL_Color color;
        bool fill;
    };
}
