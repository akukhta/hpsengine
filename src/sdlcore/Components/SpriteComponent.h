#pragma once
#include "RenderableComponent.h"
#include "../SDLTexture.h"

namespace SDLCore
{
    class SpriteComponent : public RenderableComponent
    {
    public:
        SpriteComponent(class TextureManager* textureManager, std::uint32_t textureId,
            Math::IVector2D const& relativePosition);

        SpriteComponent(TextureManager* textureManager, std::uint32_t textureID,
                    Math::IVector2D const& relativePosition, std::pair<int, int> spriteSize);

        SpriteComponent(SpriteComponent const &other);

        void render(IRenderer* renderer) override;

        Math::Rectangle getBoundingBox() const override;

        IComponent* clone() override;

    protected:
        TextureManager* textureManager = nullptr;
        std::uint32_t textureID;
        std::pair<int, int> spriteSize;
    };
}