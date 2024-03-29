#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include "containmenttype.h"
#include "planeintersectiontype.h"
#include "vector3.h"

#include <vector>

namespace yna
{

    namespace framework
    {

        struct BoundingSphere
        {
            BoundingSphere();
            BoundingSphere(const Vector3 &center, float radius);

            // The center point of the sphere.
            Vector3 Center;
            // The radius of the sphere.
            float Radius;

            // Checks whether the current BoundingFrustum contains the specified BoundingBox.
            ContainmentType Contains(const class BoundingBox &bb) const;
            // Checks whether the current BoundingFrustum contains the specified BoundingFrustum.
            ContainmentType Contains(const class BoundingFrustum &bf) const;
            // Checks whether the current BoundingFrustum contains the specified BoundingSphere.
            ContainmentType Contains(const BoundingSphere &bs) const;
            // Checks whether the current BoundingFrustum contains the specified point.
            ContainmentType Contains(const Vector3 &v) const;

            // Checks whether the current BoundingBox intersects another bool
            bool Intersects(const class BoundingBox &bb) const;
            // Checks whether the current BoundingBox intersects a BoundingFrustum.
            bool Intersects(const class BoundingFrustum &bf) const;
            // Checks whether the current BoundingBox intersects a BoundingSphere.
            bool Intersects(const BoundingSphere &bs) const;
            // Checks whether the current BoundingBox intersects a Plane.
            PlaneIntersectionType Intersects(const class Plane &plane) const;
            // Checks whether the current BoundingBox intersects a Ray.
            std::vector<float> Intersects(const class Ray &ray) const;
        };

    } // namespace framework

} // namespace yna

#endif // BOUNDINGSPHERE_H
