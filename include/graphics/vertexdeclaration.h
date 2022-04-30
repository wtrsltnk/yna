#ifndef VERTEXDECLARATION_H
#define VERTEXDECLARATION_H

#include "graphicsresource.h"
#include "property.h"
#include "vertexelement.h"

#include <vector>

namespace yna
{

    namespace framework
    {

        namespace graphics
        {

            class VertexDeclaration : public GraphicsResource
            {
            public:
                VertexDeclaration(
                    class GraphicsDevice *graphicsDevice,
                    int vertexStride,
                    std::vector<VertexElement> &elements);

                // The number of bytes from one vertex to the next.
                property<int> VertexStride;

                // Gets the vertex shader declaration.
                std::vector<VertexElement> GetVertexElements();

            private:
                std::vector<VertexElement> &_elements;
            };

        } // namespace graphics

    } // namespace framework

} // namespace yna

#endif // VERTEXDECLARATION_H
