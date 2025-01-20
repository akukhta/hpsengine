#pragma once
#include <utility>
#include "Math/Rectangle.h"
#include "Math/Vector2D.h"

namespace SDLCore
{
    class IRenderable
    {
    public:
        IRenderable() = default;

        IRenderable(const IRenderable&) = default;
        IRenderable(IRenderable&&) = default;

        IRenderable& operator=(const IRenderable&) = default;
        IRenderable& operator=(IRenderable&&) = default;

        virtual Math::Rectangle getBoundingBox() const = 0;

        virtual ~IRenderable() = default;

        virtual void render(class IRenderer* renderer) = 0;
    };
}