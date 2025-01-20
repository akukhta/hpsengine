#include "RectangleComponent.h"
#include "../../IRenderer.h"
#include "../../GameObject/GameObject.h"

SDLCore::Primitives::RectangleComponent::RectangleComponent(SDLCore::Math::IVector2D pos, int width, int height, SDL_Color color, bool fill)
    : RenderableComponent(pos), color(color), width(width), height(height), fill(fill)
{}

SDLCore::Primitives::RectangleComponent::RectangleComponent(Math::Rectangle box, SDL_Color color, bool fill)
    : RenderableComponent(Math::IVector2D{box.x,box.y}), color(color), width(box.width), height(box.height), fill(fill)
{}

void SDLCore::Primitives::RectangleComponent::render(SDLCore::IRenderer *renderer)
{
    auto pos = getParentWorldLocation();
    renderer->renderRectangle(this, pos.x + relativeLocation.x, pos.y + relativeLocation.y, width, height);
}

std::pair<int, int> SDLCore::Primitives::RectangleComponent::getRenderableSize() const
{
    auto parentPos = getWorldLocation();
    return std::make_pair(parentPos.x + width, parentPos.y + height);
}
