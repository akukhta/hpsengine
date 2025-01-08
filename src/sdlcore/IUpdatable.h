#pragma once

namespace SDLCore
{
    class IUpdatable
    {
    public:
        IUpdatable() = default;
        IUpdatable(const IUpdatable&) = default;
        IUpdatable(IUpdatable&&) = default;
        IUpdatable& operator=(const IUpdatable&) = default;
        IUpdatable& operator=(IUpdatable&&) = default;

        virtual ~IUpdatable() = default;

        virtual void update(double deltaTime) = 0;
    };
}