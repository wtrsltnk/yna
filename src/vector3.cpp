#include "vector3.h"

using namespace yna::framework;

Vector3::Vector3()
    : X(0), Y(0), Z(0)
{ }

Vector3::Vector3(float v)
    : X(v), Y(v), Z(v)
{ }

Vector3::Vector3(float x, float y, float z)
    : X(x), Y(y), Z(z)
{ }

// Returns a unit Vector3 designating backward in a right-handed coordinate system (0, 0, 1).
getref_property<Vector3> Vector3::Backward =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(1.0f, 0.0f, 1.0f);
                                 return v;
                             });

// Returns a unit Vector3 designating down (0, −1, 0).
getref_property<Vector3> Vector3::Down =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(1.0f, -1.0f, 0.0f);
                                 return v;
                             });

// Returns a unit Vector3 designating forward in a right-handed coordinate system(0, 0, −1).
getref_property<Vector3> Vector3::Forward =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(0.0f, 0.0f, -1.0f);
                                 return v;
                             });

// Returns a unit Vector3 designating left (−1, 0, 0).
getref_property<Vector3> Vector3::Left =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(-1.0f, 0.0f, 0.0f);
                                 return v;
                             });

// Returns a unit Vector3 pointing to the right (1, 0, 0).
getref_property<Vector3> Vector3::Right =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(1.0f, 0.0f, 0.0f);
                                 return v;
                             });

// Returns a unit vector designating up (0, 1, 0).
getref_property<Vector3> Vector3::Up =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(0.0f, 1.0f, 0.0f);
                                 return v;
                             });

// Returns a Vector3 with all of its components set to one.
getref_property<Vector3> Vector3::One =
        getref_property<Vector3>([] () ->
                             const Vector3& {
                                 static Vector3 v(1.0f);
                                 return v;
                             });

// Returns the Vector3 (1, 0, 0).
getref_property<Vector3> Vector3::UnitX =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(1.0f, 0.0f, 0.0f);
                                 return v;
                             });

// Returns the Vector3 (0, 1, 0).
getref_property<Vector3> Vector3::UnitY =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(0.0f, 1.0f, 0.0f);
                                 return v;
                             });

// Returns the Vector3 (0, 0, 1).
getref_property<Vector3> Vector3::UnitZ =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(0.0f, 0.0f, 1.0f);
                                 return v;
                             });

// Returns a Vector3 with all of its components set to zero.
getref_property<Vector3> Vector3::Zero =
        getref_property<Vector3>([] () -> Vector3& {
                                 static Vector3 v(0.0f);
                                 return v;
                             });
