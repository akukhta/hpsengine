#include "SDLAnimatedSpriteSheet.h"
#include "SDLTimeController.h"
#include <algorithm>
#include <iostream>

SDLCore::SDLAnimatedSpriteSheet SDLCore::SDLAnimatedSpriteSheet::loadPNG(class SDLRenderer *renderer,
    std::string const& fileName, std::pair<int, int> frameSize, double secondsPerFrame, unsigned int framesCount)
{
    auto texture  = SDLTexture::loadPNGRaw(fileName, renderer);

    return SDLAnimatedSpriteSheet{std::move(texture), std::move(frameSize), secondsPerFrame, framesCount};
}

void SDLCore::SDLAnimatedSpriteSheet::render(IRenderer *renderer, int x, int y)
{
    currentFrameTime += SDLTimeController::getDeltaTime();

    if (currentFrameTime >= secondsPerFrame)
    {
        currentFrameIndex = (currentFrameIndex + 1) % framesCount;
        currentFrameTime = 0;
    }

    Rectangle srcRect{static_cast<int>(frameSize.first * currentFrameIndex),
        static_cast<int>(frameSize.second * currentFrameIndex), frameSize.first, frameSize.second};

    Rectangle dstRect{x, y, frameSize.first, frameSize.second};

    SDLTexture::render(renderer, srcRect, dstRect);
}

void SDLCore::SDLAnimatedSpriteSheet::render(IRenderer *renderer, const Rectangle &src, const Rectangle &dst)
{
    currentFrameTime += SDLTimeController::getDeltaTime();

    if (currentFrameTime >= secondsPerFrame)
    {
        currentFrameIndex = (currentFrameIndex + 1) % framesCount;
        currentFrameTime = 0;
    }

    Rectangle srcRect{static_cast<int>(frameSize.first * currentFrameIndex),32, frameSize.first, frameSize.second};

    std::cout << srcRect.x << " " << srcRect.y << " " << srcRect.width << " " << srcRect.height << std::endl;

    SDLTexture::render(renderer, srcRect, dst);
}

SDLCore::SDLAnimatedSpriteSheet::SDLAnimatedSpriteSheet(TexturePtr texture, std::pair<int, int> frameSize, double secondsPerFrame,  unsigned int framesCount)
    : SDLTexture(std::move(texture)), frameSize(std::move(frameSize)), secondsPerFrame(secondsPerFrame), framesCount(framesCount)
{

}
