#pragma once
#include "../SDLTexture.h"

namespace SDLCore
{
    class ITextureLoadStrategy
    {
    public:
        ITextureLoadStrategy() = default;

        ITextureLoadStrategy(const ITextureLoadStrategy&) = default;
        ITextureLoadStrategy(ITextureLoadStrategy&&) = default;
        ITextureLoadStrategy& operator=(const ITextureLoadStrategy&) = default;
        ITextureLoadStrategy& operator=(ITextureLoadStrategy&&) = default;

        virtual ~ITextureLoadStrategy() = default;

        virtual std::unique_ptr<SDLTexture> load(std::string const& fileName, IRenderer* renderer) = 0;
    };
}