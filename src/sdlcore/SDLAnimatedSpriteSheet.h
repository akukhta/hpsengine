#pragma once
#include "SDLTexture.h"
#include <string_view>
#include "Math/Vector2D.h"

namespace SDLCore
{
    // Animation class description:
    // Should behave as a proxy under SDLTexture
    // It does not own the texture, it holds a name/descriptor of the corresponding texture
    // This class responsible for:
    // 1. Current frame switching
    // 2. Time managing
    // 3. Querying functionality (duration, frames count)

    class SDLAnimatedSpriteSheet
    {
    public:
        SDLAnimatedSpriteSheet(class ITextureManager* textureManager, std::uint32_t textureId, std::pair<int, int> frameSize, double duration,
            unsigned int framesCount);

        void setDuration(double durationInSeconds);
        double getDuration() const;

        void isLoop(bool loop);
        bool isLoop() const;

    private:
        friend class SpritesheetComponent;

        unsigned int currentFrameIndex = 0;
        unsigned int framesCount;

        double currentFrameTime = 0;
        double secondsPerFrame;

        std::pair<int, int> frameSize;

        bool isLoop_ = true;

        std::uint32_t textureId = 0;

        ITextureManager* textureManager = nullptr;
    };
}
