#pragma once
#include <limits>

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
    };

}