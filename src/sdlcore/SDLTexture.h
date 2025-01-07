#pragma once
#include <SDL2/SDL.h>
#include <memory>
#include <utility>
#include "IRenderable.h"

namespace SDLCore
{
    class SDLTexture : public IRenderable
    {
    public:
        static SDLTexture loadFromBMP(std::string const& fileName, class SDLRenderer* renderer);
        static SDLTexture loadPNG(std::string const& fileName, SDLRenderer* renderer);

        void render(IRenderer *renderer, int x, int y) override;
        void render(IRenderer *renderer, int x, int y, int w, int h) override;
        void render(IRenderer *renderer, const Rectangle &src, const Rectangle &dst) override;

        void setTextureSize(std::pair<int, int> const& size);
        void setTextureSize(int width, int height);
        void setTextureSize(int *width, int *height);

        void setTextureOffset(std::pair<int, int> const& offset);
        void setTextureOffset(int x, int y);
        void setTextureOffset(int *x, int *y);

        void resetSizeAndOffset();

    protected:
        friend class SDLRenderer;

        using TexturePtr = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
        using SurfacePtr = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;

        explicit SDLTexture(TexturePtr texture);

        static TexturePtr loadPNGRaw(std::string const& fileName, SDLRenderer* renderer);

        TexturePtr texture;
        std::pair<int, int> textureSize;
        SDL_Rect srcRect;
    };
}
