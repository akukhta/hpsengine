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
        RenderableComponent(Math::IVector2D relativePosition);

        Math::IVector2D const& getRelativePosition() const;

        void update(double deltaTime) override;

        void setParent(GameObject *parent) override;
        GameObject* getParent() const override;

    protected:
        GameObject* parent;
        Math::IVector2D relativePosition;
    };
}
