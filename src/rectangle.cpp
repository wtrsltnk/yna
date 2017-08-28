#include "rectangle.h"
#include "point.h"

using namespace yna::framework;

Rectangle::Rectangle()
    : X(0), Y(0), Width(0), Height(0)
{ }

Rectangle::Rectangle(int x, int y, int width, int height)
    : X(x), Y(y), Width(width), Height(height)
{ }

bool Rectangle::operator == (const Rectangle& r) const
{
    return (X == r.X) && (Y == r.Y) && (Width == r.Width) && (Height == r.Height);
}

bool Rectangle::operator != (const Rectangle& r) const
{
    return (X != r.X) || (Y != r.Y) || (Width != r.Width) || (Height != r.Height);
}

int Rectangle::Bottom() const
{
    return this->Y + this->Height;
}

struct Point Rectangle::Center() const
{
    return Point(this->X + (this->Width / 2), this->Y + (this->Height / 2));
}

bool Rectangle::IsEmpty() const
{
    return (this->X == 0) && (this->Y == 0) && (this->Width == 0) && (this->Height == 0);
}

int Rectangle::Left() const
{
    return this->X;
}

struct Point Rectangle::Location() const
{
    return Point(this->X, this->Y);
}

int Rectangle::Right() const
{
    return this->X + this->Width;
}

int Rectangle::Top() const
{
    return this->Y;
}

// Determines whether this Rectangle contains a specified point represented by its x- and y-coordinates.
bool Rectangle::Contains(int x, int y) const
{
    return !((x < X) || (y < Y) || (x > X + Width) || (y > Y + Height));
}

// Determines whether this Rectangle contains a specified Point.
bool Rectangle::Contains(const struct Point& point) const
{
    return Contains(point.X, point.Y);
}

// Determines whether this Rectangle entirely contains a specified Rectangle.
bool Rectangle::Contains(const Rectangle& rectangle) const
{
    return !(
                (rectangle.X < this->X)
                || (rectangle.Y < this->Y)
                || (rectangle.Width > (this->Width - (rectangle.X - this->X)))
                || (rectangle.Height > (this->Height - (rectangle.Y - this->Y)))
                );
}

// Pushes the edges of the Rectangle out by the horizontal and vertical values specified.
void Rectangle::Inflate(int horizontalAmount, int verticalAmount)
{
    this->X -= horizontalAmount;
    this->Y -= verticalAmount;

    this->Width += (horizontalAmount * 2);
    this->Height += (verticalAmount * 2);
}

// Creates a Rectangle defining the area where one rectangle overlaps with another rectangle.
Rectangle Rectangle::Intersect(const Rectangle& rectanlge1, const Rectangle& rectanlge2)
{
    return Rectangle();
}

// Overloaded. Determines whether a specified Rectangle intersects with this Rectangle.
bool Rectangle::Intersects(const Rectangle& rectangle) const
{
    return !(rectangle.Left() > Right()
             || rectangle.Right() < Left()
             || rectangle.Top() > Bottom()
             || rectangle.Bottom() < Top()
            );
}

// Overloaded. Changes the position of the Rectangle.
void Rectangle::Offset(int x, int y)
{
    this->X += x;
    this->Y += y;
}

void Rectangle::Offset(const struct Point& p)
{
    Offset(p.X, p.Y);
}

// Creates a new Rectangle that exactly contains two other rectangles.
Rectangle Rectangle::Union(const Rectangle& rectangle1, const Rectangle& rectangle2)
{
    return Rectangle();
}
