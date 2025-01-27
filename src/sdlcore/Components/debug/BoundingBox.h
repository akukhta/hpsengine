#pragma once
#include "../primitives/RectangleComponent.h"

namespace SDLCore
{
    class BoundingBox : public Primitives::RectangleComponent
    {
    public:
        BoundingBox(SDL_Color color, IEntity* parent = nullptr);
        BoundingBox(BoundingBox const& other);

        void render(SDLCore::IRenderer *renderer) override;

        Math::Rectangle getBoundingBox() const override;

        IComponent* clone() override;

    private:
        void calculateBoundingBox();
    };
}