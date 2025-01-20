#pragma once
#include "../primitives/RectangleComponent.h"

namespace SDLCore
{
    class BoundingBox : public Primitives::RectangleComponent
    {
    public:
        BoundingBox(IEntity* parent, SDL_Color color);

        void render(SDLCore::IRenderer *renderer) override;

        std::pair<int, int> getRenderableSize() const override;

    private:
        void calculateBoundingBox();
    };
}