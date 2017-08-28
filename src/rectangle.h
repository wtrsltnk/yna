#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "property.h"

namespace yna
{

namespace framework
{

class Rectangle
{
public:
    Rectangle();
    Rectangle(int x, int y, int width, int height);

    // Specifies the height of the rectangle.
    int Height;
    // Specifies the width of the rectangle.
    int Width;
    // Specifies the x-coordinate of the rectangle.
    int X;
    // Specifies the y-coordinate of the rectangle.
    int Y;

    // Returns the y-coordinate of the bottom of the rectangle.
    getref_property<int> Bottom;
    // Returns the x-coordinate of the left side of the rectangle.
    getref_property<int> Left;
    // Returns the x-coordinate of the right side of the rectangle.
    getref_property<int> Right;
    // Returns the y-coordinate of the top of the rectangle.
    getref_property<int> Top;
};

}

}

#endif // RECTANGLE_H
