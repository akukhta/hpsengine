#pragma once
#include "SDLTexture.h"
#include <string_view>

namespace SDLCore
{
    class SDLAnimatedSpriteSheet : public SDLTexture
    {
    public:
        static SDLAnimatedSpriteSheet loadPNG(class SDLRenderer *renderer, std::string const& fileName, std::pair<int, int> frameSize,
            double secondsPerFrame, unsigned int framesCount);

        void render(IRenderer *renderer, int x, int y) override;
        void render(IRenderer *renderer, const Rectangle &src, const Rectangle &dst) override;

    private:
        explicit SDLAnimatedSpriteSheet(TexturePtr texture, std::pair<int, int> frameSize, double secondsPerFrame, unsigned int framesCount);

        unsigned int currentFrameIndex = 0;
        unsigned int framesCount;

        double currentFrameTime = 0;
        double secondsPerFrame;

        std::pair<int, int> frameSize;
    };
}