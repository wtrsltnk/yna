#ifndef BUFFERUSAGE_H
#define BUFFERUSAGE_H

namespace yna
{

namespace framework
{

namespace graphics
{

enum class BufferUsage
{
    // None
    None,
    // Indicates that the application only writes to the vertex buffer. If specified, the driver chooses the best memory location for efficient writing and rendering. Attempts to read from a write-only vertex buffer fail.
    WriteOnly,
};

}

}

}

#endif // BUFFERUSAGE_H
