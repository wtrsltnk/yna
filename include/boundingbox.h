#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "containmenttype.h"
#include "planeintersectiontype.h"
#include "property.h"
#include "vector3.h"

#include <vector>

namespace yna
{

    namespace framework
    {

        struct BoundingBox
        {
            BoundingBox();
            BoundingBox(const Vector3 &min, const Vector3 &max);

            // The maximum point the BoundingBox contains.
            Vector3 Max;
            // The minimum point the BoundingBox contains.
            Vector3 Min;

            // Tests whether the BoundingBox contains another BoundingBox.
            ContainmentType Contains(const BoundingBox &bb) const;
            // Tests whether the BoundingBox contains a BoundingFrustum.
            ContainmentType Contains(const class BoundingFrustum &bf) const;
            // Tests whether the BoundingBox contains a BoundingSphere.
            ContainmentType Contains(const class BoundingSphere &bs) const;
            // Tests whether the BoundingBox contains a point.
            ContainmentType Contains(const Vector3 &v) const;

            // Checks whether the current BoundingBox intersects another bool
            bool Intersects(const BoundingBox &bb) const;
            // Checks whether the current BoundingBox intersects a BoundingFrustum.
            bool Intersects(const class BoundingFrustum &bf) const;
            // Checks whether the current BoundingBox intersects a BoundingSphere.
            bool Intersects(const class BoundingSphere &bs) const;
            // Checks whether the current BoundingBox intersects a Plane.
            PlaneIntersectionType Intersects(const class Plane &plane) const;
            // Checks whether the current BoundingBox intersects a Ray.
            std::vector<float> Intersects(const class Ray &ray) const;

            // Creates the smallest BoundingBox that will contain a group of points.
            static BoundingBox CreateFromPoints(const std::vector<Vector3> &points);
            // Creates the smallest BoundingBox that contains the two specified BoundingBox instances.
            static BoundingBox CreateMerged(const BoundingBox &a, BoundingBox &b);
        };

    } // namespace framework

} // namespace yna

#endif // BOUNDINGBOX_H
