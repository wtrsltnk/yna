#ifndef VECTOR4_H
#define VECTOR4_H

#include "property.h"

namespace yna
{

namespace framework
{

struct Vector4
{
    Vector4();
    Vector4(float v);
    Vector4(float x, float y, float z, float w);

    // Gets or sets the x-component of the vector.
    float X;
    // Gets or sets the y-component of the vector.
    float Y;
    // Gets or sets the z-component of the vector.
    float Z;
    // Gets or sets the w-component of the vector.
    float W;

    // Returns a Vector4 with all of its components set to one.
    static getref_property<Vector4> One;
    // Returns the Vector4 (0, 0, 0, 1).
    static getref_property<Vector4> UnitW;
    // Returns the Vector4 (1, 0, 0, 0).
    static getref_property<Vector4> UnitX;
    // Returns the Vector4 (0, 1, 0, 0).
    static getref_property<Vector4> UnitY;
    // Returns the Vector4 (0, 0, 1, 0).
    static getref_property<Vector4> UnitZ;
    // Returns a Vector4 with all of its components set to zero.
    static getref_property<Vector4> Zero;
};

}

}

#endif // VECTOR4_H
