#include "TestActor.h"

TestActor::TestActor(SDLCore::TextureManager* textureManager, std::uint32_t textureID, SDLCore::Math::IVector2D componentOffset)
{
    spriteComponent = createComponent<SDLCore::SpriteComponent>(textureManager, textureID, componentOffset);
}

SDLCore::GameObject* TestActor::clone()
{
    return new TestActor(*this);
}
