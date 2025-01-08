#include "SDLAnimatedSpriteSheet.h"
#include "SDLTimeController.h"
#include "Texture/ITextureManager.h"
#include <algorithm>

SDLCore::SDLAnimatedSpriteSheet::SDLAnimatedSpriteSheet(ITextureManager *textureManager, std::uint32_t textureId,
    std::pair<int, int> frameSize, double secondsPerFrame, unsigned int framesCount)
    : textureId(textureId), frameSize(std::move(frameSize)), secondsPerFrame(secondsPerFrame),
        framesCount(framesCount), textureManager(textureManager)
{
}

void SDLCore::SDLAnimatedSpriteSheet::render(IRenderer *renderer, int x, int y)
{
    if (!textureManager) [[unlikely]]
    {
        return;
    }

    currentFrameTime += SDLTimeController::getDeltaTime();

    if (currentFrameTime >= secondsPerFrame)
    {
        currentFrameIndex = (currentFrameIndex + 1) % framesCount;
        currentFrameTime = 0;
    }

    Math::Rectangle srcRect{static_cast<int>(frameSize.first * currentFrameIndex),
        static_cast<int>(frameSize.second * currentFrameIndex), frameSize.first, frameSize.second};

    Math::Rectangle dstRect{x, y, frameSize.first, frameSize.second};

    textureManager->getTexture(textureId)->render(renderer, srcRect, dstRect);
}

void SDLCore::SDLAnimatedSpriteSheet::render(IRenderer *renderer, const Math::Rectangle &src, const Math::Rectangle &dst)
{
    if (!textureManager) [[unlikely]]
    {
        return;
    }

    currentFrameTime += SDLTimeController::getDeltaTime();

    if (currentFrameTime >= secondsPerFrame)
    {
        currentFrameIndex = (currentFrameIndex + 1);

        if (currentFrameIndex + 1 < framesCount) [[likely]]
        {
            ++currentFrameIndex;
        }
        else [[unlikely]]
        {
            if (isLoop_) [[likely]]
            {
                currentFrameIndex = 0;
            }
            else [[unlikely]]
            {
                currentFrameIndex = framesCount - 1;
            }
        }

        currentFrameTime = 0;
    }

    Math::Rectangle srcRect{static_cast<int>(frameSize.first * currentFrameIndex),32, frameSize.first, frameSize.second};

    textureManager->getTexture(textureId)->render(renderer, srcRect, dst);
}

void SDLCore::SDLAnimatedSpriteSheet::setDuration(double durationInSeconds)
{
    secondsPerFrame = durationInSeconds / framesCount;
}

double SDLCore::SDLAnimatedSpriteSheet::getDuration() const
{
    return secondsPerFrame * framesCount;
}

void SDLCore::SDLAnimatedSpriteSheet::isLoop(bool loop)
{
    isLoop_ = loop;
}

bool SDLCore::SDLAnimatedSpriteSheet::isLoop() const
{
    return isLoop_;
}
