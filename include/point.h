#ifndef POINT_H
#define POINT_H

#include "property.h"

namespace yna
{

    namespace framework
    {

        struct Point
        {
            Point();
            Point(int v);
            Point(int x, int y);

            // Specifies the x-coordinate of the Point.
            int X;
            // Specifies the y-coordinate of the Point.
            int Y;

            bool operator==(const Point &v) const;
            bool operator!=(const Point &v) const;

            // Returns the point (0,0).
            static getref_property<Point> Zero;
        };

    } // namespace framework

} // namespace yna

#endif // POINT_H
