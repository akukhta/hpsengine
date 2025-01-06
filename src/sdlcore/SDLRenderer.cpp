#include "SDLRenderer.h"
#include "SDLWindow.h"
#include <SDL2/SDL_render.h>
#include <stdexcept>
#include "SDLTexture.h"
#include <SDL2/SDL_render.h>
#include "../primitives/Rectangle.h"

SDLCore::SDLRenderer::SDLRenderer(class SDLWindow *window)
{
    if (!window->window)
    {
        throw std::invalid_argument("Invalid SDL Window");
    }

    renderer = RendererPtr{SDL_CreateRenderer(window->window.get(), -1, SDL_RENDERER_ACCELERATED), &SDL_DestroyRenderer};
}

void SDLCore::SDLRenderer::setResolution(int width, int height)
{
    resolution = std::make_pair(width, height);
    changeResolution();
}

void SDLCore::SDLRenderer::setResolution(std::pair<int, int> resolution)
{
    this->resolution = resolution;
    changeResolution();
}

std::pair<int, int> SDLCore::SDLRenderer::getResolution()
{
    return resolution;
}

void SDLCore::SDLRenderer::render()
{
    SDL_RenderClear(renderer.get());

    SDL_RenderPresent(renderer.get());
}

void SDLCore::SDLRenderer::startRendering()
{
    SDL_RenderClear(renderer.get());
}

void SDLCore::SDLRenderer::finishRendering()
{
    SDL_RenderPresent(renderer.get());
}

void SDLCore::SDLRenderer::render(SDLTexture *texture, int x, int y, int w, int h)
{
    if (!texture)
    {
        return;
    }

    SDL_Rect dst = {x, y, w, h};
    SDL_RenderCopy(renderer.get(), texture->texture.get(), &texture->srcRect, &dst);
}

void SDLCore::SDLRenderer::render(Primitives::Rectangle *rectangle, int x, int y, int w, int h)
{
    if (!rectangle)
    {
        return;
    }

    auto prevColor = exchangeColor(rectangle->color);

    SDL_Rect dst = {x, y, w, h};

    if (rectangle->fill)
    {
        SDL_RenderFillRect(renderer.get(), &dst);
    }
    else
    {
        SDL_RenderDrawRect(renderer.get(), &dst);
    }

    setDrawColor(prevColor);
}

void SDLCore::SDLRenderer::render(Primitives::Rectangle *rectangle, int x, int y)
{
    if (!rectangle)
    {
        return;
    }

    auto prevColor = exchangeColor(rectangle->color);

    SDL_Rect dst = {x, y, rectangle->srcRect.w, rectangle->srcRect.h};

    if (rectangle->fill)
    {
        SDL_RenderFillRect(renderer.get(), &dst);
    }
    else
    {
        SDL_RenderDrawRect(renderer.get(), &dst);
    }

    setDrawColor(prevColor);
}

void SDLCore::SDLRenderer::render(Primitives::Circle *circle, int x, int y, int r)
{
    if (!circle)
    {
        return;
    }
    auto prevColor = exchangeColor(circle->color);

    for (auto const& point : circle->points)
    {
        SDL_RenderDrawPoint(renderer.get(), point.x, point.y);
    }

    setDrawColor(prevColor);
}

void SDLCore::SDLRenderer::changeResolution()
{
    if (renderer)
    {
        SDL_RenderSetLogicalSize(renderer.get(), resolution.first, resolution.second);
    }
}

SDL_Color SDLCore::SDLRenderer::getDrawColor()
{
    SDL_Color color;
    SDL_GetRenderDrawColor(renderer.get(), &color.r, &color.g, &color.b, &color.a);

    return color;
}

void SDLCore::SDLRenderer::setDrawColor(SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer.get(), color.r, color.g, color.b, color.a);
}

SDL_Color SDLCore::SDLRenderer::exchangeColor(SDL_Color color)
{
    auto prevColor = getDrawColor();
    setDrawColor(color);

    return prevColor;
}

