#include "color.h"

using namespace yna::framework;

Color::Color()
    : R(255), G(255), B(255), A(255)
{ }

Color::Color(byte v)
    : R(v), G(v), B(v), A(v)
{ }

Color::Color(byte r, byte g, byte b, byte a)
    : R(r), G(g), B(b), A(a)
{ }
