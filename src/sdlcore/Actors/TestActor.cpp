#include "TestActor.h"
#include "../../primitives/Colors.h"

TestActor::TestActor(SDLCore::TextureManager* textureManager, std::uint32_t textureID, SDLCore::Math::IVector2D componentOffset)
{
    spriteComponent = createComponent<SDLCore::SpriteComponent>(textureManager, textureID, componentOffset);
    rectangleComponent = createComponent<SDLCore::Primitives::RectangleComponent>(SDLCore::Math::IVector2D{100, 100}, 320, 240, Primitives::Colors::Red, true);
}

SDLCore::GameObject* TestActor::clone()
{
    return new TestActor(*this);
}
