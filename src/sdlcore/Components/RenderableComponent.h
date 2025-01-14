#pragma once
#include "IComponent.h"
#include "../IRenderer.h"
#include "../Math/Vector2D.h"

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

        void update(double deltaTime) override;

        void setParent(GameObject *parent) override;
        GameObject* getParent() const override;

    protected:
        GameObject* parent;
        Math::IVector2D relativeLocation{0, 0};
        Math::FVector2D scale{1.f, 1.f};
    };
}
