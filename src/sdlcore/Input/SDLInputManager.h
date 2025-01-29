#pragma once
#include "IInputManager.h"
#include "IInputDevice.h"
#include "../IUpdatable.h"
#include <unordered_map>
#include <memory>
#include <SDL2/SDL_gamecontroller.h>

namespace SDLCore
{
    class SDLInputManager : public IInputManager
    {
    public:
        SDLInputManager() = default;

        void init() override;
        void update(double deltaTime) override;

    private:
        void initGamepads();

        std::unordered_map<int, SDL_GameController*> findGamepads();
        void removeGamepads();
        void gamepadAdded(int gamepadId);
        void gamepadRemoved(int gamepadId);

        std::unordered_map<int, SDL_GameController*> gamepads;
    };
}
