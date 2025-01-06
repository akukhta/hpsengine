#include "Circle.h"
#include <utility>
#include "../sdlcore/IRenderer.h"

Primitives::Circle::Circle(int x, int y, int radius, SDL_Color color, bool filled)
    : color(std::move(color)), filled(filled)
{
    if (!this->filled)
    {
        calculatePoints(x, y, radius);
    }
}

void Primitives::Circle::render(SDLCore::IRenderer *renderer, int x, int y)
{
    std::unreachable();
}

void Primitives::Circle::render(SDLCore::IRenderer *renderer, int x, int y, int w, int h)
{
    std::unreachable();
}

void Primitives::Circle::render(SDLCore::IRenderer *renderer, int x, int y, int r)
{
    if (!filled &&  (x != prevX || y != prevY || r != prevRadius))
    {
        calculatePoints(x, y, r);
    }

    renderer->renderCircle(this, x, y, r);
}

void Primitives::Circle::calculatePoints(int centerX, int centerY, int radius)
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
