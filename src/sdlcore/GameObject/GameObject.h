#pragma once
#include "../IRenderable.h"
#include "../IUpdatable.h"

namespace SDLCore
{
    class GameObject : public IRenderable, public IUpdatable
    {
    public:
        GameObject() = default;
        GameObject(const GameObject&) = default;
        GameObject(GameObject&&) = default;
        GameObject& operator=(const GameObject&) = default;
        GameObject& operator=(GameObject&&) = default;

        virtual ~GameObject() = default;

        void render(IRenderer *renderer, int x, int y) override;
        void render(IRenderer *renderer, int x, int y, int w, int h) override;
        void render(IRenderer *renderer, const Math::Rectangle &src, const Math::Rectangle &dst) override;
        void render(IRenderer *renderer, int x, int y, int r) override;

        void update(double deltaTime) override;

        virtual GameObject* clone() = 0;
    };
}