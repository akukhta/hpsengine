#pragma once
#include "../GameObject/GameObject.h"
#include "../Components/SpriteComponent.h"
#include "../Components/primitives/RectangleComponent.h"
#include "../Components/primitives/CircleComponent.h"

class TestActor : public SDLCore::GameObject
{
public:
    TestActor(class SDLCore::TextureManager* textureManager, std::uint32_t textureID, SDLCore::Math::IVector2D componentOffset = {0, 0});

    GameObject* clone() override;

private:
    SDLCore::SpriteComponent* spriteComponent{nullptr};
    SDLCore::Primitives::RectangleComponent*  rectangleComponent{nullptr};
    SDLCore::Primitives::CircleComponent* circle_component{nullptr};
};