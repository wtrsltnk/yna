#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "bufferusage.h"
#include "graphicsresource.h"
#include "vertexdeclaration.h"
#include "property.h"
#include "color.h"

namespace yna
{

namespace framework
{

namespace graphics
{

class VertexBuffer : public GraphicsResource
{
public:
    VertexBuffer(graphics::GraphicsDevice* graphicsDevice, graphics::VertexDeclaration vertexDeclaration, int vertexCount, BufferUsage usage);
    virtual ~VertexBuffer();

    // Gets the number of vertices.
    property<int> VertexCount;
    // Defines per-vertex data in a buffer.
    property<graphics::VertexDeclaration> VertexDeclaration;

    // Overloaded. Returns a copy of the vertex buffer data.
    void GetData(int offsetInBytes, byte** data, int startIndex, int elementCount, int vertexStride) const;

    // Overloaded. Sets the vertex buffer data.
    void SetData(int offsetInBytes, byte** data, int startIndex, int elementCount, int vertexStride);
};

}

}

}

#endif // VERTEXBUFFER_H
