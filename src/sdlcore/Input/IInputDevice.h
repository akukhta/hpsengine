#pragma once

namespace SDLCore
{
    class IInputDevice
    {
    public:
        IInputDevice(IInputDevice const&) = default;
        IInputDevice& operator=(IInputDevice const&) = default;
        IInputDevice(IInputDevice&&) = default;
        IInputDevice& operator=(IInputDevice&&) = default;
        virtual ~IInputDevice() = default;
    };
}