#include "rectangle.h"

using namespace yna::framework;

int bottom(Rectangle* rectangle)
{
    return rectangle->Y + rectangle->Height;
}

int left(Rectangle* rectangle)
{
    return rectangle->X;
}

int right(Rectangle* rectangle)
{
    return rectangle->X + rectangle->Width;
}

int top(Rectangle* rectangle)
{
    return rectangle->Y;
}

Rectangle::Rectangle()
    : Bottom([this] () -> int { return bottom(this); }),
      Left([this] () -> int { return left(this); }),
      Right([this] () -> int { return right(this); }),
      Top([this] () -> int { return top(this); })
{ }

Rectangle::Rectangle(int x, int y, int width, int height)
    : X(x), Y(y), Width(width), Height(height),
      Bottom([this] () -> int { return bottom(this); }),
      Left([this] () -> int { return left(this); }),
      Right([this] () -> int { return right(this); }),
      Top([this] () -> int { return top(this); })
{ }
