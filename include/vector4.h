#ifndef VECTOR4_H
#define VECTOR4_H

#include "property.h"

namespace yna
{

    namespace framework
    {

        struct Vector4
        {
            Vector4();
            Vector4(float v);
            Vector4(float x, float y, float z, float w);

            // Gets or sets the x-component of the vector.
            float X;
            // Gets or sets the y-component of the vector.
            float Y;
            // Gets or sets the z-component of the vector.
            float Z;
            // Gets or sets the w-component of the vector.
            float W;

            float &operator[](int i);
            float operator[](int i) const;
            bool operator==(const Vector4 &v) const;
            bool operator!=(const Vector4 &v) const;
            Vector4 &operator=(const Vector4 &v);
            Vector4 &operator+=(const Vector4 &v);
            Vector4 &operator-=(const Vector4 &v);
            Vector4 &operator*=(const Vector4 &v);
            Vector4 &operator/=(const Vector4 &v);
            Vector4 &operator=(float s);
            Vector4 &operator+=(float s);
            Vector4 &operator-=(float s);
            Vector4 &operator*=(float s);
            Vector4 &operator/=(float s);
            Vector4 operator+(const Vector4 &v) const;
            Vector4 operator-(const Vector4 &v) const;
            Vector4 operator*(const Vector4 &v) const;
            Vector4 operator/(const Vector4 &v) const;
            Vector4 operator+(float const &s) const;
            Vector4 operator-(float const &s) const;
            Vector4 operator*(float const &s) const;
            Vector4 operator/(float const &s) const;

            // Returns a Vector4 with all of its components set to one.
            static getref_property<Vector4> One;
            // Returns the Vector4 (0, 0, 0, 1).
            static getref_property<Vector4> UnitW;
            // Returns the Vector4 (1, 0, 0, 0).
            static getref_property<Vector4> UnitX;
            // Returns the Vector4 (0, 1, 0, 0).
            static getref_property<Vector4> UnitY;
            // Returns the Vector4 (0, 0, 1, 0).
            static getref_property<Vector4> UnitZ;
            // Returns a Vector4 with all of its components set to zero.
            static getref_property<Vector4> Zero;

            // Overloaded. Adds two vectors.
            static Vector4 Add(const Vector4 &a, const Vector4 &b);
            // Overloaded. Returns a Vector4 containing the 2D Cartesian coordinates of a point specified in 2D barycentric (areal) coordinates.
            static Vector4 Barycentric(const Vector4 &a, const Vector4 &b, const Vector4 &c, float value1, float value2);
            // Overloaded. Performs a Catmull-Rom interpolation using the specified positions.
            static Vector4 CatmullRom(const Vector4 &a, const Vector4 &b, const Vector4 &c, const Vector4 &d, float amount);
            // Overloaded. Restricts a value to be within a specified range.
            static Vector4 Clamp(const Vector4 &value, const Vector4 &min, const Vector4 &max);
            // Overloaded. Calculates the distance between two vectors.
            static float Distance(const Vector4 &a, const Vector4 &b);
            // Overloaded. Calculates the distance between two vectors squared.
            static float DistanceSquared(const Vector4 &a, const Vector4 &b);
            // Overloaded. Divides a vector by a scalar or another vector.
            static Vector4 Divide(const Vector4 &a, const Vector4 &b);
            // Overloaded. Calculates the dot product of two vectors. If the two vectors are unit vectors, the dot product returns a floating point value between -1 and 1 that can be used to determine some properties of the angle between two vectors. For example, it can show whether the vectors are orthogonal, parallel, or have an acute or obtuse angle between them.
            static float Dot(const Vector4 &a, const Vector4 &b);
            // Overloaded. Performs a Hermite spline interpolation.
            static Vector4 Hermite(const Vector4 &value1, const Vector4 &tangent1, const Vector4 &value2, const Vector4 &tangent2, float amount);
            // Calculates the length of the vector.
            float Length() const;
            // Calculates the length of the vector squared.
            float LengthSquared() const;
            // Overloaded. Performs a linear interpolation between two vectors.
            static Vector4 Lerp(const Vector4 &a, const Vector4 &b, float amount);
            // Overloaded. Returns a vector that contains the highest value from each matching pair of components.
            static Vector4 Max(const Vector4 &a, const Vector4 &b);
            // Overloaded. Returns a vector that contains the lowest value from each matching pair of components.
            static Vector4 Min(const Vector4 &a, const Vector4 &b);
            // Overloaded. Multiplies a vector by a scalar or another vector.
            static Vector4 Multiply(const Vector4 &a, const Vector4 &b);
            static Vector4 Multiply(const Vector4 &a, float b);
            // Overloaded. Returns a vector pointing in the opposite direction.
            static Vector4 Negate(const Vector4 &v);
            // Overloaded. Creates a unit vector from the specified vector. The result is a vector one unit in length pointing in the same direction as the original vector.
            Vector4 Normalize() const;
            // Overloaded. Determines the reflect vector of the given vector and normal.
            static Vector4 Reflect(const Vector4 &a, const Vector4 &b);
            // Overloaded. Interpolates between two values using a cubic equation.
            static Vector4 SmoothStep(const Vector4 &a, const Vector4 &b, float amount);
            // Overloaded. Subtracts a vector from a vector.
            static Vector4 Subtract(const Vector4 &a, const Vector4 &b);
            // Overloaded. Transforms one or more Vector4s by a Matrix or Quaternion.
            static Vector4 Transform(const Vector4 &v, const class Matrix &m);
            static Vector4 Transform(const Vector4 &v, const class Quaternion &q);
            // Overloaded. Transforms a vector normal or array of vector normals by a matrix.
            static Vector4 TransformNormal(const Vector4 &v, const class Matrix &m);
            static Vector4 TransformNormal(const Vector4 &v, const class Quaternion &q);
        };

    } // namespace framework

} // namespace yna

#endif // VECTOR4_H
