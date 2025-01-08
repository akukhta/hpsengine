#include "SDLGame.h"
#include "SDLAnimatedSpriteSheet.h"
#include "SDLTexture.h"
#include "../primitives/Colors.h"
#include "../primitives/Rectangle.h"
#include "SDLTimeController.h"
#include <iostream>

#include "Texture/LoadPNG.h"
#include "Texture/TextureManager.h"

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

    TextureManager tManager(std::make_unique<TextureLoadStrategyFactory>());
    auto textureTM = tManager.loadTexture<LoadPNG>("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    auto animation = SDLAnimatedSpriteSheet::loadPNG(renderer.get(), "/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png",
        std::make_pair(96, 96), 0.2, 7);

    Primitives::Rectangle rect{100, 100, Primitives::Colors::Red, true};
    Primitives::Circle c{300, 300, 120, Primitives::Colors::Gray, true};

    animation.setDuration(1);
    animation.setIsRepeating(true);

    std::cout << "Animation duration: " << animation.getDuration() << std::endl;

    while (isRunning_)
    {
        // update
        {
            SDLTimeController::update();
        }

        eventHandler->handleEvents();
        renderer->startRendering();

        tManager.getTexture(textureTM)->render(renderer.get(), 0, 0);

        //texture.render(renderer.get(), 0, 0);
        //rect.render(renderer.get(), 300, 0, 200, 200);
        //c.render(renderer.get(), 300, 300, 120);

        //animation.render(renderer.get(), Rectangle{0, 0, 32, 32}, {0, 0, 400, 400});

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
