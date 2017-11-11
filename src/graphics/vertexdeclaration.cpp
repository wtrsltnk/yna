#include "graphics/vertexdeclaration.h"

using namespace yna::framework::graphics;

VertexDeclaration::VertexDeclaration(class GraphicsDevice* graphicsDevice, int vertexStride, std::vector<VertexElement>& elements)
    : GraphicsResource(graphicsDevice), VertexStride(vertexStride), _elements(elements)
{ }

std::vector<VertexElement> VertexDeclaration::GetVertexElements()
{
    return _elements;
}
