#ifndef GRAPHICSRESOURCE_H
#define GRAPHICSRESOURCE_H

#include "../property.h"

namespace yna
{

namespace framework
{

namespace graphics
{

class GraphicsResource
{
protected:
    class GraphicsDevice* _graphicsDevice;
    GraphicsResource();

public:
    get_property<class GraphicsDevice*> GraphicsDevice;
    property<std::string> Name;
    property<std::string> Tag;
};

}

}

}

#endif // GRAPHICSRESOURCE_H
