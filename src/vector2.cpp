#include "vector2.h"
#include <cassert>

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

float & Vector2::operator[](int i) { assert(i >= 0 && i < 2); return (&X)[i]; }
float Vector2::operator[](int i) const { assert(i >= 0 && i < 2); return (&X)[i]; }
Vector2& Vector2::operator  = (const Vector2& v) { this->X  = v.X; this->Y  = v.Y; return *this; }
Vector2& Vector2::operator += (const Vector2& v) { this->X += v.X; this->Y += v.Y; return *this; }
Vector2& Vector2::operator -= (const Vector2& v) { this->X -= v.X; this->Y -= v.Y; return *this; }
Vector2& Vector2::operator *= (const Vector2& v) { this->X *= v.X; this->Y *= v.Y; return *this; }
Vector2& Vector2::operator /= (const Vector2& v) { this->X /= v.X; this->Y /= v.Y; return *this; }
Vector2& Vector2::operator  = (float s) { this->X  = s; this->Y  = s; return *this; }
Vector2& Vector2::operator += (float s) { this->X += s; this->Y += s; return *this; }
Vector2& Vector2::operator -= (float s) { this->X -= s; this->Y -= s; return *this; }
Vector2& Vector2::operator *= (float s) { this->X *= s; this->Y *= s; return *this; }
Vector2& Vector2::operator /= (float s) { this->X /= s; this->Y /= s; return *this; }
bool Vector2::operator == (const Vector2& v) const { return this->X == v.X && this->Y == v.Y; }
bool Vector2::operator != (const Vector2& v) const { return this->X != v.X || this->Y != v.Y; }
Vector2 Vector2::operator + (float const & s) const { return Vector2(this->X + s, this->Y + s); }
Vector2 Vector2::operator - (float const & s) const { return Vector2(this->X - s, this->Y - s); }
Vector2 Vector2::operator * (float const & s) const { return Vector2(this->X * s, this->Y * s); }
Vector2 Vector2::operator / (float const & s) const { return Vector2(this->X / s, this->Y / s); }
Vector2 Vector2::operator + (const Vector2& v) const { return Vector2({ this->X + v.X, this->Y + v.Y }); }
Vector2 Vector2::operator - (const Vector2& v) const { return Vector2({ this->X - v.X, this->Y - v.Y }); }
Vector2 Vector2::operator * (const Vector2& v) const { return Vector2({ this->X * v.X, this->Y * v.Y }); }
Vector2 Vector2::operator / (const Vector2& v) const { return Vector2({ this->X / v.X, this->Y / v.Y }); }

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

// Overloaded. Adds two vectors.
Vector2 Vector2::Add(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

// Overloaded. Returns a Vector2 containing the 2D Cartesian coordinates of a point specified in 2D barycentric (areal) coordinates.
Vector2 Vector2::Barycentric(const Vector2& a, const Vector2& b, const Vector2& c, float value1, float value2)
{
    return Vector2();
}

// Overloaded. Performs a Catmull-Rom interpolation using the specified positions.
Vector2 Vector2::CatmullRom(const Vector2& a, const Vector2& b, const Vector2& c, const Vector2& d, float amount)
{
    return Vector2();
}

// Overloaded. Restricts a value to be within a specified range.
Vector2 Vector2::Clamp(const Vector2& value, const Vector2& min, const Vector2& max)
{
    return Vector2();
}

// Overloaded. Calculates the distance between two vectors.
float Vector2::Distance(const Vector2& a, const Vector2& b)
{
    return 0.0f;
}

// Overloaded. Calculates the distance between two vectors squared.
float Vector2::DistanceSquared(const Vector2& a, const Vector2& b)
{
    return 0.0f;
}

// Overloaded. Divides a vector by a scalar or another vector.
Vector2 Vector2::Divide(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

// Overloaded. Calculates the dot product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
float Vector2::Dot(const Vector2& a, const Vector2& b)
{
    return 0.0f;
}

// Overloaded. Performs a Hermite spline interpolation.
Vector2 Vector2::Hermite(const Vector2& value1, const Vector2& tangent1,
                                const Vector2& value2, const Vector2& tangent2, float amount)
{
    return Vector2();
}

// Calculates the length of the vector.
float Vector2::Length() const
{
    return 0.0f;
}

// Calculates the length of the vector squared.
float Vector2::LengthSquared() const
{
    return 0.0f;
}

// Overloaded. Performs a linear interpolation between two vectors.
Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float amount)
{
    return Vector2();
}

// Overloaded. Returns a vector that contains the highest value from each matching pair of components.
Vector2 Vector2::Max(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

// Overloaded. Returns a vector that contains the lowest value from each matching pair of components.
Vector2 Vector2::Min(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

// Overloaded. Multiplies a vector by a scalar or another vector.
Vector2 Vector2::Multiply(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

Vector2 Vector2::Multiply(const Vector2& a, float b)
{
    return Vector2();
}

// Overloaded. Returns a vector pointing in the opposite direction.
Vector2 Vector2::Negate(const Vector2& v)
{
    return Vector2();
}

// Overloaded. Creates a unit vector from the specified vector. The result is a vector one unit in length pointing in the same direction as the original vector.
Vector2 Vector2::Normalize() const
{
    return Vector2();
}

// Overloaded. Determines the reflect vector of the given vector and normal.
Vector2 Vector2::Reflect(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

// Overloaded. Interpolates between two values using a cubic equation.
Vector2 Vector2::SmoothStep(const Vector2& a, const Vector2& b, float amount)
{
    return Vector2();
}

// Overloaded. Subtracts a vector from a vector.
Vector2 Vector2::Subtract(const Vector2& a, const Vector2& b)
{
    return Vector2();
}

// Overloaded. Transforms one or more Vector2s by a Matrix or Quaternion.
Vector2 Vector2::Transform(const Vector2& v, const class Matrix& m)
{
    return Vector2();
}

Vector2 Vector2::Transform(const Vector2& v, const class Quaternion& q)
{
    return Vector2();
}

// Overloaded. Transforms a vector normal or array of vector normals by a matrix.
Vector2 Vector2::TransformNormal(const Vector2& v, const class Matrix& m)
{
    return Vector2();
}

Vector2 Vector2::TransformNormal(const Vector2& v, const class Quaternion& q)
{
    return Vector2();
}
