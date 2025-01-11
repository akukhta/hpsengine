#pragma once

namespace SDLCore
{
    /// The core of the SDL engine\n
    /// Responsible for the main game loop:
    /// 1. Get events
    /// 2. Update
    /// 3. Render
    template <class InputManager, class Renderer, class Gameplay>
    class SDLEngine
    {
    public:
        SDLEngine(InputManager& input_manager, Renderer& renderer, Gameplay& gameplay)
        : input_manager_(input_manager), renderer_(renderer),
        gameplay_(gameplay) {}

        void run()
        {
            while (isRunning_)
            {
                input_manager_.handleEvents();
                gameplay_.update();
                renderer_.render();
            }
        }
        bool isRunning() const
        {
            return isRunning_;
        }

    private:
        bool isRunning_ = true;

        InputManager& input_manager_;
        Renderer& renderer_;
        Gameplay& gameplay_;
    };
}
