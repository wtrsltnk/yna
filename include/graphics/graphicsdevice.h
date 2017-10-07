#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include "../property.h"
#include "../rectangle.h"
#include "../color.h"
#include "../vector4.h"
#include "clearoptions.h"
#include "vertexbuffer.h"
#include "primitivetype.h"

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

    property<Rectangle> Viewport;

    // Clears resource buffers.
    virtual void Clear(ClearOptions options, const Color& color, float depth, int stencil) = 0;
    virtual void Clear(ClearOptions options, const Vector4& color, float depth, int stencil) = 0;
    virtual void Clear(const Color& color) = 0;

    virtual void DrawPrimitives(PrimitiveType primitiveType, int startVertex, int primitiveCount) = 0;

    //Overloaded. Presents the display with the contents of the next buffer in the sequence of back buffers owned by the GraphicsDevice.
    virtual void Present() = 0;

    // Sets or binds a vertex buffer to a device.
    virtual void SetVertexBuffer(const VertexBuffer& vertexBuffer) = 0;
    virtual void SetVertexBuffer(const VertexBuffer& vertexBuffer, int vertexOffset) = 0;
};

}

}

}

#endif // GRAPHICSDEVICE_H
