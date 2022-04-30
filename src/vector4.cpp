#include "vector4.h"
#include <cassert>

using namespace yna::framework;

Vector4::Vector4()
    : X(0), Y(0), Z(0), W(0)
{}

Vector4::Vector4(float v)
    : X(v), Y(v), Z(v), W(v)
{}

Vector4::Vector4(float x, float y, float z, float w)
    : X(x), Y(y), Z(z), W(w)
{}

float &Vector4::operator[](int i)
{
    assert(i >= 0 && i < 4);
    return (&X)[i];
}
float Vector4::operator[](int i) const
{
    assert(i >= 0 && i < 4);
    return (&X)[i];
}
bool Vector4::operator==(const Vector4 &v) const { return this->X == v.X && this->Y == v.Y && this->Z == v.Z && this->W == v.W; }
bool Vector4::operator!=(const Vector4 &v) const { return this->X != v.X || this->Y != v.Y || this->Z != v.Z || this->W != v.W; }
Vector4 &Vector4::operator=(const Vector4 &v)
{
    this->X = v.X;
    this->Y = v.Y;
    this->Z = v.Z;
    this->W = v.W;
    return *this;
}
Vector4 &Vector4::operator+=(const Vector4 &v)
{
    this->X += v.X;
    this->Y += v.Y;
    this->Z += v.Z;
    this->W += v.W;
    return *this;
}
Vector4 &Vector4::operator-=(const Vector4 &v)
{
    this->X -= v.X;
    this->Y -= v.Y;
    this->Z -= v.Z;
    this->W -= v.W;
    return *this;
}
Vector4 &Vector4::operator*=(const Vector4 &v)
{
    this->X *= v.X;
    this->Y *= v.Y;
    this->Z *= v.Z;
    this->W *= v.W;
    return *this;
}
Vector4 &Vector4::operator/=(const Vector4 &v)
{
    this->X /= v.X;
    this->Y /= v.Y;
    this->Z /= v.Z;
    this->W /= v.W;
    return *this;
}
Vector4 &Vector4::operator=(float s)
{
    this->X = s;
    this->Y = s;
    this->Z = s;
    this->W = s;
    return *this;
}
Vector4 &Vector4::operator+=(float s)
{
    this->X += s;
    this->Y += s;
    this->Z += s;
    this->W += s;
    return *this;
}
Vector4 &Vector4::operator-=(float s)
{
    this->X -= s;
    this->Y -= s;
    this->Z -= s;
    this->W -= s;
    return *this;
}
Vector4 &Vector4::operator*=(float s)
{
    this->X *= s;
    this->Y *= s;
    this->Z *= s;
    this->W *= s;
    return *this;
}
Vector4 &Vector4::operator/=(float s)
{
    this->X /= s;
    this->Y /= s;
    this->Z /= s;
    this->W /= s;
    return *this;
}
Vector4 Vector4::operator+(const Vector4 &v) const { return Vector4({this->X + v.X, this->Y + v.Y, this->Z + v.Z, this->W + v.W}); }
Vector4 Vector4::operator-(const Vector4 &v) const { return Vector4({this->X - v.X, this->Y - v.Y, this->Z - v.Z, this->W - v.W}); }
Vector4 Vector4::operator*(const Vector4 &v) const { return Vector4({this->X * v.X, this->Y * v.Y, this->Z * v.Z, this->W * v.W}); }
Vector4 Vector4::operator/(const Vector4 &v) const { return Vector4({this->X / v.X, this->Y / v.Y, this->Z / v.Z, this->W / v.W}); }
Vector4 Vector4::operator+(float const &s) const { return Vector4(this->X + s, this->Y + s, this->Z + s, this->W + s); }
Vector4 Vector4::operator-(float const &s) const { return Vector4(this->X - s, this->Y - s, this->Z - s, this->W - s); }
Vector4 Vector4::operator*(float const &s) const { return Vector4(this->X * s, this->Y * s, this->Z * s, this->W * s); }
Vector4 Vector4::operator/(float const &s) const { return Vector4(this->X / s, this->Y / s, this->Z / s, this->W / s); }

// Returns a Vector4 with all of its components set to one.
getref_property<Vector4> Vector4::One =
    getref_property<Vector4>([]() -> const Vector4 & {
        static Vector4 v(1.0f);
        return v;
    });

// Returns the Vector4 (0, 0, 0, 1).
getref_property<Vector4> Vector4::UnitW =
    getref_property<Vector4>([]() -> Vector4 & {
        static Vector4 v(0.0f, 0.0f, 0.0f, 1.0f);
        return v;
    });

// Returns the Vector4 (1, 0, 0, 0).
getref_property<Vector4> Vector4::UnitX =
    getref_property<Vector4>([]() -> Vector4 & {
        static Vector4 v(1.0f, 0.0f, 0.0f, 0.0f);
        return v;
    });

// Returns the Vector4 (0, 1, 0, 0).
getref_property<Vector4> Vector4::UnitY =
    getref_property<Vector4>([]() -> Vector4 & {
        static Vector4 v(0.0f, 1.0f, 0.0f, 0.0f);
        return v;
    });

