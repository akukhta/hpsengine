#pragma once
#include <SDL2/SDL.h>
#include <memory>
#include <utility>
#include <string>
#include "IRenderable.h"

namespace SDLCore
{
    class SDLTexture
    {
    public:
        using TexturePtr = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
        using SurfacePtr = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;

        static SDLTexture loadFromBMP(std::string const& fileName, class SDLRenderer const *renderer);
        static SDLTexture loadPNG(std::string const& fileName, SDLRenderer const *renderer);

        explicit SDLTexture(TexturePtr texture);

        void setTextureSize(std::pair<int, int> const& size);
        void setTextureSize(int width, int height);
        void setTextureSize(int const *width, int const *height);

        void setTextureOffset(std::pair<int, int> const& offset);
        void setTextureOffset(int x, int y);
        void setTextureOffset(int const *x, int const *y);

        void resetSizeAndOffset();

        std::pair<int, int> getTextureSize() const;

    protected:
        friend class SDLRenderer;

        static TexturePtr loadPNGRaw(std::string const& fileName, SDLRenderer const* renderer);

        TexturePtr texture;
        std::pair<int, int> textureSize;
        SDL_Rect srcRect;
    };
}
