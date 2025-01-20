#pragma once
#include "IComponent.h"
#include "../IRenderer.h"
#include "../Math/Vector2D.h"
#include "../IRenderable.h"
#include "../IUpdatable.h"

namespace SDLCore
{
    class RenderableComponent : public IComponent, public IRenderable,
        public IUpdatable
    {
    public:
        RenderableComponent(Math::IVector2D relativeLocation);

        void setRelativeLocation(Math::IVector2D relativeLocation);
        Math::IVector2D const& getRelativeLocation() const;

        void setScale(Math::FVector2D scale);
        Math::FVector2D const& getScale() const;

        std::pair<int, int> getRenderableSize() const;

        void update(double deltaTime) override;

    protected:
        Math::IVector2D getParentLocation() const override;

        Math::IVector2D relativeLocation{0, 0};
        Math::FVector2D scale{1.f, 1.f};
    };
}
