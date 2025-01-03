#pragma once

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
};