#include "GameObject.h"

void SDLCore::GameObject::render(IRenderer *renderer)
{
    for (auto& renderable : renderableComponents)
    {
        renderable->render(renderer);
    }
}

void SDLCore::GameObject::update(double deltaTime)
{
    for (auto& updatable : updatableComponents)
    {
        updatable->update(deltaTime);
    }
}

void SDLCore::GameObject::setPosition(Math::IVector2D position)
{
    this->position = position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getWorldLocation() const
{
    return position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getRelativeLocation() const
{
    return {0, 0};
}

SDLCore::Math::Rectangle SDLCore::GameObject::getBoundingBox() const
{
    Math::Rectangle boundingBox = Math::Rectangle::createMin();

    for (auto &renderable : renderableComponents)
    {
        auto componentSize = renderable->getBoundingBox();

        boundingBox.x = std::max(boundingBox.x, componentSize.x);
        boundingBox.y = std::max(boundingBox.y, componentSize.y);
        boundingBox.width = std::max(boundingBox.width, componentSize.width);
        boundingBox.height = std::max(boundingBox.height, componentSize.height);
    }

    return boundingBox;
}
