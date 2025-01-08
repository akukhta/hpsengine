#pragma once
#include "Rectangle.h"

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

        virtual void render(class IRenderer* renderer, int x, int y)  = 0;
        virtual void render(IRenderer* renderer, int x, int y, int w, int h)  = 0;

        virtual void render(IRenderer* renderer, Math::Rectangle const& src, Math::Rectangle const& dst) {};
        virtual void render(IRenderer* renderer, int x, int y, int r) {};
    };
}