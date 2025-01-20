#pragma once
#include "IComponent.h"
#include "../IRenderer.h"
#include "../Math/Vector2D.h"
#include "../IRenderable.h"
#include "../IUpdatable.h"
#include "../Entity/ISceneEntity.h"

namespace SDLCore
{
    class RenderableComponent : public IComponent, public ISceneEntity,
        public IRenderable, public IUpdatable
    {
    public:
        RenderableComponent(Math::IVector2D relativeLocation);

        void setRelativeLocation(Math::IVector2D relativeLocation);

        void setScale(Math::FVector2D scale);
        Math::FVector2D const& getScale() const;

        void update(double deltaTime) override;

        Math::IVector2D getWorldLocation() const override;
        Math::IVector2D getRelativeLocation() const override;

        Math::Rectangle getBoundingBox() const override;

    protected:

        Math::IVector2D getParentWorldLocation() const;

        Math::Rectangle getParentRenderableSize();

        Math::IVector2D relativeLocation{0, 0};
        Math::FVector2D scale{1.f, 1.f};
    };
}
