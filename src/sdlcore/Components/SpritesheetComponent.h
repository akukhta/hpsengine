#pragma once
#include "RenderableComponent.h"
#include "../SDLAnimatedSpriteSheet.h"

namespace SDLCore
{
    class SpritesheetComponent : public RenderableComponent
    {
    public:
        SpritesheetComponent(class TextureManager* textureManager, Math::IVector2D const& relativePosition, std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet = nullptr);

        void render(IRenderer *renderer) override;
        void update(double deltaTime) override;
        void setSpritesheet(std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet);
        SDLAnimatedSpriteSheet* getSpritesheet() const;
        std::pair<int, int> getRenderableSize() const override;

    private:
        std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet;
        TextureManager* textureManager = nullptr;
        std::uint32_t textureID;
    };

    inline SDLAnimatedSpriteSheet * SpritesheetComponent::getSpritesheet() const
    {
        return spritesheet.get();
    }
}
