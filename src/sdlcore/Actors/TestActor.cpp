#include "TestActor.h"
#include "../../primitives/Colors.h"
#include "../../sdlcore/Texture/TextureManager.h"
#include "../../sdlcore/Texture/LoadPNG.h"
#include "../../sdlcore/SDLRenderer.h"
#include "../../sdlcore/IRenderer.h"

TestActor::TestActor(SDLCore::IRenderer* renderer, SDLCore::TextureManager* textureManager, std::uint32_t textureID, SDLCore::Math::IVector2D componentOffset)
{
    spriteComponent = createChildComponent<SDLCore::SpriteComponent>(textureManager, textureID, componentOffset);
    rectangleComponent = createChildComponent<SDLCore::Primitives::RectangleComponent>(SDLCore::Math::IVector2D{300, 100}, 320, 240, Primitives::Colors::Red, true);
    circle_component = createChildComponent<SDLCore::Primitives::CircleComponent>(SDLCore::Math::IVector2D{320, 240}, 50, Primitives::Colors::Gray, true);

    auto animatedTextureID = textureManager->loadTexture<SDLCore::LoadPNG>("/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png", renderer);

    spritesheet_component = createChildComponent<SDLCore::SpritesheetComponent>(textureManager, componentOffset,
        std::make_unique<SDLCore::SDLAnimatedSpriteSheet>(textureManager, animatedTextureID, std::make_pair(96, 96), 1, 7));

    spritesheet_component->setRelativeLocation({0,0});
    spritesheet_component->setScale({2, 2});
    spritesheet_component->getSpritesheet()->setDuration(1);
    spritesheet_component->getSpritesheet()->isLoop(true);

    boundBox = createDefaultComponent<SDLCore::BoundingBox>(Primitives::Colors::White);
    boundBox->setParent(circle_component);
    createDefaultComponent<SDLCore::BoundingBox>(Primitives::Colors::Green)->setParent(spritesheet_component);

}

TestActor::TestActor(TestActor const &other)
    : GameObject(other)
{
    auto componentMap = mapComponents(other);

    spriteComponent = dynamic_cast<SDLCore::SpriteComponent *>(componentMap[other.spriteComponent]);
    rectangleComponent = dynamic_cast<SDLCore::Primitives::RectangleComponent*>(componentMap[other.rectangleComponent]);
    circle_component = dynamic_cast<SDLCore::Primitives::CircleComponent*>(componentMap[other.circle_component]);
    spritesheet_component = dynamic_cast<SDLCore::SpritesheetComponent*>(componentMap[other.spritesheet_component]);
    boundBox = dynamic_cast<SDLCore::BoundingBox*>(componentMap[other.boundBox]);

    attach(std::make_unique<SDLCore::Primitives::RectangleComponent>(SDLCore::Math::IVector2D{10, 10}, 30, 30, Primitives::Colors::Green, true));
}

SDLCore::GameObject* TestActor::clone()
{
    return new TestActor(*this);
}

void TestActor::update(double deltaTime)
{
    GameObject::update(deltaTime);
    //
    // timePassed += deltaTime;
    //
    // if (timePassed > 1.0)
    // {
    //     spriteComponent->setVisibility(rand() % 2);
    //     rectangleComponent->setVisibility(rand() % 2);
    //     circle_component->setVisibility(rand() % 2);
    //     spritesheet_component->setVisibility(rand() % 2);
    //     boundBox->setVisibility(rand() % 2);
    //
    //     timePassed = 0.0;
    // }
}

