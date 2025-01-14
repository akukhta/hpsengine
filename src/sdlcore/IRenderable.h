#pragma once
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

        virtual ~IRenderable() = default;

        virtual void render(class IRenderer* renderer) = 0;
    };
}