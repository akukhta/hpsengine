#include "SpriteComponent.h"
#include "../Texture/TextureManager.h"
#include "../SDLRenderer.h"
#include "../GameObject/GameObject.h"

SDLCore::SpriteComponent::SpriteComponent(class TextureManager *textureManager,
                                          std::uint32_t textureID, Math::IVector2D const &relativePosition)
    : RenderableComponent(relativePosition), textureManager(textureManager), textureID(textureID)
{
    if (textureManager)
    {
        spriteSize = textureManager->getTexture(textureID)->getTextureSize();
    }
}

SDLCore::SpriteComponent::SpriteComponent(TextureManager *textureManager, std::uint32_t textureID,
    Math::IVector2D const &relativePosition, std::pair<int, int> spriteSize)
        : RenderableComponent(relativePosition), textureManager(textureManager),
    textureID(textureID), spriteSize(spriteSize)
{
    ;
}

void SDLCore::SpriteComponent::render(IRenderer* renderer)
{
    Math::IVector2D pos = getParentWorldLocation();

    auto texture = textureManager->getTexture(textureID);
    renderer->renderTexture(texture, pos + relativeLocation, spriteSize);
}