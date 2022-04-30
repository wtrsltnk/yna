#include "plane.h"

using namespace yna::framework;

Plane::Plane()
    : D(0.0f)
{}

Plane::Plane(
    float x,
    float y,
    float z,
    float d)
    : D(d),
      Normal(x, y, z)
{}

Plane::Plane(
    const Vector3 &normal,
    float d)
    : D(d),
      Normal(normal)
{}

Plane::Plane(
    const Vector3 &a,
    const Vector3 &b,
    const Vector3 &c)
    : D(0.0f)
{
    //    Normal = glm::normalize(glm::cross(a-b, c-b));
    //    D = glm::dot(b, normal);
}

Plane::Plane(
    const Vector4 &v)
    : D(v.W), Normal(v.X, v.Y, v.Z)
{}
