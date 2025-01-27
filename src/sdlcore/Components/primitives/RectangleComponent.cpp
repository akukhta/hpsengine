#include "RectangleComponent.h"
#include "../../IRenderer.h"
#include "../../GameObject/GameObject.h"

SDLCore::Primitives::RectangleComponent::RectangleComponent(SDLCore::Math::IVector2D pos, int width, int height, SDL_Color color, bool fill)
    : RenderableComponent(pos), color(color), width(width), height(height), fill(fill)
{}

SDLCore::Primitives::RectangleComponent::RectangleComponent(Math::Rectangle box, SDL_Color color, bool fill)
    : RenderableComponent(Math::IVector2D{box.x,box.y}), color(color), width(box.width), height(box.height), fill(fill)
{}

SDLCore::Primitives::RectangleComponent::RectangleComponent(RectangleComponent const &other)
    : RenderableComponent(other), width(other.width), height(other.height), fill(other.fill), color(other.color)
{}

void SDLCore::Primitives::RectangleComponent::render(SDLCore::IRenderer *renderer)
{
    auto pos = getParentWorldLocation();
    renderer->renderRectangle(this, pos.x + relativeLocation.x, pos.y + relativeLocation.y, width, height);
}

SDLCore::Math::Rectangle SDLCore::Primitives::RectangleComponent::getBoundingBox() const
{
    auto parentPos = getWorldLocation();
    return Math::Rectangle(parentPos.x, parentPos.y, width, height);
}

SDLCore::IComponent * SDLCore::Primitives::RectangleComponent::clone()
{
    return new RectangleComponent(*this);
}
