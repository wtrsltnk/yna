#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include "../property.h"
//#include "../rectangle.h"

namespace yna
{

namespace framework
{

namespace graphics
{

class GraphicsDevice
{
public:
    GraphicsDevice();

//    property<Rectangle> Viewport;

    //Overloaded. Presents the display with the contents of the next buffer in the sequence of back buffers owned by the GraphicsDevice.
    virtual void Present() = 0;
};

}

}

}

#endif // GRAPHICSDEVICE_H
