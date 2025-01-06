#pragma once
#include <deque>
#include <functional>
#include "IRenderer.h"

namespace SDLCore
{
    class RenderingQueue
    {
    public:
        using RenderingCommand = std::function<void(IRenderer*)>;
        void push(RenderingCommand command);

    private:
        friend class SDLRenderer;
        std::deque<RenderingCommand> renderingCommands;
    };
}