// Returns the Vector4 (0, 0, 1, 0).
getref_property<Vector4> Vector4::UnitZ =
    getref_property<Vector4>([]() -> Vector4 & {
        static Vector4 v(0.0f, 0.0f, 1.0f, 0.0f);
        return v;
    });

// Returns the Vector4 (0, 0, 1, 0).
getref_property<Vector4> Vector4::Zero =
    getref_property<Vector4>([]() -> Vector4 & {
        static Vector4 v(0.0f);
        return v;
    });

// Overloaded. Adds two vectors.
Vector4 Vector4::Add(const Vector4 &a, const Vector4 &b)
{
    return Vector4(
        a.X + b.X,
        a.Y + b.Y,
        a.Z + b.Z,
        a.W + b.W);
}

// Overloaded. Returns a Vector4 containing the 2D Cartesian coordinates of a point specified in 2D barycentric (areal) coordinates.
Vector4 Vector4::Barycentric(const Vector4 &a, const Vector4 &b, const Vector4 &c, float value1, float value2)
{
    return Vector4();
}

// Overloaded. Performs a Catmull-Rom interpolation using the specified positions.
Vector4 Vector4::CatmullRom(const Vector4 &a, const Vector4 &b, const Vector4 &c, const Vector4 &d, float amount)
{
    return Vector4();
}

// Overloaded. Restricts a value to be within a specified range.
Vector4 Vector4::Clamp(const Vector4 &value, const Vector4 &min, const Vector4 &max)
{
    return Vector4();
}

// Overloaded. Calculates the distance between two vectors.
float Vector4::Distance(const Vector4 &a, const Vector4 &b)
{
    return 0.0f;
}

// Overloaded. Calculates the distance between two vectors squared.
float Vector4::DistanceSquared(const Vector4 &a, const Vector4 &b)
{
    return 0.0f;
}

// Overloaded. Divides a vector by a scalar or another vector.
Vector4 Vector4::Divide(const Vector4 &a, const Vector4 &b)
{
    return Vector4();
}

// Overloaded. Calculates the dot product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
float Vector4::Dot(const Vector4 &a, const Vector4 &b)
{
    return 0.0f;
}

// Overloaded. Performs a Hermite spline interpolation.
Vector4 Vector4::Hermite(const Vector4 &value1, const Vector4 &tangent1,
                         const Vector4 &value2, const Vector4 &tangent2, float amount)
{
    return Vector4();
}

// Calculates the length of the vector.
float Vector4::Length() const
{
    return 0.0f;
}

// Calculates the length of the vector squared.
float Vector4::LengthSquared() const
{
    return 0.0f;
}

// Overloaded. Performs a linear interpolation between two vectors.
Vector4 Vector4::Lerp(const Vector4 &a, const Vector4 &b, float amount)
{
    return Vector4();
}

// Overloaded. Returns a vector that contains the highest value from each matching pair of components.
Vector4 Vector4::Max(const Vector4 &a, const Vector4 &b)
{
    return Vector4();
}

// Overloaded. Returns a vector that contains the lowest value from each matching pair of components.
Vector4 Vector4::Min(const Vector4 &a, const Vector4 &b)
{
    return Vector4();
}

// Overloaded. Multiplies a vector by a scalar or another vector.
Vector4 Vector4::Multiply(const Vector4 &a, const Vector4 &b)
{
    return Vector4();
}

Vector4 Vector4::Multiply(const Vector4 &a, float b)
{
    return Vector4();
}

// Overloaded. Returns a vector pointing in the opposite direction.
Vector4 Vector4::Negate(const Vector4 &v)
{
    return Vector4();
}

// Overloaded. Creates a unit vector from the specified vector. The result is a vector one unit in length pointing in the same direction as the original vector.
Vector4 Vector4::Normalize() const
{
    return Vector4();
}

// Overloaded. Determines the reflect vector of the given vector and normal.
Vector4 Vector4::Reflect(const Vector4 &a, const Vector4 &b)
{
    return Vector4();
}

// Overloaded. Interpolates between two values using a cubic equation.
Vector4 Vector4::SmoothStep(const Vector4 &a, const Vector4 &b, float amount)
{
    return Vector4();
}

// Overloaded. Subtracts a vector from a vector.
Vector4 Vector4::Subtract(const Vector4 &a, const Vector4 &b)
{
    return Vector4();
}

// Overloaded. Transforms one or more Vector4s by a Matrix or Quaternion.
Vector4 Vector4::Transform(const Vector4 &v, const class Matrix &m)
{
    return Vector4();
}

Vector4 Vector4::Transform(const Vector4 &v, const class Quaternion &q)
{
    return Vector4();
}

// Overloaded. Transforms a vector normal or array of vector normals by a matrix.
Vector4 Vector4::TransformNormal(const Vector4 &v, const class Matrix &m)
{
    return Vector4();
}

Vector4 Vector4::TransformNormal(const Vector4 &v, const class Quaternion &q)
{
    return Vector4();
}
