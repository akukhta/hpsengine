#include "SDLTexture.h"
#include "SDLRenderer.h"
#include <string>
#include <stdexcept>
#include <SDL2/SDL_image.h>

SDLCore::SDLTexture SDLCore::SDLTexture::loadFromBMP(std::string const &fileName, SDLRenderer* renderer)
{
    SurfacePtr tmpSurface = SurfacePtr{SDL_LoadBMP(fileName.c_str()), &SDL_FreeSurface};

    if (!tmpSurface)
    {
        throw std::runtime_error("Unable to load image");
    }

    TexturePtr texture = TexturePtr{SDL_CreateTextureFromSurface(renderer->getRenderer(), tmpSurface.get()), &SDL_DestroyTexture};

    return SDLTexture{std::move(texture)};
}

SDLCore::SDLTexture SDLCore::SDLTexture::loadPNG(std::string const &fileName, SDLRenderer *renderer)
{
    TexturePtr texture{IMG_LoadTexture(renderer->getRenderer(), fileName.c_str()), &SDL_DestroyTexture};

    if (!texture)
    {
        throw std::runtime_error("Unable to load image: " + std::string{IMG_GetError()});
    }

    return SDLTexture{std::move(texture)};
}

void SDLCore::SDLTexture::render(IRenderer *renderer, int x, int y)
{
    renderer->render(this, x, y, srcRect.w, srcRect.h);
}

void SDLCore::SDLTexture::render(IRenderer *renderer, int x, int y, int w, int h)
{
    renderer->render(this, x, y, w, h);
}

SDLCore::SDLTexture::SDLTexture(TexturePtr texture)
    : texture(std::move(texture))
{
    SDL_QueryTexture(this->texture.get(), nullptr, nullptr, &textureSize.first, &textureSize.second);
    srcRect = SDL_Rect{0, 0, textureSize.first, textureSize.second};
}
