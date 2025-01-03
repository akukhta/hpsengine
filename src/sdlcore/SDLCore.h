#pragma once
#include "SDLWindow.h"
#include "SDLRenderer.h"
#include "SDLTimeController.h"

namespace SDLCore
{
    /// Class to initialize SDL subsystems
    /// And create SDL objects and wrappers, such as SDLWindow, SDLRenderer, etc.
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

        enum class Subsystem : std::uint32_t
        {
            Timer = 0x00000001u,
            Audio = 0x00000010u,
            Video = 0x00000020u,
            Joystick = 0x00000200u,
            Haptic = 0x00001000u,
            Gamepad = 0x00002000u,
            Events = 0x00004000u,
            Sensor = 0x00008000u,
        };

        bool isInitialized(Subsystem subsystem) const;
    };
}