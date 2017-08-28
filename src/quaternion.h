#ifndef QUATERNION_H
#define QUATERNION_H

#include "property.h"

namespace yna
{

namespace framework
{

struct Quaternion
{
    Quaternion();
    Quaternion(float v);
    Quaternion(float x, float y, float z, float w);

    // Gets or sets the x-component of the vector.
    float X;
    // Gets or sets the y-component of the vector.
    float Y;
    // Gets or sets the z-component of the vector.
    float Z;
    // Gets or sets the w-component of the vector.
    float W;

    // Returns a Quaternion representing no rotation.
    static getref_property<Quaternion> Identity;
};

}

}

#endif // QUATERNION_H
