#ifndef CONTENTITEM_H
#define CONTENTITEM_H

#include "../../property.h"

#include <string>
#include <map>

namespace yna
{

namespace framework
{

namespace content
{

namespace pipline
{

class ContentItem
{
public:
    ContentItem();

    // Gets or sets the identity of the content item.
    property<std::string> Identity;
    // Gets or sets the name of the content item.
    property<std::string> Name;
    // Gets the opaque data of the content item.
    std::map<std::string, std::string> OpaqueData;

};

}

}

}

}

#endif // CONTENTITEM_H
