#ifndef VECTOR3_H
#define VECTOR3_H

#include "property.h"

namespace yna
{

namespace framework
{

struct Vector3
{
    Vector3();
    Vector3(float v);
    Vector3(float x, float y, float z);

    // Gets or sets the x-component of the vector.
    float X;
    // Gets or sets the y-component of the vector.
    float Y;
    // Gets or sets the z-component of the vector.
    float Z;

    float & operator[](int i);
    float operator[](int i) const;
    Vector3& operator  = (const Vector3& v);
    Vector3& operator += (const Vector3& v);
    Vector3& operator -= (const Vector3& v);
    Vector3& operator *= (const Vector3& v);
    Vector3& operator /= (const Vector3& v);
    Vector3& operator  = (float s);
    Vector3& operator += (float s);
    Vector3& operator -= (float s);
    Vector3& operator *= (float s);
    Vector3& operator /= (float s);
    bool operator == (const Vector3& v) const;
    bool operator != (const Vector3& v) const;
    Vector3 operator + (float const & s) const;
    Vector3 operator - (float const & s) const;
    Vector3 operator * (float const & s) const;
    Vector3 operator / (float const & s) const;
    Vector3 operator + (const Vector3& v) const;
    Vector3 operator - (const Vector3& v) const;
    Vector3 operator * (const Vector3& v) const;
    Vector3 operator / (const Vector3& v) const;

    // Returns a unit Vector3 designating backward in a right-handed coordinate system (0, 0, 1).
    static getref_property<Vector3> Backward;
    // Returns a unit Vector3 designating down (0, −1, 0).
    static getref_property<Vector3> Down;
    // Returns a unit Vector3 designating forward in a right-handed coordinate system(0, 0, −1).
    static getref_property<Vector3> Forward;
    // Returns a unit Vector3 designating left (−1, 0, 0).
    static getref_property<Vector3> Left;
    // Returns a unit Vector3 pointing to the right (1, 0, 0).
    static getref_property<Vector3> Right;
    // Returns a unit vector designating up (0, 1, 0).
    static getref_property<Vector3> Up;

    // Returns a Vector3 with all of its components set to one.
    static getref_property<Vector3> One;
    // Returns the Vector3 (1, 0, 0).
    static getref_property<Vector3> UnitX;
    // Returns the Vector3 (0, 1, 0).
    static getref_property<Vector3> UnitY;
    // Returns the Vector3 (0, 0, 1).
    static getref_property<Vector3> UnitZ;
    // Returns a Vector3 with all of its components set to zero.
    static getref_property<Vector3> Zero;

    // Overloaded. Adds two vectors.
    static Vector3 Add(const Vector3& a, const Vector3& b);
    // Overloaded. Returns a Vector3 containing the 2D Cartesian coordinates of a point specified in 2D barycentric (areal) coordinates.
    static Vector3 Barycentric(const Vector3& a, const Vector3& b, const Vector3& c, float value1, float value2);
    // Overloaded. Performs a Catmull-Rom interpolation using the specified positions.
    static Vector3 CatmullRom(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d, float amount);
    // Overloaded. Restricts a value to be within a specified range.
    static Vector3 Clamp(const Vector3& value, const Vector3& min, const Vector3& max);
    // Overloaded. Calculates the distance between two vectors.
    static float Distance(const Vector3& a, const Vector3& b);
    // Overloaded. Calculates the distance between two vectors squared.
    static float DistanceSquared(const Vector3& a, const Vector3& b);
    // Overloaded. Divides a vector by a scalar or another vector.
    static Vector3 Divide(const Vector3& a, const Vector3& b);
    // Overloaded. Calculates the dot    product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
    static float Dot(const Vector3& a, const Vector3& b);
    // Overloaded. Performs a Hermite spline interpolation.
    static Vector3 Hermite(const Vector3& value1, const Vector3& tangent1, const Vector3& value2, const Vector3& tangent2, float amount);
    // Calculates the length of the vector.
    float Length() const;
    // Calculates the length of the vector squared.
    float LengthSquared() const;
    // Overloaded. Performs a linear interpolation between two vectors.
    static Vector3 Lerp(const Vector3& a, const Vector3& b, float amount);
    // Overloaded. Returns a vector that contains the highest value from each matching pair of components.
    static Vector3 Max(const Vector3& a, const Vector3& b);
    // Overloaded. Returns a vector that contains the lowest value from each matching pair of components.
    static Vector3 Min(const Vector3& a, const Vector3& b);
    // Overloaded. Multiplies a vector by a scalar or another vector.
    static Vector3 Multiply(const Vector3& a, const Vector3& b);
    static Vector3 Multiply(const Vector3& a, float b);
    // Overloaded. Returns a vector pointing in the opposite direction.
    static Vector3 Negate(const Vector3& v);
    // Overloaded. Creates a unit vector from the specified vector. The result is a vector one unit in length pointing in the same direction as the original vector.
    Vector3 Normalize() const;
    // Overloaded. Determines the reflect vector of the given vector and normal.
    static Vector3 Reflect(const Vector3& a, const Vector3& b);
    // Overloaded. Interpolates between two values using a cubic equation.
    static Vector3 SmoothStep(const Vector3& a, const Vector3& b, float amount);
    // Overloaded. Subtracts a vector from a vector.
    static Vector3 Subtract(const Vector3& a, const Vector3& b);
    // Overloaded. Transforms one or more Vector3s by a Matrix or Quaternion.
    static Vector3 Transform(const Vector3& v, const class Matrix& m);
    static Vector3 Transform(const Vector3& v, const class Quaternion& q);
    // Overloaded. Transforms a vector normal or array of vector normals by a matrix.
    static Vector3 TransformNormal(const Vector3& v, const class Matrix& m);
    static Vector3 TransformNormal(const Vector3& v, const class Quaternion& q);
};

}

}

#endif // VECTOR3_H
