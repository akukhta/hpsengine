#pragma once
#include <cstdint>

namespace SDLCore
{
    class SDLTimeController
    {
    public:
        SDLTimeController(const SDLTimeController&) = delete;
        SDLTimeController& operator=(const SDLTimeController&) = delete;
        SDLTimeController(SDLTimeController&&) = delete;
        SDLTimeController& operator=(SDLTimeController&&) = delete;

        // Static proxy functions to avoid calls to "getInstance()" every time
        static std::uint32_t getTicks();
        static double getDeltaTime();
        static void update();
        static void pause();
        static void resume();
        static void reset();

    private:
        SDLTimeController() = default;
        ~SDLTimeController() = default;

        static SDLTimeController& getInstance();

        std::uint32_t currentTicks = 0; // Last checked ticks
        double deltaTime = 0; // In Seconds (1 = 1 second)

        double getDeltaTimeImpl() const;
        void updateImpl();
        void pauseImpl();
        void resumeImpl();
        void resetImpl();
        std::uint32_t getTicksImpl() const;

        bool isPaused = false;
        friend class SDLCore;
    };
}