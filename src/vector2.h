#ifndef VECTOR2_H
#define VECTOR2_H

#include "property.h"

namespace yna
{

namespace framework
{

class Vector2
{
public:
    Vector2();
    Vector2(float v);
    Vector2(float x, float y);
    virtual ~Vector2();

    // Gets or sets the x-component of the vector.
    float X;
    // Gets or sets the y-component of the vector.
    float Y;

    // Returns a Vector2 with all of its components set to one.
    static getref_property<Vector2> One;
    // Returns the Vector2 (1, 0).
    static getref_property<Vector2> UnitX;
    // Returns the Vector2 (0, 1).
    static getref_property<Vector2> UnitY;
    // Returns a Vector2 with all of its components set to zero.
    static getref_property<Vector2> Zero;
};

}

}

#endif // VECTOR2_H
