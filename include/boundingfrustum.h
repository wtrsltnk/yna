#ifndef BOUNDINGFRUSTUM_H
#define BOUNDINGFRUSTUM_H

#include "containmenttype.h"
#include "matrix.h"
#include "plane.h"
#include "planeintersectiontype.h"
#include "vector3.h"

#include <vector>

namespace yna
{

    namespace framework
    {

        class BoundingFrustum
        {
        public:
            BoundingFrustum();
            BoundingFrustum(const Matrix &value);
            virtual ~BoundingFrustum();

            // Gets the bottom plane of the BoundingFrustum.
            Plane Bottom;
            // Gets the far plane of the BoundingFrustum.
            Plane Far;
            // Gets the left plane of the BoundingFrustum.
            Plane Left;
            // Gets or sets the Matrix that describes this bounding frustum.
            Matrix FrustumMatrix;
            // Gets the near plane of the BoundingFrustum.
            Plane Near;
            // Gets the right plane of the BoundingFrustum.
            Plane Right;
            // Gets the top plane of the BoundingFrustum.
            Plane Top;

            // Checks whether the current BoundingFrustum contains the specified BoundingBox.
            ContainmentType Contains(const class BoundingBox &bb) const;
            // Checks whether the current BoundingFrustum contains the specified BoundingFrustum.
            ContainmentType Contains(const BoundingFrustum &bf) const;
            // Checks whether the current BoundingFrustum contains the specified BoundingSphere.
            ContainmentType Contains(const class BoundingSphere &bs) const;
            // Checks whether the current BoundingFrustum contains the specified point.
            ContainmentType Contains(const Vector3 &v) const;

            // Checks whether the current BoundingBox intersects another bool
            bool Intersects(const class BoundingBox &bb) const;
            // Checks whether the current BoundingBox intersects a BoundingFrustum.
            bool Intersects(const BoundingFrustum &bf) const;
            // Checks whether the current BoundingBox intersects a BoundingSphere.
            bool Intersects(const class BoundingSphere &bs) const;
            // Checks whether the current BoundingBox intersects a Plane.
            PlaneIntersectionType Intersects(const Plane &plane) const;
            // Checks whether the current BoundingBox intersects a Ray.
            std::vector<float> Intersects(const class Ray &ray) const;
        };

    } // namespace framework

} // namespace yna

#endif // BOUNDINGFRUSTUM_H
