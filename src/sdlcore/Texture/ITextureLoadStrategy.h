#pragma once
#include "../SDLTexture.h"

namespace SDLCore
{
    class ITextureLoadStrategy
    {
    public:
        virtual ~ITextureLoadStrategy() = default;

        ITextureLoadStrategy(const ITextureLoadStrategy&) = default;
        ITextureLoadStrategy(ITextureLoadStrategy&&) = default;
        ITextureLoadStrategy& operator=(const ITextureLoadStrategy&) = default;
        ITextureLoadStrategy& operator=(ITextureLoadStrategy&&) = default;

        std::unique_ptr<ITextureLoadStrategy> load(std::string const& fileName, IRenderer* renderer);
    };
}