#include "point.h"

using namespace yna::framework;

Point::Point()
    : X(0), Y(0)
{}

Point::Point(
    int v)
    : X(v), Y(v)
{}

Point::Point(
    int x,
    int y)
    : X(x),
      Y(y)
{}

bool Point::operator==(
    const Point &v) const
{
    return this->X == v.X && this->Y == v.Y;
}

bool Point::operator!=(
    const Point &v) const
{
    return this->X != v.X || this->Y != v.Y;
}

// Returns the point (0,0).
getref_property<Point> Point::Zero =
    getref_property<Point>([]() -> Point & {
        static Point p(0);
        return p;
    });
