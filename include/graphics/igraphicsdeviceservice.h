#ifndef IGRAPHICSDEVICESERVICE_H
#define IGRAPHICSDEVICESERVICE_H

#include "../iserviceprovider.h"
#include "../property.h"

namespace yna
{

    namespace framework
    {

        namespace graphics
        {

            class IGraphicsDeviceService : public IGameService
            {
            public:
                virtual class GraphicsDevice *GetGraphicsDevice() = 0;
            };

        } // namespace graphics

    } // namespace framework

} // namespace yna

#endif // IGRAPHICSDEVICESERVICE_H
