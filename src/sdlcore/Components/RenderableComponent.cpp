#include "RenderableComponent.h"

SDLCore::RenderableComponent::RenderableComponent(Math::IVector2D relativePosition)
    : relativePosition(relativePosition)
{}

SDLCore::Math::IVector2D const & SDLCore::RenderableComponent::getRelativePosition() const
{
    return relativePosition;
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
