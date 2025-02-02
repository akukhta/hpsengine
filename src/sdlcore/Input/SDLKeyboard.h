#pragma once
#include "IInputDevice.h"

namespace SDLCore
{
    class SDLKeyboard : public IInputDevice
    {
    public:
        void handleEvent(const SDL_Event &event) override;

    private:
        void onKeyDown(const SDL_KeyboardEvent &event);
        void onKeyUp(const SDL_KeyboardEvent &event);
    };
}