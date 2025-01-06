#include "SDLGame.h"

#include "SDLTexture.h"

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

    auto texture = SDLTexture::loadPNG("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    while (isRunning_)
    {
        // update
        eventHandler->handleEvents();
        renderer->startRendering();
        texture.render(renderer.get(), 0, 0);
        renderer->finishRendering();
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
