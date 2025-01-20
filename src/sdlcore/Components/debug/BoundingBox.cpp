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

SDLCore::Math::Rectangle SDLCore::BoundingBox::getBoundingBox() const
{
    return Math::Rectangle::createDefaultBoundingBox();
}

void SDLCore::BoundingBox::calculateBoundingBox()
{
    if (auto renderableParent = dynamic_cast<IRenderable*>(parent); renderableParent != nullptr)
    {
        auto parentBBox = renderableParent->getBoundingBox();

        relativeLocation = Math::IVector2D{parentBBox.x, parentBBox.y};

        width = parentBBox.width;
        height = parentBBox.height;
    }
}
