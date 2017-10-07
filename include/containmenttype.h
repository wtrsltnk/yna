#ifndef CONTAINMENTTYPE_H
#define CONTAINMENTTYPE_H

namespace yna
{

namespace framework
{

enum class ContainmentType
{
    Contains,       // Indicates that one bounding volume completely contains the other.
    Disjoint,       // Indicates there is no overlap between the bounding volumes.
    Intersects,     // Indicates that the bounding volumes partially overlap.
};

}

}

#endif // CONTAINMENTTYPE_H
