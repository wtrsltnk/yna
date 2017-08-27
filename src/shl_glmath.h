#ifndef SHL_GLMATH_H
#define SHL_GLMATH_H

#include <cassert>
#include <cmath>

namespace shl
{
namespace glmath
{

class vec2
{
public:
    virtual ~vec2() { }
    
    union { float x, r, s; };
    union { float y, g, t; };

    vec2() : x(0.0f), y(0.0f) { }
    vec2(float _s) : x(_s), y(_s) { }
    vec2(float _x, float _y) : x(_x), y(_y) { }
    vec2(const vec2& _v) : x(_v.x), y(_v.y) { }
    vec2(const class vec3& _v);
    vec2(const class vec4& _v);
    
    float & operator[](int i) { assert(i >= 0 && i < 2); return (&x)[i]; }
    float operator[](int i) const { assert(i >= 0 && i < 2); return (&x)[i]; }
    vec2& operator  = (const vec2& v) { this->x  = v.x; this->y  = v.y; return *this; }
    vec2& operator += (const vec2& v) { this->x += v.x; this->y += v.y; return *this; }
    vec2& operator -= (const vec2& v) { this->x -= v.x; this->y -= v.y; return *this; }
    vec2& operator *= (const vec2& v) { this->x *= v.x; this->y *= v.y; return *this; }
    vec2& operator /= (const vec2& v) { this->x /= v.x; this->y /= v.y; return *this; }
    vec2& operator  = (float s) { this->x  = s; this->y  = s; return *this; }
    vec2& operator += (float s) { this->x += s; this->y += s; return *this; }
    vec2& operator -= (float s) { this->x -= s; this->y -= s; return *this; }
    vec2& operator *= (float s) { this->x *= s; this->y *= s; return *this; }
    vec2& operator /= (float s) { this->x /= s; this->y /= s; return *this; }
};

inline bool  operator == (const vec2& v1, const vec2& v2) { return v1.x == v2.x && v1.y == v2.y; }
inline bool  operator != (const vec2& v1, const vec2& v2) { return v1.x != v2.x || v1.y != v2.y; }
inline vec2 operator * (const vec2& v, float const & s) { return vec2(v.x * s, v.y * s); }
inline vec2  operator  + (const vec2& v1, const vec2& v2) { return vec2({ v1.x + v2.x, v1.y + v2.y }); }
inline vec2  operator  - (const vec2& v1, const vec2& v2) { return vec2({ v1.x - v2.x, v1.y - v2.y }); }
inline vec2  operator  * (const vec2& v1, const vec2& v2) { return vec2({ v1.x * v2.x, v1.y * v2.y }); }
inline vec2  operator  / (const vec2& v1, const vec2& v2) { return vec2({ v1.x / v2.x, v1.y / v2.y }); }

inline float dot(const vec2& a, const vec2& b) { return (a.x * b.x) + (a.y * b.y); }
inline float length2(const vec2& v) { return dot(v, v); }
inline float length(const vec2& v) { return sqrt(length2(v)); }

class vec3
{
public:
    virtual ~vec3() { }
    
    union { float x, r, s; };
    union { float y, g, t; };
    union { float z, b, p; };

    vec3() : x(0.0f), y(0.0f), z(0.0f) { }
    vec3(float _s) : x(_s), y(_s), z(_s) { }
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }
    vec3(const vec2& _v) : x(_v.x), y(_v.y), z(0.0f) { }
    vec3(const class vec3& _v) : x(_v.x), y(_v.y), z(_v.z) { }
    vec3(const class vec4& _v);
    
