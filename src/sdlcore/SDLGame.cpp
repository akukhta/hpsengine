#include "SDLGame.h"
#include "SDLTexture.h"
#include "../primitives/Colors.h"
#include "../primitives/Rectangle.h"

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
    Primitives::Rectangle rect{100, 100, Primitives::Colors::Red, true};
    Primitives::Circle c{300, 300, 120, Primitives::Colors::Gray};

    while (isRunning_)
    {
        // update
        eventHandler->handleEvents();
        renderer->startRendering();
        texture.render(renderer.get(), 0, 0);
        rect.render(renderer.get(), 300, 0, 200, 200);
        c.render(renderer.get(), 300, 300, 120);

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
