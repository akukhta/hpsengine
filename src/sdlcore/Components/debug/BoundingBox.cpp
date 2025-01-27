#include "BoundingBox.h"

SDLCore::BoundingBox::BoundingBox(SDL_Color color, IEntity* parent)
    : RectangleComponent({0, 0}, 0, 0, color, false)
{
    setParent(parent);
}

SDLCore::BoundingBox::BoundingBox(BoundingBox const &other)
    : RectangleComponent(other)
{}

void SDLCore::BoundingBox::render(SDLCore::IRenderer *renderer)
{
    if (!isVisible)
    {
        return;
    }

    calculateBoundingBox();
    renderer->renderRectangle(this, relativeLocation.x, relativeLocation.y, width, height);
    //RectangleComponent::render(renderer);
}

SDLCore::Math::Rectangle SDLCore::BoundingBox::getBoundingBox() const
{
    return Math::Rectangle::createDefaultBoundingBox();
}

SDLCore::IComponent * SDLCore::BoundingBox::clone()
{
    return new BoundingBox(*this);
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
