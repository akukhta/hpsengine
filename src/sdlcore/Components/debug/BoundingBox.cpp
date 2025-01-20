#include "BoundingBox.h"

SDLCore::BoundingBox::BoundingBox(IEntity* parent, SDL_Color color)
    : RectangleComponent({0, 0}, 0, 0, color, false)
{
    setParent(parent);
}

void SDLCore::BoundingBox::render(SDLCore::IRenderer *renderer)
{
    calculateBoundingBox();
    RectangleComponent::render(renderer);
}

std::pair<int, int> SDLCore::BoundingBox::getRenderableSize() const
{
    return std::make_pair(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
}

void SDLCore::BoundingBox::calculateBoundingBox()
{
    relativeLocation = getParentWorldLocation();
    auto bounds = getParentRenderableSize();

    width = bounds.first;
    height = bounds.second;
}
