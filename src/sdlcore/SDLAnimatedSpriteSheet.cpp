#include "SDLAnimatedSpriteSheet.h"
#include "SDLTimeController.h"
#include "Texture/ITextureManager.h"
#include <algorithm>

SDLCore::SDLAnimatedSpriteSheet::SDLAnimatedSpriteSheet(ITextureManager *textureManager, std::uint32_t textureId,
                                                        std::pair<int, int> frameSize, double duration, unsigned int framesCount)
    : textureId(textureId), frameSize(std::move(frameSize)),
        framesCount(framesCount), textureManager(textureManager)
{
    setDuration(duration);
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
