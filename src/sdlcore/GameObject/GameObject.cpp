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

SDLCore::Math::IVector2D SDLCore::GameObject::getPosition() const
{
    return position;
}

void SDLCore::GameObject::setPosition(Math::IVector2D position)
{
    this->position = position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getParentLocation() const
{
    return position;
}
