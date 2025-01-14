#include "SDLGame.h"
#include "SDLAnimatedSpriteSheet.h"
#include "SDLTexture.h"
#include "../primitives/Colors.h"
#include "SDLTimeController.h"
#include <iostream>
#include "Texture/LoadPNG.h"
#include "Texture/TextureManager.h"
#include "Actors/TestActor.h"

SDLCore::SDLGame::SDLGame(RendererPtr renderer, EventHandlerPtr eventHandler)
    : renderer(std::move(renderer)), eventHandler(std::move(eventHandler)), scene(std::make_unique<Scene>()), textureManager(std::make_unique<TextureManager>(std::make_unique<TextureLoadStrategyFactory>()))
{
    this->eventHandler->addEventHandler(SDLCore::SDLEventHandler::EventType::QUIT, [this](){onGameQuit();});
}

void SDLCore::SDLGame::init()
{
    auto textureTM = textureManager->loadTexture<LoadPNG>("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    scene->addObject(new TestActor(textureManager.get(), textureTM));
}

void SDLCore::SDLGame::run()
{
    isRunning_ = true;

    auto texture = SDLTexture::loadPNG("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    TextureManager tManager(std::make_unique<TextureLoadStrategyFactory>());
    auto textureTM = tManager.loadTexture<LoadPNG>("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    auto animatedTextureID = tManager.loadTexture<LoadPNG>("/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png", renderer.get());
    SDLAnimatedSpriteSheet animation{&tManager, animatedTextureID, {96, 96}, 1, 7};
    //animation.setDuration(1);
    // auto animation = SDLAnimatedSpriteSheet::loadPNG(renderer.get(), "/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png",
    //     std::make_pair(96, 96), 0.2, 7);

    //Primitives::RectangleComponent rect{{0, 0100, 100}, Primitives::Colors::Red, true};
    ::Primitives::Circle c{300, 300, 120, ::Primitives::Colors::Gray, true};

    // animation.setDuration(1);
    // animation.setIsRepeating(true);
    //
    // std::cout << "Animation duration: " << animation.getDuration() << std::endl;

    while (isRunning_)
    {
        // update

        eventHandler->handleEvents();
        renderer->startRendering();

        render();
        //tManager.getTexture(textureTM)->render(renderer.get(), 0, 0);

        //texture.render(renderer.get(), 0, 0);
        //rect.render(renderer.get(), 300, 0, 200, 200);
        //c.render(renderer.get(), 300, 300, 120);

        //animation.render(renderer.get(), Math::Rectangle{0, 0, 32, 32}, {0, 0, 640, 480});

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

void SDLCore::SDLGame::update()
{
    SDLTimeController::update();
    auto deltaTime = SDLTimeController::getDeltaTime();

    for (auto const &updatableObject : scene->sceneObjects)
    {
        updatableObject.second->update(deltaTime);
    }
}

void SDLCore::SDLGame::handleEvents()
{
    // ...
}

void SDLCore::SDLGame::render()
{
    for (auto const& renderableObject : scene->sceneObjects)
    {
        renderableObject.second->render(renderer.get());
    }
}
