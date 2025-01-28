#pragma once
#include <vector>
#include <deque>
#include <unordered_map>
#include "../IRenderable.h"
#include "../IUpdatable.h"
#include "../Components/IComponent.h"
#include "../Entity/ISceneEntity.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    template<typename ComponentType>
    concept IsComponentType = std::is_base_of_v<IComponent, ComponentType>;

    struct NoDynamicCastTag{};
    static constexpr NoDynamicCastTag NoDynamicCast;

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

        void attach(std::unique_ptr<IEntity> child) override;

    protected:
        Math::IVector2D position{0, 0};

        template <typename ComponentType, typename... Args>
            requires IsComponentType<ComponentType>
        ComponentType* createChildComponent(Args&& ... args)
        {
            //ComponentType* component = new ComponentType{std::forward<Args>(args)...};
            auto component = std::make_unique<ComponentType>(std::forward<Args>(args)...);
            component->setParent(this);
            component->setOwner(this);

            auto rv = component.get();

            addComponentToStorage(std::move(component), NoDynamicCast);

            return rv;
        }


        template <typename ComponentType, typename... Args>
            requires IsComponentType<ComponentType>
        ComponentType* createDefaultComponent(Args&& ... args)
        {
            //ComponentType* component = new ComponentType{std::forward<Args>(args)...};
            auto component = std::make_unique<ComponentType>(std::forward<Args>(args)...);

            component->setOwner(this);
            auto rv = component.get();

            addComponentToStorage(std::move(component), NoDynamicCast);

            return rv;
        }

        std::unordered_map<IComponent*, IComponent*> mapComponents(GameObject const& gameObject);

    private:

        template<typename ComponentType>
        void addComponentToStorage(std::unique_ptr<ComponentType> component, NoDynamicCastTag tag)
        {
            if constexpr (std::is_base_of_v<IRenderable, ComponentType>)
            {
                renderableComponents.push_back(component.get());
            }

            if constexpr (std::is_base_of_v<IUpdatable, ComponentType>)
            {
                updatableComponents.push_back(component.get());
            }

            staticComponents.push_back(std::move(component));
        };

        void addComponentToStorage(std::unique_ptr<IComponent> component);

        std::vector<IRenderable*> renderableComponents;
        std::vector<IUpdatable*> updatableComponents;
        std::deque<std::unique_ptr<IComponent>> staticComponents;

        friend class ComponentsMapper;
    };
}