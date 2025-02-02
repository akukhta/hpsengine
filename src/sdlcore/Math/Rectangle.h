#pragma once
#include <limits>

#include "Vector2D.h"

namespace SDLCore::Math
{
    struct Rectangle
    {
        int x;
        int y;
        int width;
        int height;

        static constexpr Rectangle createDefaultBoundingBox()
        {
            return Rectangle
            {
                    std::numeric_limits<int>::max(),
                    std::numeric_limits<int>::max(),
                 std::numeric_limits<int>::min(),
                std::numeric_limits<int>::min(),
            };
        }

        static bool intersect(const Rectangle& a, const Rectangle& b)
        {
            return a.x < b.x + b.width && a.x + a.width > b.x
                && a.y < b.y + b.height && a.y + a.height > b.y;
        }

        static bool intersect(const IVector2D &point, const Rectangle &rect)
        {
            return point.x >= rect.x && point.x <= rect.x + rect.width
                && point.y >= rect.y && point.y <= rect.y + rect.height;
        }
    };

}
