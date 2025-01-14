#include "RectangleComponent.h"
#include "../../IRenderer.h"
#include "../../GameObject/GameObject.h"

SDLCore::Primitives::RectangleComponent::RectangleComponent(SDLCore::Math::IVector2D pos, int width, int height, SDL_Color color, bool fill)
    : relativePosition(pos.x, pos.y), color(color), width(width), height(height), fill(fill)
{}

void SDLCore::Primitives::RectangleComponent::setParent(GameObject *parent)
{
    this->parent = parent;
}

SDLCore::GameObject* SDLCore::Primitives::RectangleComponent::getParent() const
{
    return parent;
}

SDLCore::Math::IVector2D const & SDLCore::Primitives::RectangleComponent::getRelativePosition() const
{
    return relativePosition;
}

void SDLCore::Primitives::RectangleComponent::render(SDLCore::IRenderer *renderer)
{
    auto pos = parent->getPosition();
    renderer->renderRectangle(this, pos.x + relativePosition.x, pos.y + relativePosition.y, width, height);
}
