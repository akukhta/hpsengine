#pragma once
#include "../IRenderable.h"
#include "../Math/Vector2D.h"
#include "../SDLTexture.h"

namespace SDLCore
{
    class SpriteComponent : public IRenderable
    {
    public:
        SpriteComponent(class TextureManager* textureManager, std::uint32_t textureId,
            Math::IVector2D const& relativePosition);

        SpriteComponent(TextureManager* textureManager, std::uint32_t textureID,
                    Math::IVector2D const& relativePosition, std::pair<int, int> spriteSize);

        void render(IRenderer* renderer) override;

        void setParent(class GameObject* parent);
        GameObject* getParent() const;
        Math::IVector2D const& getRelativePosition() const;

    protected:
        GameObject* parent{nullptr};
        Math::IVector2D relativePosition;
        TextureManager* textureManager = nullptr;
        std::uint32_t textureID;
        std::pair<int, int> spriteSize;
    };
}