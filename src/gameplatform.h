#ifndef GAMEPLATFORM_H
#define GAMEPLATFORM_H

#include "graphics/graphicsdevice.h"
#include "property.h"

namespace yna
{

    namespace framework
    {

        class GamePlatform
        {
        protected:
            class Game *_game;

            void SetGameWindow(class GameWindow *gameWindow);
            void SetGraphicsDevice(graphics::GraphicsDevice *graphicsDevice);

        public:
            GamePlatform(class Game *game);

            static GamePlatform *PlatformCreate(class Game *game);

            virtual bool BeforeDraw() = 0;
            virtual void AfterDraw() = 0;
            virtual void RunLoop() = 0;
            virtual void Exit() = 0;
        };

    } // namespace framework

} // namespace yna

#endif // GAMEPLATFORM_H
