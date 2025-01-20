#include "SpritesheetComponent.h"
#include "../GameObject/GameObject.h"
#include "../Texture/TextureManager.h"

SDLCore::SpritesheetComponent::SpritesheetComponent(class TextureManager *textureManager, Math::IVector2D const &relativePosition,
    std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet)
        : RenderableComponent(relativePosition), textureManager(textureManager), spritesheet(std::move(spritesheet))
{}

void SDLCore::SpritesheetComponent::render(IRenderer *renderer)
{
    Math::Rectangle srcRect{static_cast<int>(spritesheet->frameSize.first * spritesheet->currentFrameIndex),
        0,spritesheet->frameSize.first,
spritesheet->frameSize.second};

    Math::IVector2D pos = getParentWorldLocation();

    Math::Rectangle dstRect{pos.x + relativeLocation.x, pos.y + relativeLocation.y,
        static_cast<int>(scale.x * spritesheet->frameSize.first), static_cast<int>(scale.y * spritesheet->frameSize.second)};

    renderer->renderTexture(textureManager->getTexture(spritesheet->textureId), srcRect, dstRect);
}

void SDLCore::SpritesheetComponent::update(double deltaTime)
{
    if (!spritesheet) [[unlikely]]
    {
        return;
    }

    spritesheet->currentFrameTime += deltaTime;

    if (spritesheet->currentFrameTime >= spritesheet->secondsPerFrame)
    {
        ++spritesheet->currentFrameIndex;

        if (spritesheet->currentFrameIndex + 1 < spritesheet->framesCount) [[likely]]
        {
            ++spritesheet->currentFrameIndex;
        }
        else [[unlikely]]
        {
            if (spritesheet->isLoop_) [[likely]]
            {
                spritesheet->currentFrameIndex = 0;
            }
            else [[unlikely]]
            {
                spritesheet->currentFrameIndex = spritesheet->framesCount - 1;
            }
        }

        spritesheet->currentFrameTime = 0;
    }
}

void SDLCore::SpritesheetComponent::setSpritesheet(std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet)
{
    this->spritesheet = std::move(spritesheet);
}

std::pair<int, int> SDLCore::SpritesheetComponent::getRenderableSize() const
{
    auto pos = getWorldLocation();
    return std::make_pair(pos.x + spritesheet->frameSize.first * scale.x, pos.y + spritesheet->frameSize.second * scale.y);
}
