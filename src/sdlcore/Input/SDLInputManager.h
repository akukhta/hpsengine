#pragma once
#include "IInputManager.h"
#include "IInputDevice.h"
#include "../IUpdatable.h"
#include <deque>
#include <memory>
#include <SDL2/SDL_gamecontroller.h>

namespace SDLCore
{
    class SDLInputManager : public IInputManager, public IUpdatable
    {
    public:
        void init() override;

        void update(double deltaTime) override;

    private:
        void initGamepads();

        std::deque<SDL_GameController*> findGamepads();
        void removeGamepads();

        std::deque<SDL_GameController*> gamepads;
    };
}
