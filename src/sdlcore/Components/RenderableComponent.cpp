#include "RenderableComponent.h"

#include "../GameObject/GameObject.h"

SDLCore::RenderableComponent::RenderableComponent(Math::IVector2D relativeLocation)
    : relativeLocation(relativeLocation)
{}

void SDLCore::RenderableComponent::setRelativeLocation(Math::IVector2D relativeLocation)
{
    this->relativeLocation = relativeLocation;
}

SDLCore::Math::IVector2D SDLCore::RenderableComponent::getRelativeLocation() const
{
    return relativeLocation;
}

SDLCore::Math::Rectangle SDLCore::RenderableComponent::getBoundingBox() const
{
    auto worldPos = getWorldLocation();
    return Math::Rectangle{worldPos.x, worldPos.y,
        static_cast<int>(scale.x), static_cast<int>(scale.y)};
}

void SDLCore::RenderableComponent::attach(std::unique_ptr<IEntity> attachedComponent)
{
    if (owner == nullptr)
    {
        throw std::runtime_error("Memory Leak: Cannot attach component to a component without parent");
    }

    attachedComponent->setParent(this);
    owner->attach(std::move(attachedComponent));
}

SDLCore::Math::IVector2D SDLCore::RenderableComponent::getParentWorldLocation() const
{
    if (auto sceneEntityPtr = dynamic_cast<ISceneEntity*>(parent))
    {
        return sceneEntityPtr->getWorldLocation();
    }

    return {0,0};
}

SDLCore::Math::Rectangle SDLCore::RenderableComponent::getParentRenderableSize()
{
    if (auto renderableParent = dynamic_cast<IRenderable*>(parent); renderableParent != nullptr)
    {
        return renderableParent->getBoundingBox();
    }
    else
    {
        return {0,0};
    }
}

void SDLCore::RenderableComponent::setScale(Math::FVector2D scale)
{
    this->scale = scale;
}

SDLCore::Math::FVector2D const& SDLCore::RenderableComponent::getScale() const
{
    return scale;
}

void SDLCore::RenderableComponent::update(double deltaTime)
{
    ;
}

SDLCore::Math::IVector2D SDLCore::RenderableComponent::getWorldLocation() const
{
    if (auto sceneEntityPtr = dynamic_cast<ISceneEntity*>(parent); sceneEntityPtr != nullptr)
    {
        return sceneEntityPtr->getWorldLocation() + relativeLocation;
    }
    else
    {
        return relativeLocation;
    }
}