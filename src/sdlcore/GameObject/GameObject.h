#pragma once
#include <vector>
#include <deque>
#include "../IRenderable.h"
#include "../IUpdatable.h"
#include "../Components/IComponent.h"
#include "../Entity/ISceneEntity.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    template<typename ComponentType>
    concept IsComponentType = std::is_base_of_v<IComponent, ComponentType>;

    class GameObject : public ISceneEntity, public IRenderable, public IUpdatable
    {
    public:
        GameObject() = default;
        GameObject(const GameObject& other);
        GameObject(GameObject&&) = default;
        GameObject& operator=(const GameObject&) = default;
        GameObject& operator=(GameObject&&) = default;

        virtual ~GameObject() = default;

        void render(IRenderer *renderer) override;

        void update(double deltaTime) override;

        virtual GameObject* clone() = 0;

        void setPosition(Math::IVector2D position);
        Math::IVector2D getWorldLocation() const override;
        Math::IVector2D getRelativeLocation() const override;

        Math::Rectangle getBoundingBox() const override;

    protected:
        Math::IVector2D position{0, 0};

        template <typename ComponentType, typename... Args>
            requires IsComponentType<ComponentType>
        ComponentType* createChildComponent(Args&& ... args)
        {
            //ComponentType* component = new ComponentType{std::forward<Args>(args)...};
            auto component = std::make_unique<ComponentType>(std::forward<Args>(args)...);

            if constexpr (std::is_base_of_v<IRenderable, ComponentType>)
            {
                renderableComponents.push_back(component.get());
            }

            if constexpr (std::is_base_of_v<IUpdatable, ComponentType>)
            {
                updatableComponents.push_back(component.get());
            }

            component->setParent(this);

            auto rv = component.get();
            componentsStorage.push_back(std::move(component));

            return rv;
        }


        template <typename ComponentType, typename... Args>
            requires IsComponentType<ComponentType>
        ComponentType* createDefaultComponent(Args&& ... args)
        {
            //ComponentType* component = new ComponentType{std::forward<Args>(args)...};
            auto component = std::make_unique<ComponentType>(std::forward<Args>(args)...);

            if constexpr (std::is_base_of_v<IRenderable, ComponentType>)
            {
                renderableComponents.push_back(component.get());
            }

            if constexpr (std::is_base_of_v<IUpdatable, ComponentType>)
            {
                updatableComponents.push_back(component.get());
            }

            auto rv = component.get();
            componentsStorage.push_back(std::move(component));

            return rv;
        }
    private:
        std::vector<IRenderable*> renderableComponents;
        std::vector<IUpdatable*> updatableComponents;
        std::deque<std::unique_ptr<IComponent>> componentsStorage;
    };
}