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

std::pair<int, int> SDLCore::RenderableComponent::getRenderableSize() const
{
    return std::make_pair(this->relativeLocation.x * scale.x, this->relativeLocation.y * scale.y);
}

SDLCore::Math::IVector2D SDLCore::RenderableComponent::getParentWorldLocation() const
{
    if (auto sceneEntityPtr = dynamic_cast<ISceneEntity*>(parent))
    {
        return sceneEntityPtr->getWorldLocation();
    }

    return {0,0};
}

std::pair<int, int> SDLCore::RenderableComponent::getParentRenderableSize()
{
    if (auto renderableParent = dynamic_cast<IRenderable*>(parent); renderableParent != nullptr)
    {
        return renderableParent->getRenderableSize();
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