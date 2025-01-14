#include "SDLRenderer.h"
#include "SDLWindow.h"
#include <SDL2/SDL_render.h>
#include <stdexcept>
#include "SDLTexture.h"
#include <SDL2/SDL_render.h>
#include "Components/primitives/RectangleComponent.h"
#include "Components/primitives/CircleComponent.h"

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

std::pair<int, int> SDLCore::SDLRenderer::getResolution() const
{
    return resolution;
}

void SDLCore::SDLRenderer::renderTexture()
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

void SDLCore::SDLRenderer::renderTexture(SDLTexture *texture, int x, int y, int w, int h)
{
    if (!texture)
    {
        return;
    }

    SDL_Rect dst = {x, y, w, h};
    SDL_RenderCopy(renderer.get(), texture->texture.get(), &texture->srcRect, &dst);
}

void SDLCore::SDLRenderer::renderTexture(SDLTexture *texture, Math::Rectangle const &src, Math::Rectangle const &dst)
{
    if (!texture)
    {
        return;
    }

    SDL_Rect sdlSrc{src.x, src.y, src.width, src.height};
    SDL_Rect sdlDst{dst.x, dst.y, dst.width, dst.height};

    SDL_RenderCopy(renderer.get(), texture->texture.get(), &sdlSrc, &sdlDst);
}

void SDLCore::SDLRenderer::renderTexture(SDLTexture *texture, Math::IVector2D pos, std::pair<int, int> size)
{
    if (!texture)
    {
        return;
    }

    Math::Rectangle src{0, 0, texture->getTextureSize().first, texture->getTextureSize().second};
    Math::Rectangle dst{pos.x, pos.y, size.first, size.second};

    renderTexture(texture, src, dst);
}

void SDLCore::SDLRenderer::renderRectangle(Primitives::RectangleComponent *rectangle, int x, int y, int w, int h)
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

void SDLCore::SDLRenderer::renderCircle(Primitives::CircleComponent *circle, int centerX, int centerY, int r)
{
    if (!circle)
    {
        return;
    }
    auto prevColor = exchangeColor(circle->color);

    if (!circle->filled)
    {
        for (auto const& point : circle->points)
        {
            SDL_RenderDrawPoint(renderer.get(), point.x, point.y);
        }
    }
    else
    {
        for (int y = -r; y <= r; ++y)
        {
            int x = static_cast<int>(sqrt(r * r - y * y));
            SDL_RenderDrawLine(renderer.get(), centerX - x, centerY + y, centerX + x, centerY + y);
        }
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

SDL_Color SDLCore::SDLRenderer::getDrawColor() const
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

