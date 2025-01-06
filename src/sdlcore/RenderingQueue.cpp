#include "RenderingQueue.h"

void SDLCore::RenderingQueue::push(RenderingCommand command)
{
    renderingCommands.push_back(std::move(command));
}
