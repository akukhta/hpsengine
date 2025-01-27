#pragma once
#include "RenderableComponent.h"
#include "../SDLAnimatedSpriteSheet.h"

namespace SDLCore
{
    class SpritesheetComponent : public RenderableComponent
    {
    public:
        SpritesheetComponent(class TextureManager* textureManager, Math::IVector2D const& relativePosition, std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet = nullptr);
        SpritesheetComponent(SpritesheetComponent const& other);

        void render(IRenderer *renderer) override;
        void update(double deltaTime) override;
        void setSpritesheet(std::unique_ptr<SDLAnimatedSpriteSheet> spritesheet);
        SDLAnimatedSpriteSheet* getSpritesheet() const;

        Math::Rectangle getBoundingBox() const override;

        IComponent* clone() override;

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
