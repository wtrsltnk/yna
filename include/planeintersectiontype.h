#ifndef PLANEINTERSECTIONTYPE_H
#define PLANEINTERSECTIONTYPE_H

namespace yna
{

namespace framework
{

enum class PlaneIntersectionType
{
    Back,           // There is no intersection, and the bounding volume is in the negative half-space of the Plane.
    Front,          // There is no intersection, and the bounding volume is in the positive half-space of the Plane.
    Intersecting,   // The Plane is intersected.
};

}

}

#endif // PLANEINTERSECTIONTYPE_H
