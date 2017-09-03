#ifndef IGRAPHICSDEVICESERVICE_H
#define IGRAPHICSDEVICESERVICE_H

#include "../property.h"
#include  "../iserviceprovider.h"

namespace yna
{

namespace framework
{

namespace graphics
{

class IGraphicsDeviceService : public IGameService
{
public:
    virtual class GraphicsDevice* GetGraphicsDevice() = 0;

};

}

}

}

#endif // IGRAPHICSDEVICESERVICE_H
