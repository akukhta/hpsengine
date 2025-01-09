#include "GameObject.h"

void SDLCore::GameObject::render(IRenderer *renderer, int x, int y)
{
    ;
}

void SDLCore::GameObject::render(IRenderer *renderer, int x, int y, int w, int h)
{
    ;
}

void SDLCore::GameObject::render(IRenderer *renderer, const Math::Rectangle &src, const Math::Rectangle &dst)
{
    IRenderable::render(renderer, src, dst);
}

void SDLCore::GameObject::render(IRenderer *renderer, int x, int y, int r)
{
    IRenderable::render(renderer, x, y, r);
}

void SDLCore::GameObject::update(double deltaTime)
{
    ;
}
