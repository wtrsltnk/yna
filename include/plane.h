#ifndef PLANE_H
#define PLANE_H

#include "vector3.h"
#include "vector4.h"

namespace yna
{

    namespace framework
    {

        struct Plane
        {
            Plane();
            Plane(float x, float y, float z, float d);
            Plane(const Vector3 &normal, float d);
            Plane(const Vector3 &a, const Vector3 &b, const Vector3 &c);
            Plane(const Vector4 &v);

            float D;
            Vector3 Normal;
        };

    } // namespace framework

} // namespace yna

#endif // PLANE_H
