#pragma once
#include "../primitives/Circle.h"
#include "Rectangle.h"

namespace Primitives
{
    class Rectangle;
}

namespace SDLCore
{
    class IRenderer
    {
    public:
        IRenderer() = default;
        IRenderer(const IRenderer&) = default;
        IRenderer(IRenderer&&) = default;
        IRenderer& operator=(const IRenderer&) = default;
        IRenderer& operator=(IRenderer&&) = default;
        virtual ~IRenderer() = default;

        virtual void startRendering() = 0;
        virtual void finishRendering() = 0;

        virtual void renderTexture(class SDLTexture*, int x = 0, int y = 0, int w = 0, int h = 0) = 0;
        virtual void renderTexture(SDLTexture*, Math::Rectangle const &src, Math::Rectangle const &dst) = 0;

        virtual void renderRectangle(Primitives::Rectangle*, int x, int y, int w, int h) = 0;
        virtual void renderRectangle(Primitives::Rectangle*, int x, int y) = 0;

        virtual void renderCircle(Primitives::Circle*, int centerX, int centerY, int r) = 0;
    };
}