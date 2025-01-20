#pragma once
#include <utility>

#include "Math/Rectangle.h"

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

        virtual std::pair<int, int> getRenderableSize() const = 0;

        virtual ~IRenderable() = default;

        virtual void render(class IRenderer* renderer) = 0;
    };
}