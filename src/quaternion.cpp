#include "quaternion.h"

using namespace yna::framework;

Quaternion::Quaternion()
    : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f)
{ }

Quaternion::Quaternion(float v)
    : X(v), Y(v), Z(v), W(v)
{ }

Quaternion::Quaternion(float x, float y, float z, float w)
    : X(x), Y(y), Z(z), W(w)
{ }

// Returns a Quaternion representing no rotation.
getref_property<Quaternion> Quaternion::Identity =
        getref_property<Quaternion>([] () ->
                             const Quaternion& {
                                 static Quaternion q(0.0f, 0.0f, 0.0f, 1.0f);
                                 return q;
                             });
