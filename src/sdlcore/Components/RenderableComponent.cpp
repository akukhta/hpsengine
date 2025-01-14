#include "RenderableComponent.h"

SDLCore::RenderableComponent::RenderableComponent(Math::IVector2D relativeLocation)
    : relativeLocation(relativeLocation)
{}

void SDLCore::RenderableComponent::setRelativeLocation(Math::IVector2D relativeLocation)
{
    this->relativeLocation = relativeLocation;
}

SDLCore::Math::IVector2D const & SDLCore::RenderableComponent::getRelativeLocation() const
{
    return relativeLocation;
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

}

void SDLCore::RenderableComponent::setParent(GameObject *parent)
{
    this->parent = parent;
}

SDLCore::GameObject * SDLCore::RenderableComponent::getParent() const
{
    return parent;
}
