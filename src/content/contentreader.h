#ifndef CONTENTREADER_H
#define CONTENTREADER_H

#include "../property.h"

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
    class ContentManager* _contentManager;
public:
    ContentReader();

    // Gets the name of the asset currently being read by this ContentReader.
    property<std::string> AssetName;
    // Gets the ContentManager associated with the ContentReader.
    get_property<class ContentManager*> ContentManager;

    bool ReadBytes(int count, std::vector<unsigned char>& buffer);
};

}

}

}

#endif // CONTENTREADER_H
