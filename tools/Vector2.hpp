#pragma once

#include <iostream>

class Vector2
{
public:
    int x, y;

    Vector2(int x, int y);
    Vector2();

    Vector2& add(const Vector2& vec);
    Vector2& sub(const Vector2& vec);
    Vector2& mult(const Vector2& vec);
    Vector2& div(const Vector2& vec);

    Vector2 operator + (const Vector2& vec);   
    Vector2 operator - (const Vector2 &vec);
    Vector2 operator * (const Vector2 &vec);
    Vector2 operator / (const Vector2 &vec);



    friend std::ostream& operator << (std::ostream& stream, const Vector2 &v)
    {
        return stream << v.x << ' ' << v.y;
    }
};