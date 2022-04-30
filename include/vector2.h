#ifndef VECTOR2_H
#define VECTOR2_H

#include "property.h"

namespace yna
{

    namespace framework
    {

        struct Vector2
        {
            Vector2();
            Vector2(float v);
            Vector2(float x, float y);

            // Gets or sets the x-component of the vector.
            float X;
            // Gets or sets the y-component of the vector.
            float Y;

            float &operator[](int i);
            float operator[](int i) const;
            bool operator==(const Vector2 &v) const;
            bool operator!=(const Vector2 &v) const;
            Vector2 &operator=(const Vector2 &v);
            Vector2 &operator+=(const Vector2 &v);
            Vector2 &operator-=(const Vector2 &v);
            Vector2 &operator*=(const Vector2 &v);
            Vector2 &operator/=(const Vector2 &v);
            Vector2 &operator=(float s);
            Vector2 &operator+=(float s);
            Vector2 &operator-=(float s);
            Vector2 &operator*=(float s);
            Vector2 &operator/=(float s);
            Vector2 operator+(const Vector2 &v) const;
            Vector2 operator-(const Vector2 &v) const;
            Vector2 operator*(const Vector2 &v) const;
            Vector2 operator/(const Vector2 &v) const;
            Vector2 operator+(float const &s) const;
            Vector2 operator-(float const &s) const;
            Vector2 operator*(float const &s) const;
            Vector2 operator/(float const &s) const;

            // Returns a Vector2 with all of its components set to one.
            static getref_property<Vector2> One;
            // Returns the Vector2 (1, 0).
            static getref_property<Vector2> UnitX;
            // Returns the Vector2 (0, 1).
            static getref_property<Vector2> UnitY;
            // Returns a Vector2 with all of its components set to zero.
            static getref_property<Vector2> Zero;

            // Overloaded. Adds two vectors.
            static Vector2 Add(const Vector2 &a, const Vector2 &b);
            // Overloaded. Returns a Vector2 containing the 2D Cartesian coordinates of a point specified in 2D barycentric (areal) coordinates.
            static Vector2 Barycentric(const Vector2 &a, const Vector2 &b, const Vector2 &c, float value1, float value2);
            // Overloaded. Performs a Catmull-Rom interpolation using the specified positions.
            static Vector2 CatmullRom(const Vector2 &a, const Vector2 &b, const Vector2 &c, const Vector2 &d, float amount);
            // Overloaded. Restricts a value to be within a specified range.
            static Vector2 Clamp(const Vector2 &value, const Vector2 &min, const Vector2 &max);
            // Overloaded. Calculates the distance between two vectors.
            static float Distance(const Vector2 &a, const Vector2 &b);
            // Overloaded. Calculates the distance between two vectors squared.
            static float DistanceSquared(const Vector2 &a, const Vector2 &b);
            // Overloaded. Divides a vector by a scalar or another vector.
            static Vector2 Divide(const Vector2 &a, const Vector2 &b);
            // Overloaded. Calculates the dot product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
            static float Dot(const Vector2 &a, const Vector2 &b);
            // Overloaded. Performs a Hermite spline interpolation.
            static Vector2 Hermite(const Vector2 &value1, const Vector2 &tangent1, const Vector2 &value2, const Vector2 &tangent2, float amount);
            // Calculates the length of the vector.
            float Length() const;
            // Calculates the length of the vector squared.
            float LengthSquared() const;
            // Overloaded. Performs a linear interpolation between two vectors.
            static Vector2 Lerp(const Vector2 &a, const Vector2 &b, float amount);
            // Overloaded. Returns a vector that contains the highest value from each matching pair of components.
            static Vector2 Max(const Vector2 &a, const Vector2 &b);
            // Overloaded. Returns a vector that contains the lowest value from each matching pair of components.
            static Vector2 Min(const Vector2 &a, const Vector2 &b);
            // Overloaded. Multiplies a vector by a scalar or another vector.
            static Vector2 Multiply(const Vector2 &a, const Vector2 &b);
            static Vector2 Multiply(const Vector2 &a, float b);
            // Overloaded. Returns a vector pointing in the opposite direction.
            static Vector2 Negate(const Vector2 &v);
            // Overloaded. Creates a unit vector from the specified vector. The result is a vector one unit in length pointing in the same direction as the original vector.
            Vector2 Normalize() const;
            // Overloaded. Determines the reflect vector of the given vector and normal.
            static Vector2 Reflect(const Vector2 &a, const Vector2 &b);
            // Overloaded. Interpolates between two values using a cubic equation.
            static Vector2 SmoothStep(const Vector2 &a, const Vector2 &b, float amount);
            // Overloaded. Subtracts a vector from a vector.
            static Vector2 Subtract(const Vector2 &a, const Vector2 &b);
            // Overloaded. Transforms one or more Vector2s by a Matrix or Quaternion.
            static Vector2 Transform(const Vector2 &v, const class Matrix &m);
            static Vector2 Transform(const Vector2 &v, const class Quaternion &q);
            // Overloaded. Transforms a vector normal or array of vector normals by a matrix.
            static Vector2 TransformNormal(const Vector2 &v, const class Matrix &m);
            static Vector2 TransformNormal(const Vector2 &v, const class Quaternion &q);
        };

    } // namespace framework

} // namespace yna

#endif // VECTOR2_H
