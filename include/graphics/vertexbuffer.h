#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "graphicsresource.h"
#include "vertexdeclaration.h"
#include "property.h"

namespace yna
{

namespace framework
{

namespace graphics
{

class VertexBuffer : public GraphicsResource
{
public:
    // Gets the number of vertices.
    property<int> VertexCount;
    // Defines per-vertex data in a buffer.
    property<graphics::VertexDeclaration> VertexDeclaration;

    // Overloaded. Returns a copy of the vertex buffer data.
    void GetData(int offsetInBytes, void*& data, int startIndex, int elementCount, int vertexStride);

    // Overloaded. Sets the vertex buffer data.
    void SetData(int offsetInBytes, void* data, int startIndex, int elementCount, int vertexStride);
};

}

}

}

#endif // VERTEXBUFFER_H
