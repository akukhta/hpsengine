#include "SDLRenderer.h"
#include "SDLWindow.h"
#include <SDL2/SDL_render.h>

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

void SDLCore::SDLRenderer::changeResolution()
{
    if (renderer)
    {
        SDL_RenderSetLogicalSize(renderer.get(), resolution.first, resolution.second);
    }
}

