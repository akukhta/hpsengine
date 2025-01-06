#include "Rectangle.h"
#include "../sdlcore/IRenderer.h"

Primitives::Rectangle::Rectangle(int width, int height, SDL_Color color, bool fill)
    : size(std::make_pair(width, height)), color(std::move(color)), fill(fill)
{
    srcRect = SDL_Rect{0, 0, width, height};
}

void Primitives::Rectangle::render(SDLCore::IRenderer *renderer, int x, int y)
{
    renderer->renderRectangle(this, x, y);
}

void Primitives::Rectangle::render(SDLCore::IRenderer *renderer, int x, int y, int w, int h)
{
    renderer->renderRectangle(this, x, y, w, h);
}
