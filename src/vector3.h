#ifndef VECTOR3_H
#define VECTOR3_H

#include "property.h"

namespace yna
{

namespace framework
{

class Vector3
{
public:
    Vector3();
    Vector3(float v);
    Vector3(float x, float y, float z);
    virtual ~Vector3();

    // Gets or sets the x-component of the vector.
    float X;
    // Gets or sets the y-component of the vector.
    float Y;
    // Gets or sets the z-component of the vector.
    float Z;

    // Returns a unit Vector3 designating backward in a right-handed coordinate system (0, 0, 1).
    static getref_property<Vector3> Backward;
    // Returns a unit Vector3 designating down (0, −1, 0).
    static getref_property<Vector3> Down;
    // Returns a unit Vector3 designating forward in a right-handed coordinate system(0, 0, −1).
    static getref_property<Vector3> Forward;
    // Returns a unit Vector3 designating left (−1, 0, 0).
    static getref_property<Vector3> Left;
    // Returns a unit Vector3 pointing to the right (1, 0, 0).
    static getref_property<Vector3> Right;
    // Returns a unit vector designating up (0, 1, 0).
    static getref_property<Vector3> Up;

    // Returns a Vector3 with all of its components set to one.
    static getref_property<Vector3> One;
    // Returns the Vector3 (1, 0, 0).
    static getref_property<Vector3> UnitX;
    // Returns the Vector3 (0, 1, 0).
    static getref_property<Vector3> UnitY;
    // Returns the Vector3 (0, 0, 1).
    static getref_property<Vector3> UnitZ;
    // Returns a Vector3 with all of its components set to zero.
    static getref_property<Vector3> Zero;
};

}

}

#endif // VECTOR3_H
