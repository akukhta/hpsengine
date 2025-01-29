#pragma once

namespace SDLCore
{
    class IInputManager
    {
    public:
        IInputManager(IInputManager const&) = default;
        IInputManager& operator=(IInputManager const&) = default;
        IInputManager(IInputManager&&) = default;
        IInputManager& operator=(IInputManager&&) = default;
        virtual ~IInputManager() = default;

        virtual void init() = 0;
    };
}