#include "SDLGame.h"
#include "SDLAnimatedSpriteSheet.h"
#include "SDLTexture.h"
#include "../primitives/Colors.h"
#include "SDLTimeController.h"
#include <iostream>
#include "Texture/LoadPNG.h"
#include "Texture/TextureManager.h"
#include "Actors/TestActor.h"
#include "Input/SDLKeyboard.h"
#include "Input/SDLMouse.h"

SDLCore::SDLGame::SDLGame(RendererPtr renderer, EventHandlerPtr eventHandler)
    : renderer(std::move(renderer)), eventHandler(std::move(eventHandler)), scene(std::make_unique<Scene>()), textureManager(std::make_unique<TextureManager>(std::make_unique<TextureLoadStrategyFactory>()))
{
    this->eventHandler->addEventHandler(SDLEventHandler::EventType::QUIT, [this]{onGameQuit();});
}

void SDLCore::SDLGame::init()
{
    auto textureTM = textureManager->loadTexture<LoadPNG>("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    auto actorID = scene->addObject(new TestActor(renderer.get(), textureManager.get(), textureTM));
    auto actorCopy = dynamic_cast<TestActor*>(scene->getObject(actorID)->clone());

    scene->removeObject(actorID);

    //scene->getObject(actorID)->setVisibility(true);

    actorCopy->setPosition({50,  100});

    scene->addObject(actorCopy);

    try
    {
        auto& keyboard = dynamic_cast<SDLKeyboard&>(eventHandler->getInputManager()->getKeyboard());

        keyboard.addKeyDownCallback(SDLK_f, [&actorCopy](){actorCopy->someAction();});
        keyboard.addKeyUpCallback(SDLK_f, [&actorCopy](){actorCopy->finishSomeAction();});
        keyboard.addAxis(SDLK_a, SDLK_d, [&actorCopy](int dir){actorCopy->move(dir);});

        auto& mouse = dynamic_cast<SDLMouse&>(eventHandler->getInputManager()->getMouse());
        mouse.addButtonPressCallback(SDL_BUTTON_LEFT, [](){std::cout << "LMBTN" << std::endl;});
        mouse.addButtonPressCallback(SDL_BUTTON_RIGHT, [](){std::cout << "RMBTN" << std::endl;});
        mouse.addMouseMoveCallback([](int x, int y) {std::cout << x << "," << y << std::endl;});
    }
    catch (std::bad_cast &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void SDLCore::SDLGame::run()
{
    isRunning_ = true;

    auto texture = SDLTexture::loadPNG("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    TextureManager tManager(std::make_unique<TextureLoadStrategyFactory>());
    //auto textureTM = tManager.loadTexture<LoadPNG>("/Users/khk/Downloads/5b92b51b196573108b203ad1.png", renderer.get());

    //auto animatedTextureID = tManager.loadTexture<LoadPNG>("/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png", renderer.get());
    //SDLAnimatedSpriteSheet animation{&tManager, animatedTextureID, {96, 96}, 1, 7};
    //animation.setDuration(1);
    // auto animation = SDLAnimatedSpriteSheet::loadPNG(renderer.get(), "/Users/khk/Downloads/FREE_Samurai 2D Pixel Art v1.2/Sprites/attack.png",
    //     std::make_pair(96, 96), 0.2, 7);

    //Primitives::RectangleComponent rect{{0, 0100, 100}, Primitives::Colors::Red, true};
    //::Primitives::Circle c{300, 300, 120, ::Primitives::Colors::Gray, true};

    // animation.setDuration(1);
    // animation.setIsRepeating(true);
    //
    // std::cout << "Animation duration: " << animation.getDuration() << std::endl;

    std::uint32_t frameStart;
    std::uint32_t frameTime;

    while (isRunning_)
    {
        // update
        frameStart = SDLTimeController::getTicks();
        eventHandler->handleEvents();
        update();

        renderer->startRendering();
        render();
        renderer->finishRendering();
        frameTime = SDLTimeController::getTicks() - frameStart;

        if (fpsLockEnabled && frameTime < delayTime)
        {
            delayGame(delayTime - frameTime);
        }
    }
}

bool SDLCore::SDLGame::isRunning() const
{
    return isRunning_;
}

void SDLCore::SDLGame::setFPSLock(int fps)
{
    fpsLockEnabled = true;
    this->fps = fps;
    delayTime = 1000.0 / fps;
}

void SDLCore::SDLGame::unlockFPS()
{
    fpsLockEnabled = false;
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

void SDLCore::SDLGame::delayGame(std::uint32_t ticks)
{
    SDL_Delay(ticks);
}
