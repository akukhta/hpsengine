#include "SDLGame.h"

SDLCore::SDLGame::SDLGame(RendererPtr renderer, EventHandlerPtr eventHandler)
    : renderer(std::move(renderer)), eventHandler(std::move(eventHandler))
{
    this->eventHandler->addEventHandler(SDLCore::SDLEventHandler::EventType::QUIT, [this](){onGameQuit();});
}

void SDLCore::SDLGame::init()
{
    ;
}

void SDLCore::SDLGame::run()
{
    isRunning_ = true;

    while (isRunning_)
    {
        // update
        eventHandler->handleEvents();
        renderer->render();
    }
}

bool SDLCore::SDLGame::isRunning() const
{
    return isRunning_;
}

void SDLCore::SDLGame::onGameQuit()
{
    isRunning_ = false;
}
