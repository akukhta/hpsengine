#pragma once
#include "IInputManager.h"
#include <unordered_map>
#include <memory>
#include <SDL2/SDL_gamecontroller.h>
#include "SDLGamepad.h"
#include "SDLMouse.h"

namespace SDLCore
{
    class SDLInputManager : public IInputManager
    {
    public:
        SDLInputManager() = default;

        void init() override;
        void handleEvent(SDL_Event event) override;

    private:
        void initGamepads();

        std::unordered_map<int, std::unique_ptr<SDLGamepad>> findGamepads();
        void removeGamepads();
        void gamepadAdded(int gamepadId);
        void gamepadRemoved(int gamepadId);

        // XBOX360
        // Left & Right movements on stick one is axis 0
        // Up & down movements on stick one is axis 1
        // Left & right movements on stick two is axis 3
        // Up & down movements on stick two is axis 4
        // Axis 2 and 5 are for the analog triggers
        std::unordered_map<int, std::unique_ptr<SDLGamepad>> gamepads;
        SDLMouse mouse;
    };
}
