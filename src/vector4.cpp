#include "vector4.h"

using namespace yna::framework;

Vector4::Vector4()
    : X(0), Y(0), Z(0), W(0)
{ }

Vector4::Vector4(float v)
    : X(v), Y(v), Z(v), W(v)
{ }

Vector4::Vector4(float x, float y, float z, float w)
    : X(x), Y(y), Z(z), W(w)
{ }

// Returns a Vector4 with all of its components set to one.
getref_property<Vector4> Vector4::One =
        getref_property<Vector4>([] () ->
                             const Vector4& {
                                 static Vector4 v(1.0f);
                                 return v;
                             });

// Returns the Vector4 (0, 0, 0, 1).
getref_property<Vector4> Vector4::UnitW =
        getref_property<Vector4>([] () -> Vector4& {
                                 static Vector4 v(0.0f, 0.0f, 0.0f, 1.0f);
                                 return v;
                             });

// Returns the Vector4 (1, 0, 0, 0).
getref_property<Vector4> Vector4::UnitX =
        getref_property<Vector4>([] () -> Vector4& {
                                 static Vector4 v(1.0f, 0.0f, 0.0f, 0.0f);
                                 return v;
                             });

// Returns the Vector4 (0, 1, 0, 0).
getref_property<Vector4> Vector4::UnitY =
        getref_property<Vector4>([] () -> Vector4& {
                                 static Vector4 v(0.0f, 1.0f, 0.0f, 0.0f);
                                 return v;
                             });

// Returns the Vector4 (0, 0, 1, 0).
getref_property<Vector4> Vector4::UnitZ =
        getref_property<Vector4>([] () -> Vector4& {
                                 static Vector4 v(0.0f, 0.0f, 1.0f, 0.0f);
                                 return v;
                             });

// Returns the Vector4 (0, 0, 1, 0).
getref_property<Vector4> Vector4::Zero =
        getref_property<Vector4>([] () -> Vector4& {
                                 static Vector4 v(0.0f);
                                 return v;
                             });
