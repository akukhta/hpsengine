#include "GameObject.h"

void SDLCore::GameObject::render(IRenderer *renderer)
{
    for (auto& renderable : renderableComponents)
    {
        renderable->render(renderer);
    }
}

void SDLCore::GameObject::update(double deltaTime)
{
    for (auto& updatable : updatableComponents)
    {
        updatable->update(deltaTime);
    }
}

void SDLCore::GameObject::setPosition(Math::IVector2D position)
{
    this->position = position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getWorldLocation() const
{
    return position;
}

SDLCore::Math::IVector2D SDLCore::GameObject::getRelativeLocation() const
{
    return {0, 0};
}

std::pair<int, int> SDLCore::GameObject::getRenderableSize() const
{
    std::pair<int, int> renderableSize = {std::numeric_limits<int>::min(),
        std::numeric_limits<int>::min()};

    for (auto &renderable : renderableComponents)
    {
        auto componentSize = renderable->getRenderableSize();

        renderableSize.first = std::max(renderableSize.first, componentSize.first);
        renderableSize.second = std::max(renderableSize.second, componentSize.second);
    }

    return renderableSize;
}
