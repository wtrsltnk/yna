#ifndef STREAM_H
#define STREAM_H

#include <vector>

typedef unsigned char byte;

enum class SeekOrigin
{
    // Specifies the beginning of a stream.
    Begin,
    // Specifies the current position within a stream.
    Current,
    // Specifies the end of a stream.
    End,
};

class Stream
{
public:
    virtual ~Stream() { }

    virtual bool CanRead() = 0;
    virtual bool CanSeek() = 0;
    virtual bool CanWrite() = 0;
    virtual long Length() = 0;
    virtual long Position() = 0;

    // When overridden in a derived class, sets the position within the current stream.
    virtual void Seek(long offset, SeekOrigin origin) = 0;
    // When overridden in a derived class, reads a sequence of bytes from the current stream
    //      and advances the position within the stream by the number of bytes read.
    virtual long Read(std::vector<byte>& buffer, long offset, long count) = 0;
    // When overridden in a derived class, writes a sequence of bytes to the current stream
    //      and advances the current position within this stream by the number of bytes written.
    virtual void Write(const std::vector<byte>& buffer, long offset, long count) = 0;

    // Closes the current stream and releases any resources (such as sockets and file handles)
    //      associated with the current stream.
    virtual void Close() = 0;
};

#endif // STREAM_H
