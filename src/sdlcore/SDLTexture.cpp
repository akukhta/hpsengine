#include "SDLTexture.h"
#include "SDLRenderer.h"
#include <string>
#include <stdexcept>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

SDLCore::SDLTexture SDLCore::SDLTexture::loadFromBMP(std::string const &fileName, SDLRenderer const *renderer)
{
    auto const tmpSurface = SurfacePtr{SDL_LoadBMP(fileName.c_str()), &SDL_FreeSurface};

    if (!tmpSurface)
    {
        throw std::runtime_error("Unable to load image");
    }

    auto texture = TexturePtr{SDL_CreateTextureFromSurface(renderer->getRenderer(), tmpSurface.get()), &SDL_DestroyTexture};

    return SDLTexture{std::move(texture)};
}

SDLCore::SDLTexture SDLCore::SDLTexture::loadPNG(std::string const &fileName, SDLRenderer const *renderer)
{
    TexturePtr texture{IMG_LoadTexture(renderer->getRenderer(), fileName.c_str()), &SDL_DestroyTexture};

    if (!texture)
    {
        throw std::runtime_error("Unable to load image: " + std::string{IMG_GetError()});
    }

    return SDLTexture{std::move(texture)};
}


SDLCore::SDLTexture::TexturePtr SDLCore::SDLTexture::loadPNGRaw(std::string const &fileName, SDLRenderer const* renderer)
{
    TexturePtr texture{IMG_LoadTexture(renderer->getRenderer(), fileName.c_str()), &SDL_DestroyTexture};

    if (!texture)
    {
        throw std::runtime_error("Unable to load image: " + std::string{IMG_GetError()});
    }

    return texture;
}

void SDLCore::SDLTexture::setTextureSize(std::pair<int, int> const &size)
{
    srcRect.w = size.first;
    srcRect.h = size.second;
}

void SDLCore::SDLTexture::setTextureSize(int width, int height)
{
    srcRect.w = width;
    srcRect.h = height;
}

void SDLCore::SDLTexture::setTextureSize(int const *width, int const *height)
{
    if (width)
    {
        srcRect.w = *width;
    }

    if (height)
    {
        srcRect.h = *height;
    }
}

void SDLCore::SDLTexture::setTextureOffset(std::pair<int, int> const &offset)
{
    srcRect.x = offset.first;
    srcRect.y = offset.second;
}

void SDLCore::SDLTexture::setTextureOffset(int x, int y)
{
    srcRect.x = x;
    srcRect.y = y;
}

void SDLCore::SDLTexture::setTextureOffset(int const *x, int const *y)
{
    if (x)
    {
        srcRect.x = *x;
    }

    if (y)
    {
        srcRect.y = *y;
    }
}

void SDLCore::SDLTexture::resetSizeAndOffset()
{
    SDL_QueryTexture(this->texture.get(), nullptr, nullptr, &textureSize.first, &textureSize.second);
    srcRect = SDL_Rect{0, 0, textureSize.first, textureSize.second};
}

std::pair<int, int> SDLCore::SDLTexture::getTextureSize() const
{
    return textureSize;
}

SDLCore::SDLTexture::SDLTexture(TexturePtr texture)
    : texture(std::move(texture))
{
    resetSizeAndOffset();
}
