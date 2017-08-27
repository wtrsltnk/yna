#include "vector2.h"

using namespace yna::framework;

Vector2::Vector2()
    : X(0), Y(0)
{ }

Vector2::Vector2(float v)
    : X(v), Y(v)
{ }

Vector2::Vector2(float x, float y)
    : X(x), Y(y)
{ }

// Returns a Vector2 with all of its components set to one.
getref_property<Vector2> Vector2::One =
        getref_property<Vector2>([] () ->
                             const Vector2& {
                                 static Vector2 v(1.0f);
                                 return v;
                             });

// Returns the Vector2 (1, 0).
getref_property<Vector2> Vector2::UnitX =
        getref_property<Vector2>([] () -> Vector2& {
                                 static Vector2 v(1.0f, 0.0f);
                                 return v;
                             });

// Returns the Vector2 (0, 1).
getref_property<Vector2> Vector2::UnitY =
        getref_property<Vector2>([] () -> Vector2& {
                                 static Vector2 v(0.0f, 1.0f);
                                 return v;
                             });

// Returns a Vector2 with all of its components set to zero.
getref_property<Vector2> Vector2::Zero =
        getref_property<Vector2>([] () -> Vector2& {
                                 static Vector2 v(0.0f);
                                 return v;
                             });
