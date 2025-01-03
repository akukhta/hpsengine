#include "SDLWindow.h"

SDLCore::SDLWindow::SDLWindow(std::string_view title, std::pair<int, int> size, std::pair<int, int> pos, bool isShown,
    bool isFullscreen) : windowName(title), size(size), position(pos), isShown(isShown), isFullscreen(isFullscreen)
{
    window = WindowPtr{SDL_CreateWindow(windowName.data(),
        position.first, position.second,
        size.first, size.second,
        (SDL_WINDOW_SHOWN * isShown) | (SDL_WINDOW_FULLSCREEN * isFullscreen)), &SDL_DestroyWindow};

    if (!window)
    {
        throw std::runtime_error("Failed to create SDL window");
    }
}
