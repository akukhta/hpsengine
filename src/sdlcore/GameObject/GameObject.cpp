#include "GameObject.h"
#include <unordered_map>

SDLCore::GameObject::GameObject(const GameObject &other)
{
    /// Original Component Ptr => Component Copy Ptr
    std::unordered_map<IComponent*, IComponent*> componentsMap;

    for (auto &component : other.staticComponents)
    {
        auto componentCopy = std::unique_ptr<IComponent>(component->clone());
        componentsMap[component.get()] = componentCopy.get();
        staticComponents.push_back(std::move(componentCopy));
    }

    for (auto& origComponent : other.staticComponents)
    {
        if (origComponent->getParent() == &other)
        {
            componentsMap[origComponent.get()]->setParent(this);
        }
        else
        {
            componentsMap[origComponent.get()]->setParent(
                componentsMap[dynamic_cast<IComponent*>(origComponent->getParent())]);
        }
    }

    for (auto& component : staticComponents)
    {
        component->setOwner(this);

        if (auto renderablePtr = dynamic_cast<IRenderable*>(component.get()); renderablePtr != nullptr)
        {
            renderableComponents.push_back(renderablePtr);
        }

        if (auto updatablePtr = dynamic_cast<IUpdatable*>(component.get()); updatablePtr != nullptr)
        {
            updatableComponents.push_back(updatablePtr);
        }
    }
}

void SDLCore::GameObject::render(IRenderer *renderer)
{
    if (isVisible)
    {
        for (auto& renderable : renderableComponents)
        {
            renderable->render(renderer);
        }
    }
}

void SDLCore::GameObject::update(double deltaTime)
{
    for (auto& updatable : updatableComponents)
    {
        updatable->update(deltaTime);
    }
}

void SDLCore::GameObject::setPosition(Math::IVector2D position)
{
    this->position = position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getWorldLocation() const
{
    return position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getRelativeLocation() const
{
    return {0, 0};
}

SDLCore::Math::Rectangle SDLCore::GameObject::getBoundingBox() const
{
    Math::Rectangle boundingBox = Math::Rectangle::createDefaultBoundingBox();

    for (auto &renderable : renderableComponents)
    {
        auto componentSize = renderable->getBoundingBox();

        boundingBox.x = std::min(boundingBox.x, componentSize.x);
        boundingBox.y = std::min(boundingBox.y, componentSize.y);
        boundingBox.width = std::max(boundingBox.width, componentSize.width + componentSize.x);
        boundingBox.height = std::max(boundingBox.height, componentSize.height + componentSize.y);
    }

    return boundingBox;
}

void SDLCore::GameObject::attach(std::unique_ptr<IEntity> child)
{
    IComponent* componentPtr = dynamic_cast<IComponent*>(child.get());

    if (componentPtr == nullptr)
    {
        throw std::runtime_error("GameObject::attach: child is not a Component");
    }

    addComponentToStorage(std::unique_ptr<IComponent>(dynamic_cast<IComponent*>(child.release())));
}

///
/// @param gameObject
/// @return other component ptr => current component ptr
std::unordered_map<SDLCore::IComponent *, SDLCore::IComponent *> SDLCore::GameObject::mapComponents(
    GameObject const &gameObject)
{
    std::unordered_map<SDLCore::IComponent*, SDLCore::IComponent*> componentsMap;

    if (staticComponents.size() != gameObject.staticComponents.size())
    {
        throw std::runtime_error("Cannot map object with different set of components");
    }

    for (size_t i = 0; i < staticComponents.size(); ++i)
    {
        componentsMap[gameObject.staticComponents[i].get()] = staticComponents[i].get();
    }

    return componentsMap;
}

void SDLCore::GameObject::addComponentToStorage(std::unique_ptr<IComponent> component)
{
    if (auto renderablePtr = dynamic_cast<IRenderable*>(component.get()); renderablePtr != nullptr)
    {
        renderableComponents.push_back(renderablePtr);
    }

    if (auto updatablePtr = dynamic_cast<IUpdatable*>(component.get()); updatablePtr != nullptr)
    {
        updatableComponents.push_back(updatablePtr);
    }

    staticComponents.push_back(std::move(component));
}
