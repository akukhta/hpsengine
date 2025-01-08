#include "LoadPNG.h"
#include "../SDLRenderer.h"
#include <SDL_image.h>

std::unique_ptr<SDLCore::SDLTexture> SDLCore::LoadPNG::load(const std::string &fileName, IRenderer *renderer)
{
    auto sdlRenderer = dynamic_cast<SDLRenderer*>(renderer);

    if (sdlRenderer == nullptr)
    {
        return nullptr;
    }

    SDLTexture::TexturePtr texture{IMG_LoadTexture(sdlRenderer->getRenderer(), fileName.c_str()), &SDL_DestroyTexture};

    if (!texture)
    {
        throw std::runtime_error("Unable to load image: " + std::string{IMG_GetError()});
    }

    return std::make_unique<SDLTexture>(std::move(texture));
}
