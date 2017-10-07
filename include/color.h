#ifndef COLOR_H
#define COLOR_H

namespace yna
{

namespace framework
{

typedef unsigned char byte;

struct Color
{
    Color();
    Color(byte v);
    Color(byte r, byte g, byte b, byte a = 255);

    byte R;
    byte G;
    byte B;
    byte A;
};

}

}

#endif // COLOR_H
