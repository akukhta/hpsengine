#include "CircleComponent.h"
#include <utility>
#include "../../IRenderer.h"
#include "../../GameObject/GameObject.h"

SDLCore::Primitives::CircleComponent::CircleComponent(Math::IVector2D relativePosition, int radius, SDL_Color color, bool filled)
    : RenderableComponent(relativePosition), r(radius), color(std::move(color)), filled(filled)
{
    if (!this->filled)
    {
        calculatePoints(relativePosition.x, relativePosition.y, radius);
    }
}

void SDLCore::Primitives::CircleComponent::render(SDLCore::IRenderer *renderer)
{
    auto parentPos = parent->getPosition();

    auto currX = parentPos.x + relativePosition.x;
    auto currY = parentPos.y + relativePosition.y;

    if (!filled &&  (currX != prevX || currY != prevY))
    {
        calculatePoints(currX, currY, r);
    }

    renderer->renderCircle(this, currX, currY, r);
}

void SDLCore::Primitives::CircleComponent::calculatePoints(int centerX, int centerY, int radius)
{
    points.clear();

    int x = radius;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y)
    {
        points.push_back({ centerX + x, centerY - y });
        points.push_back({ centerX + y, centerY - x });
        points.push_back({ centerX - x, centerY - y });
        points.push_back({ centerX - y, centerY - x });
        points.push_back({ centerX - x, centerY + y });
        points.push_back({ centerX - y, centerY + x });
        points.push_back({ centerX + x, centerY + y });
        points.push_back({ centerX + y, centerY + x });

        y++;

        if (radiusError <= 0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }

    prevRadius = radius;
    prevX = centerX;
    prevY = centerY;
}
