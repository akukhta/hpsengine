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

SDLCore::Math::IVector2D SDLCore::RenderableComponent::getParentWorldLocation()
{
    if (auto sceneEntityPtr = dynamic_cast<ISceneEntity*>(parent))
    {
        return sceneEntityPtr->getWorldLocation();
    }

    return {0,0};
}

void SDLCore::RenderableComponent::setScale(Math::FVector2D scale)
{
    this->scale = scale;
}

SDLCore::Math::FVector2D const& SDLCore::RenderableComponent::getScale() const
{
    return scale;
}

std::pair<int, int> SDLCore::RenderableComponent::getRenderableSize() const
{
    return std::make_pair(relativeLocation.x * scale.x, relativeLocation.y * scale.y);
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