#pragma once
#include "../IUpdatable.h"

namespace SDLCore
{
    class IInputManager : public IUpdatable
    {
    public:
        IInputManager() = default;
        IInputManager(IInputManager const&) = default;
        IInputManager& operator=(IInputManager const&) = default;
        IInputManager(IInputManager&&) = default;
        IInputManager& operator=(IInputManager&&) = default;
        virtual ~IInputManager() = default;

        virtual void init() = 0;
    };
}