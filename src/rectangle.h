#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "property.h"

namespace yna
{

namespace framework
{

struct Rectangle
{
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

    bool operator == (const Rectangle& r) const;
    bool operator != (const Rectangle& r) const;

    // Returns the y-coordinate of the bottom of the rectangle.
    int Bottom() const;
    // Gets the Point that specifies the center of the rectangle.
    struct Point Center() const;
    // Gets a value that indicates whether the Rectangle is empty.
    bool IsEmpty() const;
    // Returns the x-coordinate of the left side of the rectangle.
    int Left() const;
    //Gets or sets the upper-left value of the Rectangle.
    struct Point Location() const;
    // Returns the x-coordinate of the right side of the rectangle.
    int Right() const;
    // Returns the y-coordinate of the top of the rectangle.
    int Top() const;

    // Determines whether this Rectangle contains a specified point represented by its x- and y-coordinates.
    bool Contains(int x, int y) const;
    // Determines whether this Rectangle contains a specified Point.
    bool Contains(const struct Point& point) const;
    // Determines whether this Rectangle entirely contains a specified Rectangle.
    bool Contains(const Rectangle& rectangle) const;

    // Pushes the edges of the Rectangle out by the horizontal and vertical values specified.
    void Inflate(int horizontalAmount, int verticalAmount);
    // Creates a Rectangle defining the area where one rectangle overlaps with another rectangle.
    static Rectangle Intersect(const Rectangle& rectanlge1, const Rectangle& rectanlge2);
    // Overloaded. Determines whether a specified Rectangle intersects with this Rectangle.
    bool Intersects(const Rectangle& rectangle) const;
    // Overloaded. Changes the position of the Rectangle.
    void Offset(int x, int y);
    void Offset(const struct Point& p);
    // Creates a new Rectangle that exactly contains two other rectangles.
    static Rectangle Union(const Rectangle& rectangle1, const Rectangle& rectangle2);
};

}

}

#endif // RECTANGLE_H
