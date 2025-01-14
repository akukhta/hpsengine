#pragma once
#include <stdexcept>
#include <cmath>

namespace SDLCore::Math
{
    template <typename T>
    class Vector2D
    {
    public:
        T x;
        T y;

        double length() const noexcept
        {
            return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
        }

        Vector2D& operator*(T mul) noexcept
        {
            x *= mul;
            y *= mul;

            return *this;
        }

        Vector2D getDirectionVector() const noexcept
        {
            auto len = length();
            return Vector2D{ x / len, y / len };
        }

        Vector2D project(Vector2D const& B) const noexcept
        {
            auto lenB = B.length();

            if (lenB == 0)
            {
                throw std::invalid_argument("Can't project zero length vector");
            }

            return ((*this * B) / std::pow(lenB, 2)) * B;
        }

        friend T operator*(Vector2D const& A, Vector2D const& B) noexcept
        {
            return A.x * B.x + A.y * B.y;
        }

        friend Vector2D operator+(Vector2D const& a, Vector2D const& b) noexcept
        {
            return Vector2D{a.x + b.x, a.y + b.y};
        }

        friend Vector2D operator-(Vector2D const& a, Vector2D const& b) noexcept
        {
            return Vector2D{a.x - b.x, a.y - b.y};
        }
    };

    using IVector2D = Vector2D<int>;
    using FVector2D = Vector2D<float>;
}