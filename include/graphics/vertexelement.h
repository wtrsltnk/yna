#ifndef VERTEXELEMENT_H
#define VERTEXELEMENT_H

namespace yna
{

namespace framework
{

namespace graphics
{

enum class VertexElementFormats
{
    // Single-component, 32-bit floating-point, expanded to (float, 0, 0, 1).
    Single,
    // Two-component, 32-bit floating-point, expanded to (float, Float32 value, 0, 1).
    Vector2,
    // Three-component, 32-bit floating point, expanded to (float, float, float, 1).
    Vector3,
    // Four-component, 32-bit floating point, expanded to (float, float, float, float).
    Vector4,
    // Two-component, 16-bit floating point expanded to (value, value, value, value). This type is valid for vertex shader version 2.0 or higher.
    HalfVector2,
    // Four-component, 16-bit floating-point expanded to (value, value, value, value). This type is valid for vertex shader version 2.0 or higher.
    HalfVector4,
    // Four-component, packed, unsigned byte, mapped to 0 to 1 range. Input is in Int32 format (ARGB) expanded to (R, G, B, A).
    Color,
    // Normalized, two-component, signed short, expanded to (first short/32767.0, second short/32767.0, 0, 1). This type is valid for vertex shader version 2.0 or higher.
    NormalizedShort2,
    // Normalized, four-component, signed short, expanded to (first short/32767.0, second short/32767.0, third short/32767.0, fourth short/32767.0). This type is valid for vertex shader version 2.0 or higher.
    NormalizedShort4,
    // Two-component, signed short expanded to (value, value, 0, 1).
    Short2,
    // Four-component, signed short expanded to (value, value, value, value).
    Short4,
    // Four-component, unsigned byte.
    Byte4,
};

enum class VertexElementUsages
{
    // Vertex binormal data.
    Binormal,
    // Blending indices data. (BlendIndices with UsageIndex = 0) specifies matrix indices for fixed-function vertex processing using indexed paletted skinning.
    BlendIndices,
    // Blending weight data. (BlendWeight with UsageIndex = 0) specifies the blend weights in fixed-function vertex processing.
    BlendWeight,
    // Vertex data contains diffuse or specular color. (Color with UsageIndex = 0) specifies the diffuse color in the fixed-function vertex shader and in pixel shaders prior to ps_3_0. (Color with UsageIndex = 1) specifies the specular color in the fixed-function vertex shader and in pixel shaders prior to ps_3_0.
    Color,
    // Vertex data contains depth data.
    Depth,
    // Vertex data contains fog data. (Fog with UsageIndex = 0) specifies a fog blend value to use after pixel shading is finished. This flag applies to pixel shaders prior to version ps_3_0.
    Fog,
    // Vertex normal data. (Normal with UsageIndex = 0) specifies vertex normals for fixed-function vertex processing and the N-patch tessellator. (Normal with UsageIndex = 1) specifies vertex normals for fixed-function vertex processing for skinning.
    Normal,
    // Point size data. (PointSize with UsageIndex = 0) specifies the point-size attribute used by the setup engine of the rasterizer to expand a point into a quad for the point-sprite functionality.
    PointSize,
    // Position data. (Position with UsageIndex = 0 ) specifies the nontransformed position in fixed-function vertex processing and the N-patch tessellator. (Position with UsageIndex = 1) specifies the nontransformed position in the fixed-function vertex shader for skinning.
    Position,
    // Vertex data contains sampler data. (Sample with UsageIndex = 0) specifies the displacement value to look up.
    Sample,
    // Vertex tangent data.
    Tangent,
    // Single, positive floating-point value. (TessellateFactor with UsageIndex = 0) specifies a tessellation factor used in the tessellation unit to control the rate of tessellation.
    TessellateFactor,
    // Texture coordinate data. (TextureCoordinate, n) specifies texture coordinates in fixed-function vertex processing and in pixel shaders prior to ps_3_0. These coordinates can be used to pass user-defined data.
    TextureCoordinate,
};

struct VertexElement
{
    // Retrieves or sets the offset (if any) from the beginning of the stream to the beginning of the vertex data.
    int Offset;
    // Modifies the usage data to allow the user to specify multiple usage types.
    int UsageIndex;
    // Gets or sets the format of this vertex element.
    VertexElementFormats VertexElementFormat;
    // Gets or sets a value describing how the vertex element is to be used.
    VertexElementUsages VertexElementUsage;
};

}

}

}

#endif // VERTEXELEMENT_H
