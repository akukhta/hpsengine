#include "LoadBMP.h"
#include <SDL2/SDL.h>
#include "../SDLRenderer.h"

std::unique_ptr<SDLCore::SDLTexture> SDLCore::LoadBMP::load(const std::string &fileName, IRenderer *renderer)
{
    auto sdlRenderer = dynamic_cast<SDLRenderer*>(renderer);

    if (!sdlRenderer)
    {
        return nullptr;
    }

    SDLTexture::SurfacePtr tmpSurface = SDLTexture::SurfacePtr{SDL_LoadBMP(fileName.c_str()), &SDL_FreeSurface};

    if (!tmpSurface)
    {
        throw std::runtime_error("Unable to load image");
    }

    SDLTexture::TexturePtr texture = SDLTexture::TexturePtr{SDL_CreateTextureFromSurface(sdlRenderer->getRenderer(), tmpSurface.get()), &SDL_DestroyTexture};

    return std::make_unique<SDLTexture>(std::move(texture));

}
