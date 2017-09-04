#ifndef CONTENTREADER_H
#define CONTENTREADER_H

#include "../property.h"
#include "../stream.h"

#include <string>
#include <vector>

namespace yna
{

namespace framework
{

namespace content
{

class ContentReader
{
    Stream* _stream;
    class ContentManager* _contentManager;
public:
    ContentReader(Stream* stream, class ContentManager* contentManager);

    // Gets the name of the asset currently being read by this ContentReader.
    property<std::string> AssetName;
    // Exposes access to the underlying stream of the BinaryReader.
    get_property<Stream*> BaseStream;
    // Gets the ContentManager associated with the ContentReader.
    get_property<class ContentManager*> ContentManager;

    bool ReadBytes(int count, std::vector<byte>& buffer);
};

}

}

}

#endif // CONTENTREADER_H
