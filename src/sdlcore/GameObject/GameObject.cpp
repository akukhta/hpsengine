#include "GameObject.h"

void SDLCore::GameObject::render(IRenderer *renderer, int x, int y)
{
    for (auto & renderable : renderableComponents)
    {
        renderable->render(renderer, x, y);
    }
}

void SDLCore::GameObject::render(IRenderer *renderer, int x, int y, int w, int h)
{
    for (auto & renderable : renderableComponents)
    {
        renderable->render(renderer, x, y, w, h);
    }
}

void SDLCore::GameObject::render(IRenderer *renderer, const Math::Rectangle &src, const Math::Rectangle &dst)
{
    for (auto & renderable : renderableComponents)
    {
        renderable->render(renderer, src, dst);
    }
}

void SDLCore::GameObject::render(IRenderer *renderer, int x, int y, int r)
{
    for (auto & renderable : renderableComponents)
    {
        renderable->render(renderer, x, y, r);
    }
}

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
