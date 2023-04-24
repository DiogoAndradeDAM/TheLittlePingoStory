#include "Vector2.hpp"

Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(int x, int y)
: x(x), y(y)
{
}

Vector2& Vector2::add(const Vector2& vec)
{
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}

Vector2& Vector2::sub(const Vector2& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
}

Vector2& Vector2::mult(const Vector2& vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    return *this;
}

Vector2& Vector2::div(const Vector2& vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& vec)
{
    return this->add(vec);
}

Vector2 Vector2::operator-(const Vector2& vec)
{
    return this->sub(vec);
}

Vector2 Vector2::operator*(const Vector2& vec)
{
    return this->mult(vec);
}

Vector2 Vector2::operator/(const Vector2& vec)
{
    return this->div(vec);
}

