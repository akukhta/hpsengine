#include "TestActor.h"
#include "../../primitives/Colors.h"
#include "../../sdlcore/Texture/TextureManager.h"
#include "../../sdlcore/Texture/LoadPNG.h"
#include "../../sdlcore/SDLRenderer.h"
#include "../../sdlcore/IRenderer.h"

TestActor::TestActor(SDLCore::IRenderer* renderer, SDLCore::TextureManager* textureManager, std::uint32_t textureID, SDLCore::Math::IVector2D componentOffset)
{
    spriteComponent = createComponent<SDLCore::SpriteComponent>(textureManager, textureID, componentOffset);
    rectangleComponent = createComponent<SDLCore::Primitives::RectangleComponent>(SDLCore::Math::IVector2D{300, 100}, 320, 240, Primitives::Colors::Red, true);
    circle_component = createComponent<SDLCore::Primitives::CircleComponent>(SDLCore::Math::IVector2D{320, 240}, 50, Primitives::Colors::Gray, true);

    auto animatedTextureID = textureManager->loadTexture<SDLCore::LoadPNG>("/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png", renderer);

    spritesheet_component = createComponent<SDLCore::SpritesheetComponent>(textureManager, componentOffset,
        std::make_unique<SDLCore::SDLAnimatedSpriteSheet>(textureManager, animatedTextureID, std::make_pair(96, 96), 1, 7));

    spritesheet_component->setRelativeLocation({0,0});
    spritesheet_component->setScale({2, 2});
    spritesheet_component->getSpritesheet()->setDuration(1);
    spritesheet_component->getSpritesheet()->isLoop(true);

    boundBox = createComponent<SDLCore::BoundingBox>(this, Primitives::Colors::White);
}

SDLCore::GameObject* TestActor::clone()
{
    return new TestActor(*this);
}