    float & operator[](int i) { assert(i >= 0 && i < 3); return (&x)[i]; }
    float operator[](int i) const { assert(i >= 0 && i < 3); return (&x)[i]; }
    vec3& operator  = (const vec3& v) { this->x  = v.x; this->y  = v.y; this->z  = v.z; return *this; }
    vec3& operator += (const vec3& v) { this->x += v.x; this->y += v.y; this->z += v.z; return *this; }
    vec3& operator -= (const vec3& v) { this->x -= v.x; this->y -= v.y; this->z -= v.z; return *this; }
    vec3& operator *= (const vec3& v) { this->x *= v.x; this->y *= v.y; this->z *= v.z; return *this; }
    vec3& operator /= (const vec3& v) { this->x /= v.x; this->y /= v.y; this->z /= v.z; return *this; }
    vec3& operator  = (float s) { this->x  = s; this->y  = s; this->z  = s; return *this; }
    vec3& operator += (float s) { this->x += s; this->y += s; this->z += s; return *this; }
    vec3& operator -= (float s) { this->x -= s; this->y -= s; this->z -= s; return *this; }
    vec3& operator *= (float s) { this->x *= s; this->y *= s; this->z *= s; return *this; }
    vec3& operator /= (float s) { this->x /= s; this->y /= s; this->z /= s; return *this; }
};

inline bool  operator == (const vec3& v1, const vec3& v2) { return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z; }
inline bool  operator != (const vec3& v1, const vec3& v2) { return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z; }
inline vec3 operator * (const vec3& v, float const & s) { return vec3(v.x * s, v.y * s, v.z * s); }
inline vec3  operator  + (const vec3& v1, const vec3& v2) { return vec3({ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }); }
inline vec3  operator  - (const vec3& v1, const vec3& v2) { return vec3({ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }); }
inline vec3  operator  * (const vec3& v1, const vec3& v2) { return vec3({ v1.x * v2.x, v1.y * v2.y, v1.z * v2.z }); }
inline vec3  operator  / (const vec3& v1, const vec3& v2) { return vec3({ v1.x / v2.x, v1.y / v2.y, v1.z / v2.z }); }

inline vec3 cross(const vec3& a, const vec3& b) { return vec3({ (a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x) }); }
inline float dot(const vec3& a, const vec3& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
inline float length2(const vec3& v) { return dot(v, v); }
inline float length(const vec3& v) { return sqrt(length2(v)); }

class vec4
{
public:
    virtual ~vec4() { }
    
    union { float x, r, s; };
    union { float y, g, t; };
    union { float z, b, p; };
    union { float w, a, q; };

    vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
    vec4(float _s) : x(_s), y(_s), z(_s), w(_s) { }
    vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) { }
    vec4(const vec2& _v) : x(_v.x), y(_v.y), z(0.0f), w(0.0f) { }
    vec4(const vec3& _v) : x(_v.x), y(_v.y), z(_v.z), w(0.0f) { }
    vec4(const vec4& _v) : x(_v.x), y(_v.y), z(_v.z), w(_v.w) { }
    
    float & operator[](int i) { assert(i >= 0 && i < 4); return (&x)[i]; }
    float operator[](int i) const { assert(i >= 0 && i < 4); return (&x)[i]; }
    vec4& operator  = (const vec4& v) { this->x  = v.x; this->y  = v.y; this->z  = v.z; this->w  = v.w; return *this; }
    vec4& operator += (const vec4& v) { this->x += v.x; this->y += v.y; this->z += v.z; this->w += v.w; return *this; }
    vec4& operator -= (const vec4& v) { this->x -= v.x; this->y -= v.y; this->z -= v.z; this->w -= v.w; return *this; }
    vec4& operator *= (const vec4& v) { this->x *= v.x; this->y *= v.y; this->z *= v.z; this->w *= v.w; return *this; }
    vec4& operator /= (const vec4& v) { this->x /= v.x; this->y /= v.y; this->z /= v.z; this->w /= v.w; return *this; }
    vec4& operator  = (float s) { this->x  = s; this->y  = s; this->z  = s; this->w  = s; return *this; }
    vec4& operator += (float s) { this->x += s; this->y += s; this->z += s; this->w += s; return *this; }
    vec4& operator -= (float s) { this->x -= s; this->y -= s; this->z -= s; this->w -= s; return *this; }
    vec4& operator *= (float s) { this->x *= s; this->y *= s; this->z *= s; this->w *= s; return *this; }
    vec4& operator /= (float s) { this->x /= s; this->y /= s; this->z /= s; this->w /= s; return *this; }
};

inline bool operator == (const vec4& v1, const vec4& v2) { return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w; }
inline bool operator != (const vec4& v1, const vec4& v2) { return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z || v1.w != v2.w; }
inline vec4 operator  * (const vec4& v, float const & s) { return vec4(v.x * s, v.y * s, v.z * s, v.w * s); }
inline vec4 operator  + (const vec4& v1, const vec4& v2) { return vec4({ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w }); }
inline vec4 operator  - (const vec4& v1, const vec4& v2) { return vec4({ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w }); }
inline vec4 operator  * (const vec4& v1, const vec4& v2) { return vec4({ v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w }); }
inline vec4 operator  / (const vec4& v1, const vec4& v2) { return vec4({ v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w }); }

inline float dot(const vec4& a, const vec4& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w); }
inline float length2(const vec4& v) { return dot(v, v); }
inline float length(const vec4& v) { return sqrt(length2(v)); }

