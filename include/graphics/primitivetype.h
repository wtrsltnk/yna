#ifndef PRIMITIVETYPE_H
#define PRIMITIVETYPE_H

namespace yna
{

namespace framework
{

namespace graphics
{

enum class PrimitiveType
{
    // The data is ordered as a sequence of triangles; each triangle is described by three new vertices. Back-face culling is affected by the current winding-order render state.
    TriangleList,
    // The data is ordered as a sequence of triangles; each triangle is described by two new vertices and one vertex from the previous triangle. The back-face culling flag is flipped automatically on even-numbered triangles.
    TriangleStrip,
    // The data is ordered as a sequence of line segments; each line segment is described by two new vertices. The count may be any positive integer.
    LineList,
    // The data is ordered as a sequence of line segments; each line segment is described by one new vertex and the last vertex from the previous line seqment. The count may be any positive integer.
    LineStrip,
};

}

}

}

#endif // PRIMITIVETYPE_H
