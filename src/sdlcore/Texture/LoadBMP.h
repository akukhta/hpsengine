#pragma once
#include "ITextureLoadStrategy.h"

namespace SDLCore
{
    class LoadBMP : public ITextureLoadStrategy
    {
    public:
        std::unique_ptr<SDLTexture> load(const std::string &fileName, IRenderer *renderer) override;
    };
}