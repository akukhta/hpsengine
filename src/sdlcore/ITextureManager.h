#pragma once
#include "SDLTexture.h"

namespace SDLCore
{
    class ITextureManager
    {
    public:
        virtual ~ITextureManager() = default;

        ITextureManager(const ITextureManager&) = default;
        ITextureManager(ITextureManager&&) = default;
        ITextureManager& operator=(const ITextureManager&) = default;
        ITextureManager& operator=(ITextureManager&&) = default;

        SDLTexture* load(std::string const& fileName, IRenderer* renderer);
    };
}