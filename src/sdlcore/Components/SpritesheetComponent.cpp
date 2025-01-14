#include "SpritesheetComponent.h"
#include "../GameObject/GameObject.h"
#include "../Texture/TextureManager.h"
#include <iostream>

SDLCore::SpritesheetComponent::SpritesheetComponent(class TextureManager *textureManager, Math::IVector2D const &relativePosition,
    std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet)
        : RenderableComponent(relativePosition), textureManager(textureManager), spritesheet(std::move(spritesheet))
{}

void SDLCore::SpritesheetComponent::render(IRenderer *renderer)
{
    Math::Rectangle srcRect{static_cast<int>(spritesheet->frameSize.first * spritesheet->currentFrameIndex),
        0,spritesheet->frameSize.first,
spritesheet->frameSize.second};

    auto pos = getParent()->getPosition();

    Math::Rectangle dstRect{pos.x + relativePosition.x, pos.y + relativePosition.y,
        spritesheet->frameSize.first, spritesheet->frameSize.second};

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

    std::cout << spritesheet->currentFrameIndex << "\n";
}

void SDLCore::SpritesheetComponent::setSpritesheet(std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet)
{
    this->spritesheet = std::move(spritesheet);
}
