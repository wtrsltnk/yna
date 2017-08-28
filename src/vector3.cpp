#include "vector3.h"
#include <cassert>

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

float & Vector3::operator[](int i) { assert(i >= 0 && i < 3); return (&X)[i]; }
float Vector3::operator[](int i) const { assert(i >= 0 && i < 3); return (&X)[i]; }
bool Vector3::operator == (const Vector3& v) const { return this->X == v.X && this->Y == v.Y && this->Z == v.Z; }
bool Vector3::operator != (const Vector3& v) const { return this->X != v.X || this->Y != v.Y || this->Z != v.Z; }
Vector3& Vector3::operator  = (const Vector3& v) { this->X  = v.X; this->Y  = v.Y; this->Z  = v.Z; return *this; }
Vector3& Vector3::operator += (const Vector3& v) { this->X += v.X; this->Y += v.Y; this->Z += v.Z; return *this; }
Vector3& Vector3::operator -= (const Vector3& v) { this->X -= v.X; this->Y -= v.Y; this->Z -= v.Z; return *this; }
Vector3& Vector3::operator *= (const Vector3& v) { this->X *= v.X; this->Y *= v.Y; this->Z *= v.Z; return *this; }
Vector3& Vector3::operator /= (const Vector3& v) { this->X /= v.X; this->Y /= v.Y; this->Z /= v.Z; return *this; }
Vector3& Vector3::operator  = (float s) { this->X  = s; this->Y  = s; this->Z  = s; return *this; }
Vector3& Vector3::operator += (float s) { this->X += s; this->Y += s; this->Z += s; return *this; }
Vector3& Vector3::operator -= (float s) { this->X -= s; this->Y -= s; this->Z -= s; return *this; }
Vector3& Vector3::operator *= (float s) { this->X *= s; this->Y *= s; this->Z *= s; return *this; }
Vector3& Vector3::operator /= (float s) { this->X /= s; this->Y /= s; this->Z /= s; return *this; }
Vector3 Vector3::operator + (const Vector3& v) const { return Vector3({ this->X + v.X, this->Y + v.Y, this->Z + v.Z }); }
Vector3 Vector3::operator - (const Vector3& v) const { return Vector3({ this->X - v.X, this->Y - v.Y, this->Z - v.Z }); }
Vector3 Vector3::operator * (const Vector3& v) const { return Vector3({ this->X * v.X, this->Y * v.Y, this->Z * v.Z }); }
Vector3 Vector3::operator / (const Vector3& v) const { return Vector3({ this->X / v.X, this->Y / v.Y, this->Z / v.Z }); }
Vector3 Vector3::operator + (float const & s) const { return Vector3(this->X + s, this->Y + s, this->Z + s); }
Vector3 Vector3::operator - (float const & s) const { return Vector3(this->X - s, this->Y - s, this->Z - s); }
Vector3 Vector3::operator * (float const & s) const { return Vector3(this->X * s, this->Y * s, this->Z * s); }
Vector3 Vector3::operator / (float const & s) const { return Vector3(this->X / s, this->Y / s, this->Z / s); }

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

// Overloaded. Adds two vectors.
Vector3 Vector3::Add(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

// Overloaded. Returns a Vector3 containing the 2D Cartesian coordinates of a point specified in 2D barycentric (areal) coordinates.
Vector3 Vector3::Barycentric(const Vector3& a, const Vector3& b, const Vector3& c, float value1, float value2)
{
    return Vector3();
}

// Overloaded. Performs a Catmull-Rom interpolation using the specified positions.
Vector3 Vector3::CatmullRom(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d, float amount)
{
    return Vector3();
}

// Overloaded. Restricts a value to be within a specified range.
Vector3 Vector3::Clamp(const Vector3& value, const Vector3& min, const Vector3& max)
{
    return Vector3();
}

// Overloaded. Calculates the distance between two vectors.
float Vector3::Distance(const Vector3& a, const Vector3& b)
{
    return 0.0f;
}

// Overloaded. Calculates the distance between two vectors squared.
float Vector3::DistanceSquared(const Vector3& a, const Vector3& b)
{
    return 0.0f;
}

// Overloaded. Divides a vector by a scalar or another vector.
Vector3 Vector3::Divide(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

// Overloaded. Calculates the dot product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
float Vector3::Dot(const Vector3& a, const Vector3& b)
{
    return 0.0f;
}

// Overloaded. Performs a Hermite spline interpolation.
Vector3 Vector3::Hermite(const Vector3& value1, const Vector3& tangent1,
                                const Vector3& value2, const Vector3& tangent2, float amount)
{
    return Vector3();
}

// Calculates the length of the vector.
float Vector3::Length() const
{
    return 0.0f;
}

// Calculates the length of the vector squared.
float Vector3::LengthSquared() const
{
    return 0.0f;
}

// Overloaded. Performs a linear interpolation between two vectors.
Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float amount)
{
    return Vector3();
}

// Overloaded. Returns a vector that contains the highest value from each matching pair of components.
Vector3 Vector3::Max(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

// Overloaded. Returns a vector that contains the lowest value from each matching pair of components.
Vector3 Vector3::Min(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

// Overloaded. Multiplies a vector by a scalar or another vector.
Vector3 Vector3::Multiply(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

Vector3 Vector3::Multiply(const Vector3& a, float b)
{
    return Vector3();
}

// Overloaded. Returns a vector pointing in the opposite direction.
Vector3 Vector3::Negate(const Vector3& v)
{
    return Vector3();
}

// Overloaded. Creates a unit vector from the specified vector. The result is a vector one unit in length pointing in the same direction as the original vector.
Vector3 Vector3::Normalize() const
{
    return Vector3();
}

// Overloaded. Determines the reflect vector of the given vector and normal.
Vector3 Vector3::Reflect(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

// Overloaded. Interpolates between two values using a cubic equation.
Vector3 Vector3::SmoothStep(const Vector3& a, const Vector3& b, float amount)
{
    return Vector3();
}

// Overloaded. Subtracts a vector from a vector.
Vector3 Vector3::Subtract(const Vector3& a, const Vector3& b)
{
    return Vector3();
}

// Overloaded. Transforms one or more Vector3s by a Matrix or Quaternion.
Vector3 Vector3::Transform(const Vector3& v, const class Matrix& m)
{
    return Vector3();
}

Vector3 Vector3::Transform(const Vector3& v, const class Quaternion& q)
{
    return Vector3();
}

// Overloaded. Transforms a vector normal or array of vector normals by a matrix.
Vector3 Vector3::TransformNormal(const Vector3& v, const class Matrix& m)
{
    return Vector3();
}

Vector3 Vector3::TransformNormal(const Vector3& v, const class Quaternion& q)
{
    return Vector3();
}
