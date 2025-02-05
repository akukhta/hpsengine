#pragma once
#include "../GameObject/GameObject.h"
#include "../Components/SpriteComponent.h"
#include "../Components/SpritesheetComponent.h"
#include "../Components/debug/BoundingBox.h"
#include "../Components/primitives/RectangleComponent.h"
#include "../Components/primitives/CircleComponent.h"

class TestActor : public SDLCore::GameObject
{
public:
    TestActor(class SDLCore::IRenderer* renderer, class SDLCore::TextureManager* textureManager, std::uint32_t textureID, SDLCore::Math::IVector2D componentOffset = {0, 0});
    TestActor(TestActor const& other);

    GameObject* clone() override;

    void update(double deltaTime) override;
    void someAction();
    void finishSomeAction();
    void move(int direction);

private:
    double timePassed{0};
    SDLCore::SpriteComponent* spriteComponent{nullptr};
    SDLCore::Primitives::RectangleComponent*  rectangleComponent{nullptr};
    SDLCore::Primitives::CircleComponent* circle_component{nullptr};
    SDLCore::SpritesheetComponent* spritesheet_component{nullptr};
    SDLCore::BoundingBox* boundBox{nullptr};
};