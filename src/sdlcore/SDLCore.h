#pragma once
#include "SDLWindow.h"
#include "SDLRenderer.h"
#include "SDLTimeController.h"

namespace SDLCore
{
    class SDLCore
    {
    public:
        SDLCore() = default;
        SDLCore(const SDLCore&) = delete;
        SDLCore& operator=(const SDLCore&) = delete;
        SDLCore(SDLCore&&) = delete;
        SDLCore& operator=(SDLCore&&) = delete;
        ~SDLCore();

        bool initSDL();
        bool initImage();
        bool initFont();

        std::unique_ptr<SDLWindow> createWindow(std::string_view title, std::pair<int, int> size, std::pair<int, int> pos, bool isShown, bool isFullscreen);

        std::unique_ptr<SDLRenderer> createRenderer(std::unique_ptr<SDLWindow> &window);
        std::unique_ptr<SDLRenderer> createRenderer(SDLWindow* window);

        SDLTimeController& getTimeController();
    };
}