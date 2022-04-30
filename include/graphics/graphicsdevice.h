#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include "../color.h"
#include "../property.h"
#include "../rectangle.h"
#include "../vector4.h"
#include "clearoptions.h"
#include "primitivetype.h"
#include "vertexbuffer.h"

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
                virtual void Clear(ClearOptions options, const Color &color, float depth, int stencil) = 0;
                virtual void Clear(ClearOptions options, const Vector4 &color, float depth, int stencil) = 0;
                virtual void Clear(const Color &color) = 0;

                virtual void DrawPrimitives(PrimitiveType primitiveType, int startVertex, int primitiveCount) = 0;

                //Overloaded. Presents the display with the contents of the next buffer in the sequence of back buffers owned by the GraphicsDevice.
                virtual void Present() = 0;

                // Sets or binds a vertex buffer to a device.
                virtual void SetVertexBuffer(VertexBuffer &vertexBuffer) = 0;
                virtual void SetVertexBuffer(VertexBuffer &vertexBuffer, int vertexOffset) = 0;
            };

        } // namespace graphics

    } // namespace framework

} // namespace yna

#endif // GRAPHICSDEVICE_H
