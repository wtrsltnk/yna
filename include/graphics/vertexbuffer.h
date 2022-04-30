#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "bufferusage.h"
#include "color.h"
#include "graphicsresource.h"
#include "property.h"
#include "vertexdeclaration.h"

namespace yna
{

    namespace framework
    {

        namespace graphics
        {

            class VertexBuffer : public GraphicsResource
            {
            public:
                VertexBuffer(graphics::GraphicsDevice *graphicsDevice, graphics::VertexDeclaration vertexDeclaration, int vertexCount, BufferUsage usage);
                virtual ~VertexBuffer();

                // Gets the number of vertices.
                property<int> VertexCount;
                // Defines per-vertex data in a buffer.
                property<graphics::VertexDeclaration> VertexDeclaration;

                // Overloaded. Returns a copy of the vertex buffer data.
                void GetData(int offsetInBytes, byte **data, int startIndex, int elementCount, int vertexStride) const;

                // Overloaded. Sets the vertex buffer data.
                void SetData(int offsetInBytes, byte **data, int startIndex, int elementCount, int vertexStride);
            };

        } // namespace graphics

    } // namespace framework

} // namespace yna

#endif // VERTEXBUFFER_H
