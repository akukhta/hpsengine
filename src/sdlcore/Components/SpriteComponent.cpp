#include "SpriteComponent.h"
#include "../Texture/TextureManager.h"
#include "../SDLRenderer.h"
#include "../GameObject/GameObject.h"

SDLCore::SpriteComponent::SpriteComponent(class TextureManager *textureManager,
                                          std::uint32_t textureID, Math::IVector2D const &relativePosition)
    : textureManager(textureManager), textureID(textureID), relativePosition(relativePosition)
{
    if (textureManager)
    {
        spriteSize = textureManager->getTexture(textureID)->getTextureSize();
    }
}

SDLCore::SpriteComponent::SpriteComponent(TextureManager *textureManager, std::uint32_t textureID,
    Math::IVector2D const &relativePosition, std::pair<int, int> spriteSize)
        : textureManager(textureManager), textureID(textureID),
    relativePosition(relativePosition), spriteSize(spriteSize)
{
    ;
}

void SDLCore::SpriteComponent::render(IRenderer* renderer)
{
    if (auto sdlRenderer = dynamic_cast<SDLRenderer*>(renderer); sdlRenderer)
    {
        auto pos = parent->getPosition();
        auto texture = textureManager->getTexture(textureID);
        sdlRenderer->renderTexture(texture, pos + relativePosition, spriteSize);
    }
}

void SDLCore::SpriteComponent::setParent(GameObject *parent)
{
    this->parent = parent;
}

SDLCore::GameObject * SDLCore::SpriteComponent::getParent() const
{
    return parent;
}

SDLCore::Math::IVector2D const & SDLCore::SpriteComponent::getRelativePosition() const
{
    return relativePosition;
}
