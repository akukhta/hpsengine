#pragma once
#include "../primitives/RectangleComponent.h"

namespace SDLCore
{
    class BoundingBox : public Primitives::RectangleComponent
    {
    public:
        BoundingBox(IEntity* parent, SDL_Color color);

        void render(SDLCore::IRenderer *renderer) override;

        Math::Rectangle getBoundingBox() const override;

    private:
        void calculateBoundingBox();
    };
}