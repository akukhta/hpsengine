#pragma once
#include <SDL2/SDL.h>
#include <memory>
#include <string_view>

namespace SDLCore
{
    class SDLWindow
    {
    public:
        SDLWindow(std::string_view title, std::pair<int, int> size, std::pair<int, int> pos, bool isShown, bool isFullscreen);

    private:
        std::string_view windowName;
        std::pair<int, int> size;
        std::pair<int, int> position;
        bool isShown;
        bool isFullscreen;

        using WindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
        WindowPtr window = WindowPtr(nullptr, &SDL_DestroyWindow);

        friend class SDLRenderer;
    };
}
