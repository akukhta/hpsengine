#pragma once
#include <vector>
#include "../IRenderable.h"
#include "../IUpdatable.h"
#include "../Components/IComponent.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    template<typename ComponentType>
    concept IsComponentType = std::is_base_of_v<IComponent, ComponentType>;

    class GameObject : public IEntity, public IRenderable, public IUpdatable
    {
    public:
        GameObject() = default;
        GameObject(const GameObject&) = default;
        GameObject(GameObject&&) = default;
        GameObject& operator=(const GameObject&) = default;
        GameObject& operator=(GameObject&&) = default;

        virtual ~GameObject() = default;

        void render(IRenderer *renderer) override;

        void update(double deltaTime) override;

        virtual GameObject* clone() = 0;

        Math::IVector2D getPosition() const;
        void setPosition(Math::IVector2D position);

    protected:
        Math::IVector2D getParentLocation() const override;

        Math::IVector2D position{0, 0};

        template <typename ComponentType, typename... Args>
            requires IsComponentType<ComponentType>
        ComponentType* createComponent(Args&& ... args)
        {
            ComponentType* component = new ComponentType{std::forward<Args>(args)...};

            if constexpr (std::is_base_of_v<IRenderable, ComponentType>)
            {
                renderableComponents.push_back(component);
            }

            if constexpr (std::is_base_of_v<IUpdatable, ComponentType>)
            {
                updatableComponents.push_back(component);
            }

            component->setParent(this);
            return component;
        }

    private:
        std::vector<IRenderable*> renderableComponents;
        std::vector<IUpdatable*> updatableComponents;
    };
}