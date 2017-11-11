#include "graphics/vertexbuffer.h"

using namespace yna::framework::graphics;

VertexBuffer::VertexBuffer(graphics::GraphicsDevice* graphicsDevice, graphics::VertexDeclaration vertexDeclaration, int vertexCount, BufferUsage usage)
    : GraphicsResource(graphicsDevice), VertexCount(vertexCount), VertexDeclaration(vertexDeclaration)
{ }

VertexBuffer::~VertexBuffer()
{ }

void VertexBuffer::GetData(int offsetInBytes, byte** data, int startIndex, int elementCount, int vertexStride) const
{

}

void VertexBuffer::SetData(int offsetInBytes, byte** data, int startIndex, int elementCount, int vertexStride)
{

}