inline vec2::vec2(const vec3& _v) : x(_v.x), y(_v.y) { }
inline vec2::vec2(const vec4& _v) : x(_v.x), y(_v.y) { }
inline vec3::vec3(const vec4& _v) : x(_v.x), y(_v.y), z(_v.z) { }

class mat4
{
    vec4 columns[4];
public:
    virtual ~mat4() { }
    
    mat4()
    {
        this->columns[0] = vec4(1, 0, 0, 0);
        this->columns[1] = vec4(0, 1, 0, 0);
        this->columns[2] = vec4(0, 0, 1, 0);
        this->columns[3] = vec4(0, 0, 0, 1);
    }
    
    mat4(float s)
    {
        this->columns[0] = vec4(s, 0, 0, 0);
        this->columns[1] = vec4(0, s, 0, 0);
        this->columns[2] = vec4(0, 0, s, 0);
        this->columns[3] = vec4(0, 0, 0, s);
    }
    
    mat4(const mat4& m)
    {
        this->columns[0] = m.columns[0];
        this->columns[1] = m.columns[1];
        this->columns[2] = m.columns[2];
        this->columns[3] = m.columns[3];
    }
    
    mat4(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3)
    {
        this->columns[0] = v0;
        this->columns[1] = v1;
        this->columns[2] = v2;
        this->columns[3] = v3;
    }
    
    mat4(float const & x0, float const & y0, float const & z0, float const & w0,
        float const & x1, float const & y1, float const & z1, float const & w1,
		float const & x2, float const & y2, float const & z2, float const & w2,
		float const & x3, float const & y3, float const & z3, float const & w3)
    {
        this->columns[0] = vec4(x0, y0, z0, w0);
        this->columns[1] = vec4(x1, y1, z1, w1);
        this->columns[2] = vec4(x2, y2, z2, w2);
        this->columns[3] = vec4(x3, y3, z3, w3);
    }

    vec4& operator[](int i) { assert(i >= 0 && i < 4); return columns[i]; }
    vec4 const & operator[](int i) const { assert(i >= 0 && i < 4); return columns[i]; }
};

inline bool operator == (const mat4& m1, const mat4& m2) { return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]); }
inline bool operator != (const mat4& m1, const mat4& m2) { return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]); }
inline mat4 operator * (const mat4& m, float const & s) { return mat4(m[0] * s, m[1] * s, m[2] * s, m[3] * s); }
inline vec4 operator * (const mat4& m, const vec4& v)
{
    vec4 result;
    
    int col, row;
    for(row = 0; row < 4; ++row)
    {
        float total = 0;
        
        for(col = 0; col < 4; ++col) total += m[col][row] * v[col];
        
        result[row] = total;
    }
    
    return result;
}

} // glmath
} // shl

#endif // SHL_GLMATH_H
