#ifndef VERTEXDECLARATION_H
#define VERTEXDECLARATION_H

#include "graphicsresource.h"
#include "vertexelement.h"
#include "property.h"

#include <vector>

namespace yna
{

namespace framework
{

namespace graphics
{

class VertexDeclaration : public GraphicsResource
{
    std::vector<VertexElement>& _elements;
public:
    VertexDeclaration(class GraphicsDevice* graphicsDevice, int vertexStride, std::vector<VertexElement>& elements);

    // The number of bytes from one vertex to the next.
    property<int> VertexStride;

    // Gets the vertex shader declaration.
     std::vector<VertexElement> GetVertexElements();
};

}

}

}

#endif // VERTEXDECLARATION_H
