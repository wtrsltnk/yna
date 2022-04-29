#ifndef GRAPHICSDEVICEMANAGER_H
#define GRAPHICSDEVICEMANAGER_H

#include "game.h"
#include "graphics/igraphicsdeviceservice.h"

namespace yna
{

    namespace framework
    {

        class GraphicsDeviceManager : public graphics::IGraphicsDeviceService
        {
        public:
            GraphicsDeviceManager(
                Game *game);

            virtual const std::string &Name() const;
            virtual graphics::GraphicsDevice *GetGraphicsDevice();

        private:
            Game *_game;
        };

    } // namespace framework

} // namespace yna

#endif // GRAPHICSDEVICEMANAGER_H
