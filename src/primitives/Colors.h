#pragma once
#include <SDL2/SDL_pixels.h>

namespace Primitives
{
    namespace Colors
    {
        SDL_Color Black{0, 0, 0, 255};
        SDL_Color Red {255, 0, 0, 255};
        SDL_Color Green {0, 255, 0, 255};
        SDL_Color Blue {0, 0, 255, 255};
        SDL_Color Yellow{255, 255, 0, 255};
        SDL_Color Cyan {0, 255, 255, 255};
        SDL_Color Pink {255, 0, 255, 255};
        SDL_Color Gray {192, 192, 192, 255};
        SDL_Color White {255, 255, 255, 255};
    };
}