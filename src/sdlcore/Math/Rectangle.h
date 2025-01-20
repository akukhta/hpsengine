#pragma once

namespace SDLCore::Math
{
    struct Rectangle
    {
        int x;
        int y;
        int width;
        int height;

        static constexpr Rectangle createMin()
        {
            return Rectangle
            {
                    std::numeric_limits<int>::min(),
                    std::numeric_limits<int>::min(),
                 std::numeric_limits<int>::min(),
                std::numeric_limits<int>::min(),
            };
        }
    };

}